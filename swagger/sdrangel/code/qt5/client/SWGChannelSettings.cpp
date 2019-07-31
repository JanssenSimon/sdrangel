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


#include "SWGChannelSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGChannelSettings::SWGChannelSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGChannelSettings::SWGChannelSettings() {
    channel_type = nullptr;
    m_channel_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    originator_device_set_index = 0;
    m_originator_device_set_index_isSet = false;
    originator_channel_index = 0;
    m_originator_channel_index_isSet = false;
    am_demod_settings = nullptr;
    m_am_demod_settings_isSet = false;
    am_mod_settings = nullptr;
    m_am_mod_settings_isSet = false;
    atv_mod_settings = nullptr;
    m_atv_mod_settings_isSet = false;
    bfm_demod_settings = nullptr;
    m_bfm_demod_settings_isSet = false;
    dsd_demod_settings = nullptr;
    m_dsd_demod_settings_isSet = false;
    file_source_settings = nullptr;
    m_file_source_settings_isSet = false;
    free_dv_demod_settings = nullptr;
    m_free_dv_demod_settings_isSet = false;
    free_dv_mod_settings = nullptr;
    m_free_dv_mod_settings_isSet = false;
    freq_tracker_settings = nullptr;
    m_freq_tracker_settings_isSet = false;
    nfm_demod_settings = nullptr;
    m_nfm_demod_settings_isSet = false;
    nfm_mod_settings = nullptr;
    m_nfm_mod_settings_isSet = false;
    local_sink_settings = nullptr;
    m_local_sink_settings_isSet = false;
    local_source_settings = nullptr;
    m_local_source_settings_isSet = false;
    remote_sink_settings = nullptr;
    m_remote_sink_settings_isSet = false;
    remote_source_settings = nullptr;
    m_remote_source_settings_isSet = false;
    ssb_mod_settings = nullptr;
    m_ssb_mod_settings_isSet = false;
    ssb_demod_settings = nullptr;
    m_ssb_demod_settings_isSet = false;
    udp_source_settings = nullptr;
    m_udp_source_settings_isSet = false;
    udp_sink_settings = nullptr;
    m_udp_sink_settings_isSet = false;
    wfm_demod_settings = nullptr;
    m_wfm_demod_settings_isSet = false;
    wfm_mod_settings = nullptr;
    m_wfm_mod_settings_isSet = false;
}

SWGChannelSettings::~SWGChannelSettings() {
    this->cleanup();
}

void
SWGChannelSettings::init() {
    channel_type = new QString("");
    m_channel_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    originator_device_set_index = 0;
    m_originator_device_set_index_isSet = false;
    originator_channel_index = 0;
    m_originator_channel_index_isSet = false;
    am_demod_settings = new SWGAMDemodSettings();
    m_am_demod_settings_isSet = false;
    am_mod_settings = new SWGAMModSettings();
    m_am_mod_settings_isSet = false;
    atv_mod_settings = new SWGATVModSettings();
    m_atv_mod_settings_isSet = false;
    bfm_demod_settings = new SWGBFMDemodSettings();
    m_bfm_demod_settings_isSet = false;
    dsd_demod_settings = new SWGDSDDemodSettings();
    m_dsd_demod_settings_isSet = false;
    file_source_settings = new SWGFileSourceSettings();
    m_file_source_settings_isSet = false;
    free_dv_demod_settings = new SWGFreeDVDemodSettings();
    m_free_dv_demod_settings_isSet = false;
    free_dv_mod_settings = new SWGFreeDVModSettings();
    m_free_dv_mod_settings_isSet = false;
    freq_tracker_settings = new SWGFreqTrackerSettings();
    m_freq_tracker_settings_isSet = false;
    nfm_demod_settings = new SWGNFMDemodSettings();
    m_nfm_demod_settings_isSet = false;
    nfm_mod_settings = new SWGNFMModSettings();
    m_nfm_mod_settings_isSet = false;
    local_sink_settings = new SWGLocalSinkSettings();
    m_local_sink_settings_isSet = false;
    local_source_settings = new SWGLocalSourceSettings();
    m_local_source_settings_isSet = false;
    remote_sink_settings = new SWGRemoteSinkSettings();
    m_remote_sink_settings_isSet = false;
    remote_source_settings = new SWGRemoteSourceSettings();
    m_remote_source_settings_isSet = false;
    ssb_mod_settings = new SWGSSBModSettings();
    m_ssb_mod_settings_isSet = false;
    ssb_demod_settings = new SWGSSBDemodSettings();
    m_ssb_demod_settings_isSet = false;
    udp_source_settings = new SWGUDPSourceSettings();
    m_udp_source_settings_isSet = false;
    udp_sink_settings = new SWGUDPSinkSettings();
    m_udp_sink_settings_isSet = false;
    wfm_demod_settings = new SWGWFMDemodSettings();
    m_wfm_demod_settings_isSet = false;
    wfm_mod_settings = new SWGWFMModSettings();
    m_wfm_mod_settings_isSet = false;
}

