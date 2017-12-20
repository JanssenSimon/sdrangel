///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QTime>
#include <QDebug>
#include <QMutexLocker>

#include "SWGChannelSettings.h"
#include "SWGCWKeyerSettings.h"

#include <stdio.h>
#include <complex.h>
#include <algorithm>

#include <dsp/upchannelizer.h>
#include "dsp/dspengine.h"
#include "dsp/pidcontroller.h"
#include "device/devicesinkapi.h"
#include "dsp/threadedbasebandsamplesource.h"

#include "nfmmod.h"

MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureNFMMod, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureChannelizer, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureFileSourceName, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureFileSourceSeek, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureAFInput, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgConfigureFileSourceStreamTiming, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgReportFileSourceStreamData, Message)
MESSAGE_CLASS_DEFINITION(NFMMod::MsgReportFileSourceStreamTiming, Message)

const QString NFMMod::m_channelIdURI = "sdrangel.channeltx.modnfm";
const QString NFMMod::m_channelId = "NFMMod";
const int NFMMod::m_levelNbSamples = 480; // every 10ms

NFMMod::NFMMod(DeviceSinkAPI *deviceAPI) :
    ChannelSourceAPI(m_channelIdURI),
	m_deviceAPI(deviceAPI),
	m_absoluteFrequencyOffset(0),
	m_modPhasor(0.0f),
    m_movingAverage(40, 0),
    m_volumeAGC(40, 0),
    m_audioFifo(4800),
	m_settingsMutex(QMutex::Recursive),
	m_fileSize(0),
	m_recordLength(0),
	m_sampleRate(48000),
	m_levelCalcCount(0),
	m_peakLevel(0.0f),
	m_levelSum(0.0f)
{
	setObjectName(m_channelId);

	m_audioBuffer.resize(1<<14);
	m_audioBufferFill = 0;

	m_movingAverage.resize(16, 0);
	m_volumeAGC.resize(4096, 0.003, 0);
	m_magsq = 0.0;

	m_toneNco.setFreq(1000.0, m_settings.m_audioSampleRate);
	m_ctcssNco.setFreq(88.5, m_settings.m_audioSampleRate);
	DSPEngine::instance()->addAudioSource(&m_audioFifo);

    // CW keyer
    m_cwKeyer.setSampleRate(m_settings.m_audioSampleRate);
    m_cwKeyer.setWPM(13);
    m_cwKeyer.setMode(CWKeyerSettings::CWNone);

    m_channelizer = new UpChannelizer(this);
    m_threadedChannelizer = new ThreadedBasebandSampleSource(m_channelizer, this);
    m_deviceAPI->addThreadedSource(m_threadedChannelizer);
    m_deviceAPI->addChannelAPI(this);

    applySettings(m_settings, true);
}

NFMMod::~NFMMod()
{
    DSPEngine::instance()->removeAudioSource(&m_audioFifo);
    m_deviceAPI->removeChannelAPI(this);
    m_deviceAPI->removeThreadedSource(m_threadedChannelizer);
    delete m_threadedChannelizer;
    delete m_channelizer;
}

void NFMMod::pull(Sample& sample)
{
	if (m_settings.m_channelMute)
	{
		sample.m_real = 0.0f;
		sample.m_imag = 0.0f;
		return;
	}

	Complex ci;

	m_settingsMutex.lock();

    if (m_interpolatorDistance > 1.0f) // decimate
    {
    	modulateSample();

        while (!m_interpolator.decimate(&m_interpolatorDistanceRemain, m_modSample, &ci))
        {
        	modulateSample();
        }
    }
    else
    {
        if (m_interpolator.interpolate(&m_interpolatorDistanceRemain, m_modSample, &ci))
        {
        	modulateSample();
        }
    }

    m_interpolatorDistanceRemain += m_interpolatorDistance;

    ci *= m_carrierNco.nextIQ(); // shift to carrier frequency

    m_settingsMutex.unlock();

    Real magsq = ci.real() * ci.real() + ci.imag() * ci.imag();
	magsq /= (1<<30);
	m_movingAverage.feed(magsq);
	m_magsq = m_movingAverage.average();

	sample.m_real = (FixReal) ci.real();
	sample.m_imag = (FixReal) ci.imag();
}

void NFMMod::pullAudio(int nbSamples)
{
    unsigned int nbSamplesAudio = nbSamples * ((Real) m_settings.m_audioSampleRate / (Real) m_settings.m_basebandSampleRate);

    if (nbSamplesAudio > m_audioBuffer.size())
    {
        m_audioBuffer.resize(nbSamplesAudio);
    }

    m_audioFifo.read(reinterpret_cast<quint8*>(&m_audioBuffer[0]), nbSamplesAudio, 10);
    m_audioBufferFill = 0;
}

