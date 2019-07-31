/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.11.6
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGInstanceSummaryResponse.h
 *
 * Summarized information about this SDRangel instance
 */

#ifndef SWGInstanceSummaryResponse_H_
#define SWGInstanceSummaryResponse_H_

#include <QJsonObject>


#include "SWGDeviceSetList.h"
#include "SWGLoggingInfo.h"
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGInstanceSummaryResponse: public SWGObject {
public:
    SWGInstanceSummaryResponse();
    SWGInstanceSummaryResponse(QString* json);
    virtual ~SWGInstanceSummaryResponse();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGInstanceSummaryResponse* fromJson(QString &jsonString) override;

    QString* getVersion();
    void setVersion(QString* version);

    QString* getQtVersion();
    void setQtVersion(QString* qt_version);

    qint32 getDspRxBits();
    void setDspRxBits(qint32 dsp_rx_bits);

    qint32 getDspTxBits();
    void setDspTxBits(qint32 dsp_tx_bits);

    qint32 getPid();
    void setPid(qint32 pid);

    QString* getAppname();
    void setAppname(QString* appname);

    QString* getArchitecture();
    void setArchitecture(QString* architecture);

    QString* getOs();
    void setOs(QString* os);

    SWGLoggingInfo* getLogging();
    void setLogging(SWGLoggingInfo* logging);

    SWGDeviceSetList* getDevicesetlist();
    void setDevicesetlist(SWGDeviceSetList* devicesetlist);


    virtual bool isSet() override;

private:
    QString* version;
    bool m_version_isSet;

    QString* qt_version;
    bool m_qt_version_isSet;

    qint32 dsp_rx_bits;
    bool m_dsp_rx_bits_isSet;

    qint32 dsp_tx_bits;
    bool m_dsp_tx_bits_isSet;

    qint32 pid;
    bool m_pid_isSet;

    QString* appname;
    bool m_appname_isSet;

    QString* architecture;
    bool m_architecture_isSet;

    QString* os;
    bool m_os_isSet;

    SWGLoggingInfo* logging;
    bool m_logging_isSet;

    SWGDeviceSetList* devicesetlist;
    bool m_devicesetlist_isSet;

};

}

#endif /* SWGInstanceSummaryResponse_H_ */