void
SWGChannelSettings::cleanup() {
    if(channel_type != nullptr) { 
        delete channel_type;
    }



    if(am_demod_settings != nullptr) { 
        delete am_demod_settings;
    }
    if(am_mod_settings != nullptr) { 
        delete am_mod_settings;
    }
    if(atv_mod_settings != nullptr) { 
        delete atv_mod_settings;
    }
    if(bfm_demod_settings != nullptr) { 
        delete bfm_demod_settings;
    }
    if(dsd_demod_settings != nullptr) { 
        delete dsd_demod_settings;
    }
    if(file_source_settings != nullptr) { 
        delete file_source_settings;
    }
    if(free_dv_demod_settings != nullptr) { 
        delete free_dv_demod_settings;
    }
    if(free_dv_mod_settings != nullptr) { 
        delete free_dv_mod_settings;
    }
    if(freq_tracker_settings != nullptr) { 
        delete freq_tracker_settings;
    }
    if(nfm_demod_settings != nullptr) { 
        delete nfm_demod_settings;
    }
    if(nfm_mod_settings != nullptr) { 
        delete nfm_mod_settings;
    }
    if(local_sink_settings != nullptr) { 
        delete local_sink_settings;
    }
    if(local_source_settings != nullptr) { 
        delete local_source_settings;
    }
    if(remote_sink_settings != nullptr) { 
        delete remote_sink_settings;
    }
    if(remote_source_settings != nullptr) { 
        delete remote_source_settings;
    }
    if(ssb_mod_settings != nullptr) { 
        delete ssb_mod_settings;
    }
    if(ssb_demod_settings != nullptr) { 
        delete ssb_demod_settings;
    }
    if(udp_source_settings != nullptr) { 
        delete udp_source_settings;
    }
    if(udp_sink_settings != nullptr) { 
        delete udp_sink_settings;
    }
    if(wfm_demod_settings != nullptr) { 
        delete wfm_demod_settings;
    }
    if(wfm_mod_settings != nullptr) { 
        delete wfm_mod_settings;
    }
}