void NFMMod::modulateSample()
{
	Real t;

    pullAF(t);
    calculateLevel(t);
    m_audioBufferFill++;

    if (m_settings.m_ctcssOn)
    {
        m_modPhasor += (m_settings.m_fmDeviation / (float) m_settings.m_audioSampleRate) * (0.85f * m_bandpass.filter(t) + 0.15f * 378.0f * m_ctcssNco.next()) * (M_PI / 378.0f);
    }
    else
    {
        // 378 = 302 * 1.25; 302 = number of filter taps (established experimentally)
        m_modPhasor += (m_settings.m_fmDeviation / (float) m_settings.m_audioSampleRate) * m_bandpass.filter(t) * (M_PI / 378.0f);
    }

    m_modSample.real(cos(m_modPhasor) * 29204.0f); // -1 dB
    m_modSample.imag(sin(m_modPhasor) * 29204.0f);
}

void NFMMod::pullAF(Real& sample)
{
    switch (m_settings.m_modAFInput)
    {
    case NFMModInputTone:
        sample = m_toneNco.next();
        break;
    case NFMModInputFile:
        // sox f4exb_call.wav --encoding float --endian little f4exb_call.raw
        // ffplay -f f32le -ar 48k -ac 1 f4exb_call.raw
        if (m_ifstream.is_open())
        {
            if (m_ifstream.eof())
            {
            	if (m_settings.m_playLoop)
            	{
                    m_ifstream.clear();
                    m_ifstream.seekg(0, std::ios::beg);
            	}
            }

            if (m_ifstream.eof())
            {
            	sample = 0.0f;
            }
            else
            {
            	m_ifstream.read(reinterpret_cast<char*>(&sample), sizeof(Real));
            	sample *= m_settings.m_volumeFactor;
            }
        }
        else
        {
            sample = 0.0f;
        }
        break;
    case NFMModInputAudio:
        sample = ((m_audioBuffer[m_audioBufferFill].l + m_audioBuffer[m_audioBufferFill].r) / 65536.0f) * m_settings.m_volumeFactor;
        break;
    case NFMModInputCWTone:
        Real fadeFactor;

        if (m_cwKeyer.getSample())
        {
            m_cwKeyer.getCWSmoother().getFadeSample(true, fadeFactor);
            sample = m_toneNco.next() * fadeFactor;
        }
        else
        {
            if (m_cwKeyer.getCWSmoother().getFadeSample(false, fadeFactor))
            {
                sample = m_toneNco.next() * fadeFactor;
            }
            else
            {
                sample = 0.0f;
                m_toneNco.setPhase(0);
            }
        }
        break;
    case NFMModInputNone:
    default:
        sample = 0.0f;
        break;
    }
}

void NFMMod::calculateLevel(Real& sample)
{
    if (m_levelCalcCount < m_levelNbSamples)
    {
        m_peakLevel = std::max(std::fabs(m_peakLevel), sample);
        m_levelSum += sample * sample;
        m_levelCalcCount++;
    }
    else
    {
        qreal rmsLevel = sqrt(m_levelSum / m_levelNbSamples);
        //qDebug("NFMMod::calculateLevel: %f %f", rmsLevel, m_peakLevel);
        emit levelChanged(rmsLevel, m_peakLevel, m_levelNbSamples);
        m_peakLevel = 0.0f;
        m_levelSum = 0.0f;
        m_levelCalcCount = 0;
    }
}

void NFMMod::start()
{
	qDebug() << "NFMMod::start: m_outputSampleRate: " << m_settings.m_outputSampleRate
			<< " m_inputFrequencyOffset: " << m_settings.m_inputFrequencyOffset;

	m_audioFifo.clear();
}

void NFMMod::stop()
{
}