SWGChannelSettings*
SWGChannelSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGChannelSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&channel_type, pJson["channelType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&direction, pJson["direction"], "qint32", "");
    
    ::SWGSDRangel::setValue(&originator_device_set_index, pJson["originatorDeviceSetIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&originator_channel_index, pJson["originatorChannelIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&am_demod_settings, pJson["AMDemodSettings"], "SWGAMDemodSettings", "SWGAMDemodSettings");
    
    ::SWGSDRangel::setValue(&am_mod_settings, pJson["AMModSettings"], "SWGAMModSettings", "SWGAMModSettings");
    
    ::SWGSDRangel::setValue(&atv_mod_settings, pJson["ATVModSettings"], "SWGATVModSettings", "SWGATVModSettings");
    
    ::SWGSDRangel::setValue(&bfm_demod_settings, pJson["BFMDemodSettings"], "SWGBFMDemodSettings", "SWGBFMDemodSettings");
    
    ::SWGSDRangel::setValue(&dsd_demod_settings, pJson["DSDDemodSettings"], "SWGDSDDemodSettings", "SWGDSDDemodSettings");
    
    ::SWGSDRangel::setValue(&file_source_settings, pJson["FileSourceSettings"], "SWGFileSourceSettings", "SWGFileSourceSettings");
    
    ::SWGSDRangel::setValue(&free_dv_demod_settings, pJson["FreeDVDemodSettings"], "SWGFreeDVDemodSettings", "SWGFreeDVDemodSettings");
    
    ::SWGSDRangel::setValue(&free_dv_mod_settings, pJson["FreeDVModSettings"], "SWGFreeDVModSettings", "SWGFreeDVModSettings");
    
    ::SWGSDRangel::setValue(&freq_tracker_settings, pJson["FreqTrackerSettings"], "SWGFreqTrackerSettings", "SWGFreqTrackerSettings");
    
    ::SWGSDRangel::setValue(&nfm_demod_settings, pJson["NFMDemodSettings"], "SWGNFMDemodSettings", "SWGNFMDemodSettings");
    
    ::SWGSDRangel::setValue(&nfm_mod_settings, pJson["NFMModSettings"], "SWGNFMModSettings", "SWGNFMModSettings");
    
    ::SWGSDRangel::setValue(&local_sink_settings, pJson["LocalSinkSettings"], "SWGLocalSinkSettings", "SWGLocalSinkSettings");
    
    ::SWGSDRangel::setValue(&local_source_settings, pJson["LocalSourceSettings"], "SWGLocalSourceSettings", "SWGLocalSourceSettings");
    
    ::SWGSDRangel::setValue(&remote_sink_settings, pJson["RemoteSinkSettings"], "SWGRemoteSinkSettings", "SWGRemoteSinkSettings");
    
    ::SWGSDRangel::setValue(&remote_source_settings, pJson["RemoteSourceSettings"], "SWGRemoteSourceSettings", "SWGRemoteSourceSettings");
    
    ::SWGSDRangel::setValue(&ssb_mod_settings, pJson["SSBModSettings"], "SWGSSBModSettings", "SWGSSBModSettings");
    
    ::SWGSDRangel::setValue(&ssb_demod_settings, pJson["SSBDemodSettings"], "SWGSSBDemodSettings", "SWGSSBDemodSettings");
    
    ::SWGSDRangel::setValue(&udp_source_settings, pJson["UDPSourceSettings"], "SWGUDPSourceSettings", "SWGUDPSourceSettings");
    
    ::SWGSDRangel::setValue(&udp_sink_settings, pJson["UDPSinkSettings"], "SWGUDPSinkSettings", "SWGUDPSinkSettings");
    
    ::SWGSDRangel::setValue(&wfm_demod_settings, pJson["WFMDemodSettings"], "SWGWFMDemodSettings", "SWGWFMDemodSettings");
    
    ::SWGSDRangel::setValue(&wfm_mod_settings, pJson["WFMModSettings"], "SWGWFMModSettings", "SWGWFMModSettings");
    
}

QString
SWGChannelSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGChannelSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(channel_type != nullptr && *channel_type != QString("")){
        toJsonValue(QString("channelType"), channel_type, obj, QString("QString"));
    }
    if(m_direction_isSet){
        obj->insert("direction", QJsonValue(direction));
    }
    if(m_originator_device_set_index_isSet){
        obj->insert("originatorDeviceSetIndex", QJsonValue(originator_device_set_index));
    }
    if(m_originator_channel_index_isSet){
        obj->insert("originatorChannelIndex", QJsonValue(originator_channel_index));
    }
    if((am_demod_settings != nullptr) && (am_demod_settings->isSet())){
        toJsonValue(QString("AMDemodSettings"), am_demod_settings, obj, QString("SWGAMDemodSettings"));
    }
    if((am_mod_settings != nullptr) && (am_mod_settings->isSet())){
        toJsonValue(QString("AMModSettings"), am_mod_settings, obj, QString("SWGAMModSettings"));
    }
    if((atv_mod_settings != nullptr) && (atv_mod_settings->isSet())){
        toJsonValue(QString("ATVModSettings"), atv_mod_settings, obj, QString("SWGATVModSettings"));
    }
    if((bfm_demod_settings != nullptr) && (bfm_demod_settings->isSet())){
        toJsonValue(QString("BFMDemodSettings"), bfm_demod_settings, obj, QString("SWGBFMDemodSettings"));
    }
    if((dsd_demod_settings != nullptr) && (dsd_demod_settings->isSet())){
        toJsonValue(QString("DSDDemodSettings"), dsd_demod_settings, obj, QString("SWGDSDDemodSettings"));
    }
    if((file_source_settings != nullptr) && (file_source_settings->isSet())){
        toJsonValue(QString("FileSourceSettings"), file_source_settings, obj, QString("SWGFileSourceSettings"));
    }
    if((free_dv_demod_settings != nullptr) && (free_dv_demod_settings->isSet())){
        toJsonValue(QString("FreeDVDemodSettings"), free_dv_demod_settings, obj, QString("SWGFreeDVDemodSettings"));
    }
    if((free_dv_mod_settings != nullptr) && (free_dv_mod_settings->isSet())){
        toJsonValue(QString("FreeDVModSettings"), free_dv_mod_settings, obj, QString("SWGFreeDVModSettings"));
    }
    if((freq_tracker_settings != nullptr) && (freq_tracker_settings->isSet())){
        toJsonValue(QString("FreqTrackerSettings"), freq_tracker_settings, obj, QString("SWGFreqTrackerSettings"));
    }
    if((nfm_demod_settings != nullptr) && (nfm_demod_settings->isSet())){
        toJsonValue(QString("NFMDemodSettings"), nfm_demod_settings, obj, QString("SWGNFMDemodSettings"));
    }
    if((nfm_mod_settings != nullptr) && (nfm_mod_settings->isSet())){
        toJsonValue(QString("NFMModSettings"), nfm_mod_settings, obj, QString("SWGNFMModSettings"));
    }
    if((local_sink_settings != nullptr) && (local_sink_settings->isSet())){
        toJsonValue(QString("LocalSinkSettings"), local_sink_settings, obj, QString("SWGLocalSinkSettings"));
    }
    if((local_source_settings != nullptr) && (local_source_settings->isSet())){
        toJsonValue(QString("LocalSourceSettings"), local_source_settings, obj, QString("SWGLocalSourceSettings"));
    }
    if((remote_sink_settings != nullptr) && (remote_sink_settings->isSet())){
        toJsonValue(QString("RemoteSinkSettings"), remote_sink_settings, obj, QString("SWGRemoteSinkSettings"));
    }
    if((remote_source_settings != nullptr) && (remote_source_settings->isSet())){
        toJsonValue(QString("RemoteSourceSettings"), remote_source_settings, obj, QString("SWGRemoteSourceSettings"));
    }
    if((ssb_mod_settings != nullptr) && (ssb_mod_settings->isSet())){
        toJsonValue(QString("SSBModSettings"), ssb_mod_settings, obj, QString("SWGSSBModSettings"));
    }
    if((ssb_demod_settings != nullptr) && (ssb_demod_settings->isSet())){
        toJsonValue(QString("SSBDemodSettings"), ssb_demod_settings, obj, QString("SWGSSBDemodSettings"));
    }
    if((udp_source_settings != nullptr) && (udp_source_settings->isSet())){
        toJsonValue(QString("UDPSourceSettings"), udp_source_settings, obj, QString("SWGUDPSourceSettings"));
    }
    if((udp_sink_settings != nullptr) && (udp_sink_settings->isSet())){
        toJsonValue(QString("UDPSinkSettings"), udp_sink_settings, obj, QString("SWGUDPSinkSettings"));
    }
    if((wfm_demod_settings != nullptr) && (wfm_demod_settings->isSet())){
        toJsonValue(QString("WFMDemodSettings"), wfm_demod_settings, obj, QString("SWGWFMDemodSettings"));
    }
    if((wfm_mod_settings != nullptr) && (wfm_mod_settings->isSet())){
        toJsonValue(QString("WFMModSettings"), wfm_mod_settings, obj, QString("SWGWFMModSettings"));
    }

    return obj;
}

QString*
SWGChannelSettings::getChannelType() {
    return channel_type;
}
void
SWGChannelSettings::setChannelType(QString* channel_type) {
    this->channel_type = channel_type;
    this->m_channel_type_isSet = true;
}

qint32
SWGChannelSettings::getDirection() {
    return direction;
}
void
SWGChannelSettings::setDirection(qint32 direction) {
    this->direction = direction;
    this->m_direction_isSet = true;
}

qint32
SWGChannelSettings::getOriginatorDeviceSetIndex() {
    return originator_device_set_index;
}
void
SWGChannelSettings::setOriginatorDeviceSetIndex(qint32 originator_device_set_index) {
    this->originator_device_set_index = originator_device_set_index;
    this->m_originator_device_set_index_isSet = true;
}

qint32
SWGChannelSettings::getOriginatorChannelIndex() {
    return originator_channel_index;
}
void
SWGChannelSettings::setOriginatorChannelIndex(qint32 originator_channel_index) {
    this->originator_channel_index = originator_channel_index;
    this->m_originator_channel_index_isSet = true;
}

SWGAMDemodSettings*
SWGChannelSettings::getAmDemodSettings() {
    return am_demod_settings;
}
void
SWGChannelSettings::setAmDemodSettings(SWGAMDemodSettings* am_demod_settings) {
    this->am_demod_settings = am_demod_settings;
    this->m_am_demod_settings_isSet = true;
}