bool NFMMod::handleMessage(const Message& cmd)
{
	if (UpChannelizer::MsgChannelizerNotification::match(cmd))
	{
		UpChannelizer::MsgChannelizerNotification& notif = (UpChannelizer::MsgChannelizerNotification&) cmd;

		NFMModSettings settings = m_settings;

		settings.m_basebandSampleRate = notif.getBasebandSampleRate();
		settings.m_outputSampleRate = notif.getSampleRate();
		settings.m_inputFrequencyOffset = notif.getFrequencyOffset();

        applySettings(settings);

        qDebug() << "NFMMod::handleMessage: UpChannelizer::MsgChannelizerNotification:"
				<< " m_basebandSampleRate: " << settings.m_basebandSampleRate
                << " m_outputSampleRate: " << settings.m_outputSampleRate
				<< " m_inputFrequencyOffset: " << settings.m_inputFrequencyOffset;

		return true;
	}
    else if (MsgConfigureChannelizer::match(cmd))
    {
        MsgConfigureChannelizer& cfg = (MsgConfigureChannelizer&) cmd;

        m_channelizer->configure(m_channelizer->getInputMessageQueue(),
            cfg.getSampleRate(),
            cfg.getCenterFrequency());

        qDebug() << "NFMMod::handleMessage: MsgConfigureChannelizer:"
                << " getSampleRate: " << cfg.getSampleRate()
                << " getCenterFrequency: " << cfg.getCenterFrequency();

        return true;
    }
    else if (MsgConfigureNFMMod::match(cmd))
    {
        MsgConfigureNFMMod& cfg = (MsgConfigureNFMMod&) cmd;

        NFMModSettings settings = cfg.getSettings();

        m_absoluteFrequencyOffset = settings.m_inputFrequencyOffset;
        settings.m_outputSampleRate = m_settings.m_outputSampleRate;
        settings.m_inputFrequencyOffset = m_settings.m_inputFrequencyOffset;

        qDebug() << "NFMMod::handleMessage: MsgConfigureNFMMod:"
                << " m_rfBandwidth: " << settings.m_rfBandwidth
                << " m_afBandwidth: " << settings.m_afBandwidth
                << " m_fmDeviation: " << settings.m_fmDeviation
                << " m_volumeFactor: " << settings.m_volumeFactor
                << " m_toneFrequency: " << settings.m_toneFrequency
                << " m_ctcssIndex: " << settings.m_ctcssIndex
                << " m_ctcssOn: " << settings.m_ctcssOn
                << " m_channelMute: " << settings.m_channelMute
                << " m_playLoop: " << settings.m_playLoop
                << " m_modAFInout " << settings.m_modAFInput
                << " force: " << cfg.getForce();

        applySettings(settings, cfg.getForce());

        return true;
    }
	else if (MsgConfigureFileSourceName::match(cmd))
    {
        MsgConfigureFileSourceName& conf = (MsgConfigureFileSourceName&) cmd;
        m_fileName = conf.getFileName();
        openFileStream();
	    qDebug() << "NFMMod::handleMessage: MsgConfigureFileSourceName:"
	             << " m_fileName: " << m_fileName;
        return true;
    }
    else if (MsgConfigureFileSourceSeek::match(cmd))
    {
        MsgConfigureFileSourceSeek& conf = (MsgConfigureFileSourceSeek&) cmd;
        int seekPercentage = conf.getPercentage();
        seekFileStream(seekPercentage);
        qDebug() << "NFMMod::handleMessage: MsgConfigureFileSourceSeek:"
                 << " seekPercentage: " << seekPercentage;

        return true;
    }
    else if (MsgConfigureAFInput::match(cmd))
    {
        MsgConfigureAFInput& conf = (MsgConfigureAFInput&) cmd;
        m_afInput = conf.getAFInput();
        qDebug() << "NFMMod::handleMessage: MsgConfigureAFInput:"
                 << " m_afInput: " << m_afInput;

        return true;
    }
    else if (MsgConfigureFileSourceStreamTiming::match(cmd))
    {
    	std::size_t samplesCount;

    	if (m_ifstream.eof()) {
    		samplesCount = m_fileSize / sizeof(Real);
    	} else {
    		samplesCount = m_ifstream.tellg() / sizeof(Real);
    	}

    	MsgReportFileSourceStreamTiming *report;
        report = MsgReportFileSourceStreamTiming::create(samplesCount);
        getMessageQueueToGUI()->push(report);

        return true;
    }
	else
	{
		return false;
	}
}

void NFMMod::openFileStream()
{
    if (m_ifstream.is_open()) {
        m_ifstream.close();
    }

    m_ifstream.open(m_fileName.toStdString().c_str(), std::ios::binary | std::ios::ate);
    m_fileSize = m_ifstream.tellg();
    m_ifstream.seekg(0,std::ios_base::beg);

    m_sampleRate = 48000; // fixed rate
    m_recordLength = m_fileSize / (sizeof(Real) * m_sampleRate);

    qDebug() << "NFMMod::openFileStream: " << m_fileName.toStdString().c_str()
            << " fileSize: " << m_fileSize << "bytes"
            << " length: " << m_recordLength << " seconds";

    MsgReportFileSourceStreamData *report;
    report = MsgReportFileSourceStreamData::create(m_sampleRate, m_recordLength);
    getMessageQueueToGUI()->push(report);
}