SWGAMModSettings*
SWGChannelSettings::getAmModSettings() {
    return am_mod_settings;
}
void
SWGChannelSettings::setAmModSettings(SWGAMModSettings* am_mod_settings) {
    this->am_mod_settings = am_mod_settings;
    this->m_am_mod_settings_isSet = true;
}

SWGATVModSettings*
SWGChannelSettings::getAtvModSettings() {
    return atv_mod_settings;
}
void
SWGChannelSettings::setAtvModSettings(SWGATVModSettings* atv_mod_settings) {
    this->atv_mod_settings = atv_mod_settings;
    this->m_atv_mod_settings_isSet = true;
}

SWGBFMDemodSettings*
SWGChannelSettings::getBfmDemodSettings() {
    return bfm_demod_settings;
}
void
SWGChannelSettings::setBfmDemodSettings(SWGBFMDemodSettings* bfm_demod_settings) {
    this->bfm_demod_settings = bfm_demod_settings;
    this->m_bfm_demod_settings_isSet = true;
}

SWGDSDDemodSettings*
SWGChannelSettings::getDsdDemodSettings() {
    return dsd_demod_settings;
}
void
SWGChannelSettings::setDsdDemodSettings(SWGDSDDemodSettings* dsd_demod_settings) {
    this->dsd_demod_settings = dsd_demod_settings;
    this->m_dsd_demod_settings_isSet = true;
}

SWGFileSourceSettings*
SWGChannelSettings::getFileSourceSettings() {
    return file_source_settings;
}
void
SWGChannelSettings::setFileSourceSettings(SWGFileSourceSettings* file_source_settings) {
    this->file_source_settings = file_source_settings;
    this->m_file_source_settings_isSet = true;
}

SWGFreeDVDemodSettings*
SWGChannelSettings::getFreeDvDemodSettings() {
    return free_dv_demod_settings;
}
void
SWGChannelSettings::setFreeDvDemodSettings(SWGFreeDVDemodSettings* free_dv_demod_settings) {
    this->free_dv_demod_settings = free_dv_demod_settings;
    this->m_free_dv_demod_settings_isSet = true;
}

SWGFreeDVModSettings*
SWGChannelSettings::getFreeDvModSettings() {
    return free_dv_mod_settings;
}
void
SWGChannelSettings::setFreeDvModSettings(SWGFreeDVModSettings* free_dv_mod_settings) {
    this->free_dv_mod_settings = free_dv_mod_settings;
    this->m_free_dv_mod_settings_isSet = true;
}

SWGFreqTrackerSettings*
SWGChannelSettings::getFreqTrackerSettings() {
    return freq_tracker_settings;
}
void
SWGChannelSettings::setFreqTrackerSettings(SWGFreqTrackerSettings* freq_tracker_settings) {
    this->freq_tracker_settings = freq_tracker_settings;
    this->m_freq_tracker_settings_isSet = true;
}

SWGNFMDemodSettings*
SWGChannelSettings::getNfmDemodSettings() {
    return nfm_demod_settings;
}
void
SWGChannelSettings::setNfmDemodSettings(SWGNFMDemodSettings* nfm_demod_settings) {
    this->nfm_demod_settings = nfm_demod_settings;
    this->m_nfm_demod_settings_isSet = true;
}

SWGNFMModSettings*
SWGChannelSettings::getNfmModSettings() {
    return nfm_mod_settings;
}
void
SWGChannelSettings::setNfmModSettings(SWGNFMModSettings* nfm_mod_settings) {
    this->nfm_mod_settings = nfm_mod_settings;
    this->m_nfm_mod_settings_isSet = true;
}

SWGLocalSinkSettings*
SWGChannelSettings::getLocalSinkSettings() {
    return local_sink_settings;
}
void
SWGChannelSettings::setLocalSinkSettings(SWGLocalSinkSettings* local_sink_settings) {
    this->local_sink_settings = local_sink_settings;
    this->m_local_sink_settings_isSet = true;
}

SWGLocalSourceSettings*
SWGChannelSettings::getLocalSourceSettings() {
    return local_source_settings;
}
void
SWGChannelSettings::setLocalSourceSettings(SWGLocalSourceSettings* local_source_settings) {
    this->local_source_settings = local_source_settings;
    this->m_local_source_settings_isSet = true;
}

SWGRemoteSinkSettings*
SWGChannelSettings::getRemoteSinkSettings() {
    return remote_sink_settings;
}
void
SWGChannelSettings::setRemoteSinkSettings(SWGRemoteSinkSettings* remote_sink_settings) {
    this->remote_sink_settings = remote_sink_settings;
    this->m_remote_sink_settings_isSet = true;
}

SWGRemoteSourceSettings*
SWGChannelSettings::getRemoteSourceSettings() {
    return remote_source_settings;
}
void
SWGChannelSettings::setRemoteSourceSettings(SWGRemoteSourceSettings* remote_source_settings) {
    this->remote_source_settings = remote_source_settings;
    this->m_remote_source_settings_isSet = true;
}

SWGSSBModSettings*
SWGChannelSettings::getSsbModSettings() {
    return ssb_mod_settings;
}
void
SWGChannelSettings::setSsbModSettings(SWGSSBModSettings* ssb_mod_settings) {
    this->ssb_mod_settings = ssb_mod_settings;
    this->m_ssb_mod_settings_isSet = true;
}

SWGSSBDemodSettings*
SWGChannelSettings::getSsbDemodSettings() {
    return ssb_demod_settings;
}
void
SWGChannelSettings::setSsbDemodSettings(SWGSSBDemodSettings* ssb_demod_settings) {
    this->ssb_demod_settings = ssb_demod_settings;
    this->m_ssb_demod_settings_isSet = true;
}