void NFMMod::seekFileStream(int seekPercentage)
{
    QMutexLocker mutexLocker(&m_settingsMutex);

    if (m_ifstream.is_open())
    {
        int seekPoint = ((m_recordLength * seekPercentage) / 100) * m_sampleRate;
        seekPoint *= sizeof(Real);
        m_ifstream.clear();
        m_ifstream.seekg(seekPoint, std::ios::beg);
    }
}

void NFMMod::applySettings(const NFMModSettings& settings, bool force)
{
    if ((settings.m_inputFrequencyOffset != m_settings.m_inputFrequencyOffset) ||
        (settings.m_outputSampleRate != m_settings.m_outputSampleRate) || force)
    {
        m_settingsMutex.lock();
        m_carrierNco.setFreq(settings.m_inputFrequencyOffset, settings.m_outputSampleRate);
        m_settingsMutex.unlock();
    }

    if((settings.m_outputSampleRate != m_settings.m_outputSampleRate) ||
        (settings.m_rfBandwidth != m_settings.m_rfBandwidth) ||
        (settings.m_audioSampleRate != m_settings.m_audioSampleRate) || force)
    {
        m_settingsMutex.lock();
        m_interpolatorDistanceRemain = 0;
        m_interpolatorConsumed = false;
        m_interpolatorDistance = (Real) settings.m_audioSampleRate / (Real) settings.m_outputSampleRate;
        m_interpolator.create(48, settings.m_audioSampleRate, settings.m_rfBandwidth / 2.2, 3.0);
        m_settingsMutex.unlock();
    }

    if ((settings.m_afBandwidth != m_settings.m_afBandwidth) ||
        (settings.m_audioSampleRate != m_settings.m_audioSampleRate) || force)
    {
        m_settingsMutex.lock();
        m_lowpass.create(301, settings.m_audioSampleRate, 250.0);
        m_bandpass.create(301, settings.m_audioSampleRate, 300.0, settings.m_afBandwidth);
        m_settingsMutex.unlock();
    }

    if ((settings.m_toneFrequency != m_settings.m_toneFrequency) ||
        (settings.m_audioSampleRate != m_settings.m_audioSampleRate) || force)
    {
        m_settingsMutex.lock();
        m_toneNco.setFreq(settings.m_toneFrequency, settings.m_audioSampleRate);
        m_settingsMutex.unlock();
    }

    if ((settings.m_audioSampleRate != m_settings.m_audioSampleRate) || force)
    {
        m_cwKeyer.setSampleRate(settings.m_audioSampleRate);
    }

    if ((settings.m_ctcssIndex != m_settings.m_ctcssIndex) ||
        (settings.m_audioSampleRate != m_settings.m_audioSampleRate) || force)
    {
        m_settingsMutex.lock();
        m_ctcssNco.setFreq(NFMModSettings::getCTCSSFreq(settings.m_ctcssIndex), settings.m_audioSampleRate);
        m_settingsMutex.unlock();
    }

    m_settings = settings;
}

QByteArray NFMMod::serialize() const
{
    return m_settings.serialize();
}

bool NFMMod::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        MsgConfigureNFMMod *msg = MsgConfigureNFMMod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        MsgConfigureNFMMod *msg = MsgConfigureNFMMod::create(m_settings, true);
        m_inputMessageQueue.push(msg);
        return false;
    }
}

int NFMMod::webapiSettingsGet(
                SWGSDRangel::SWGChannelSettings& response,
                QString& errorMessage __attribute__((unused)))
{
    response.setNfmModSettings(new SWGSDRangel::SWGNFMModSettings());
    response.getNfmModSettings()->setAfBandwidth(m_settings.m_afBandwidth);
    response.getNfmModSettings()->setAudioSampleRate(m_settings.m_audioSampleRate);
    response.getNfmModSettings()->setBasebandSampleRate(m_settings.m_basebandSampleRate);
    response.getNfmModSettings()->setChannelMute(m_settings.m_channelMute ? 1 : 0);
    response.getNfmModSettings()->setCtcssIndex(m_settings.m_ctcssIndex);
    response.getNfmModSettings()->setCtcssOn(m_settings.m_ctcssOn ? 1 : 0);
    response.getNfmModSettings()->setFmDeviation(m_settings.m_fmDeviation);
    response.getNfmModSettings()->setInputFrequencyOffset(m_settings.m_inputFrequencyOffset);
    response.getNfmModSettings()->setModAfInput((int) m_settings.m_modAFInput);
    response.getNfmModSettings()->setOutputSampleRate(m_settings.m_outputSampleRate);
    response.getNfmModSettings()->setPlayLoop(m_settings.m_playLoop ? 1 : 0);
    response.getNfmModSettings()->setRfBandwidth(m_settings.m_rfBandwidth);
    response.getNfmModSettings()->setRgbColor(m_settings.m_rgbColor);
    *response.getNfmModSettings()->getTitle() = m_settings.m_title;
    response.getNfmModSettings()->setToneFrequency(m_settings.m_toneFrequency);
    response.getNfmModSettings()->setVolumeFactor(m_settings.m_volumeFactor);
    SWGSDRangel::SWGCWKeyerSettings *apiCwKeyerSettings = response.getNfmModSettings()->getCwKeyer();
    const CWKeyerSettings& cwKeyerSettings = m_cwKeyer.getSettings();
    apiCwKeyerSettings->setLoop(cwKeyerSettings.m_loop ? 1 : 0);
    apiCwKeyerSettings->setMode((int) cwKeyerSettings.m_mode);
    apiCwKeyerSettings->setSampleRate(cwKeyerSettings.m_sampleRate);
    apiCwKeyerSettings->setText(new QString(cwKeyerSettings.m_text));
    apiCwKeyerSettings->setWpm(cwKeyerSettings.m_wpm);
    return 200;
}