SWGUDPSourceSettings*
SWGChannelSettings::getUdpSourceSettings() {
    return udp_source_settings;
}
void
SWGChannelSettings::setUdpSourceSettings(SWGUDPSourceSettings* udp_source_settings) {
    this->udp_source_settings = udp_source_settings;
    this->m_udp_source_settings_isSet = true;
}

SWGUDPSinkSettings*
SWGChannelSettings::getUdpSinkSettings() {
    return udp_sink_settings;
}
void
SWGChannelSettings::setUdpSinkSettings(SWGUDPSinkSettings* udp_sink_settings) {
    this->udp_sink_settings = udp_sink_settings;
    this->m_udp_sink_settings_isSet = true;
}

SWGWFMDemodSettings*
SWGChannelSettings::getWfmDemodSettings() {
    return wfm_demod_settings;
}
void
SWGChannelSettings::setWfmDemodSettings(SWGWFMDemodSettings* wfm_demod_settings) {
    this->wfm_demod_settings = wfm_demod_settings;
    this->m_wfm_demod_settings_isSet = true;
}

SWGWFMModSettings*
SWGChannelSettings::getWfmModSettings() {
    return wfm_mod_settings;
}
void
SWGChannelSettings::setWfmModSettings(SWGWFMModSettings* wfm_mod_settings) {
    this->wfm_mod_settings = wfm_mod_settings;
    this->m_wfm_mod_settings_isSet = true;
}


bool
SWGChannelSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(channel_type != nullptr && *channel_type != QString("")){ isObjectUpdated = true; break;}
        if(m_direction_isSet){ isObjectUpdated = true; break;}
        if(m_originator_device_set_index_isSet){ isObjectUpdated = true; break;}
        if(m_originator_channel_index_isSet){ isObjectUpdated = true; break;}
        if(am_demod_settings != nullptr && am_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(am_mod_settings != nullptr && am_mod_settings->isSet()){ isObjectUpdated = true; break;}
        if(atv_mod_settings != nullptr && atv_mod_settings->isSet()){ isObjectUpdated = true; break;}
        if(bfm_demod_settings != nullptr && bfm_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(dsd_demod_settings != nullptr && dsd_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(file_source_settings != nullptr && file_source_settings->isSet()){ isObjectUpdated = true; break;}
        if(free_dv_demod_settings != nullptr && free_dv_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(free_dv_mod_settings != nullptr && free_dv_mod_settings->isSet()){ isObjectUpdated = true; break;}
        if(freq_tracker_settings != nullptr && freq_tracker_settings->isSet()){ isObjectUpdated = true; break;}
        if(nfm_demod_settings != nullptr && nfm_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(nfm_mod_settings != nullptr && nfm_mod_settings->isSet()){ isObjectUpdated = true; break;}
        if(local_sink_settings != nullptr && local_sink_settings->isSet()){ isObjectUpdated = true; break;}
        if(local_source_settings != nullptr && local_source_settings->isSet()){ isObjectUpdated = true; break;}
        if(remote_sink_settings != nullptr && remote_sink_settings->isSet()){ isObjectUpdated = true; break;}
        if(remote_source_settings != nullptr && remote_source_settings->isSet()){ isObjectUpdated = true; break;}
        if(ssb_mod_settings != nullptr && ssb_mod_settings->isSet()){ isObjectUpdated = true; break;}
        if(ssb_demod_settings != nullptr && ssb_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(udp_source_settings != nullptr && udp_source_settings->isSet()){ isObjectUpdated = true; break;}
        if(udp_sink_settings != nullptr && udp_sink_settings->isSet()){ isObjectUpdated = true; break;}
        if(wfm_demod_settings != nullptr && wfm_demod_settings->isSet()){ isObjectUpdated = true; break;}
        if(wfm_mod_settings != nullptr && wfm_mod_settings->isSet()){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