int NFMMod::webapiSettingsPutPatch(
                bool force,
                SWGSDRangel::SWGChannelSettings& response,
                QString& errorMessage __attribute__((unused)))
{
    NFMModSettings settings;
    settings.m_afBandwidth = response.getNfmModSettings()->getAfBandwidth();
    settings.m_audioSampleRate = response.getNfmModSettings()->getAudioSampleRate();
    settings.m_basebandSampleRate = response.getNfmModSettings()->getBasebandSampleRate();
    settings.m_channelMute = response.getNfmModSettings()->getChannelMute() != 0;
    settings.m_ctcssIndex = response.getNfmModSettings()->getCtcssIndex();
    settings.m_ctcssOn = response.getNfmModSettings()->getCtcssOn() != 0;
    settings.m_fmDeviation = response.getNfmModSettings()->getFmDeviation();
    settings.m_inputFrequencyOffset = response.getNfmModSettings()->getInputFrequencyOffset();
    settings.m_modAFInput = (NFMModSettings::NFMModInputAF) response.getNfmModSettings()->getModAfInput();
    settings.m_outputSampleRate = response.getNfmModSettings()->getOutputSampleRate();
    settings.m_playLoop = response.getNfmModSettings()->getPlayLoop() != 0;
    settings.m_rfBandwidth = response.getNfmModSettings()->getRfBandwidth();
    settings.m_rgbColor = response.getNfmModSettings()->getRgbColor();
    settings.m_title = *response.getNfmModSettings()->getTitle();
    settings.m_toneFrequency = response.getNfmModSettings()->getToneFrequency();
    settings.m_volumeFactor = response.getNfmModSettings()->getVolumeFactor();
    SWGSDRangel::SWGCWKeyerSettings *apiCwKeyerSettings = response.getNfmModSettings()->getCwKeyer();
    CWKeyerSettings cwKeyerSettings;
    cwKeyerSettings.m_loop = apiCwKeyerSettings->getLoop() != 0;
    cwKeyerSettings.m_mode = (CWKeyerSettings::CWMode) apiCwKeyerSettings->getMode();
    cwKeyerSettings.m_sampleRate = apiCwKeyerSettings->getSampleRate();
    cwKeyerSettings.m_text = *apiCwKeyerSettings->getText();
    cwKeyerSettings.m_wpm = apiCwKeyerSettings->getWpm();
    m_cwKeyer.setLoop(cwKeyerSettings.m_loop);
    m_cwKeyer.setMode(cwKeyerSettings.m_mode);
    m_cwKeyer.setSampleRate(cwKeyerSettings.m_sampleRate);
    m_cwKeyer.setText(cwKeyerSettings.m_text);
    m_cwKeyer.setWPM(cwKeyerSettings.m_wpm);

    MsgConfigureNFMMod *msg = MsgConfigureNFMMod::create(settings, force);
    m_inputMessageQueue.push(msg);

    if (m_guiMessageQueue) // forward to GUI if any
    {
        CWKeyer::MsgConfigureCWKeyer *msgCwKeyer = CWKeyer::MsgConfigureCWKeyer::create(cwKeyerSettings, force);
        m_guiMessageQueue->push(msgCwKeyer);
        MsgConfigureNFMMod *msgToGUI = MsgConfigureNFMMod::create(settings, force);
        m_guiMessageQueue->push(msgToGUI);
    }

    return 200;
}
