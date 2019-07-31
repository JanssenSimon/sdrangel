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


#include "SWGFileSourceSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFileSourceSettings::SWGFileSourceSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFileSourceSettings::SWGFileSourceSettings() {
    file_name = nullptr;
    m_file_name_isSet = false;
    loop = 0;
    m_loop_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    filter_chain_hash = 0;
    m_filter_chain_hash_isSet = false;
    gain_db = 0;
    m_gain_db_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

SWGFileSourceSettings::~SWGFileSourceSettings() {
    this->cleanup();
}

void
SWGFileSourceSettings::init() {
    file_name = new QString("");
    m_file_name_isSet = false;
    loop = 0;
    m_loop_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    filter_chain_hash = 0;
    m_filter_chain_hash_isSet = false;
    gain_db = 0;
    m_gain_db_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

void
SWGFileSourceSettings::cleanup() {
    if(file_name != nullptr) { 
        delete file_name;
    }





    if(title != nullptr) { 
        delete title;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGFileSourceSettings*
SWGFileSourceSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFileSourceSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&file_name, pJson["fileName"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&loop, pJson["loop"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_interp, pJson["log2Interp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&filter_chain_hash, pJson["filterChainHash"], "qint32", "");
    
    ::SWGSDRangel::setValue(&gain_db, pJson["gainDB"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGFileSourceSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFileSourceSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(file_name != nullptr && *file_name != QString("")){
        toJsonValue(QString("fileName"), file_name, obj, QString("QString"));
    }
    if(m_loop_isSet){
        obj->insert("loop", QJsonValue(loop));
    }
    if(m_log2_interp_isSet){
        obj->insert("log2Interp", QJsonValue(log2_interp));
    }
    if(m_filter_chain_hash_isSet){
        obj->insert("filterChainHash", QJsonValue(filter_chain_hash));
    }
    if(m_gain_db_isSet){
        obj->insert("gainDB", QJsonValue(gain_db));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }
    if(m_reverse_api_channel_index_isSet){
        obj->insert("reverseAPIChannelIndex", QJsonValue(reverse_api_channel_index));
    }

    return obj;
}

QString*
SWGFileSourceSettings::getFileName() {
    return file_name;
}
void
SWGFileSourceSettings::setFileName(QString* file_name) {
    this->file_name = file_name;
    this->m_file_name_isSet = true;
}

qint32
SWGFileSourceSettings::getLoop() {
    return loop;
}
void
SWGFileSourceSettings::setLoop(qint32 loop) {
    this->loop = loop;
    this->m_loop_isSet = true;
}

qint32
SWGFileSourceSettings::getLog2Interp() {
    return log2_interp;
}
void
SWGFileSourceSettings::setLog2Interp(qint32 log2_interp) {
    this->log2_interp = log2_interp;
    this->m_log2_interp_isSet = true;
}

qint32
SWGFileSourceSettings::getFilterChainHash() {
    return filter_chain_hash;
}
void
SWGFileSourceSettings::setFilterChainHash(qint32 filter_chain_hash) {
    this->filter_chain_hash = filter_chain_hash;
    this->m_filter_chain_hash_isSet = true;
}

qint32
SWGFileSourceSettings::getGainDb() {
    return gain_db;
}
void
SWGFileSourceSettings::setGainDb(qint32 gain_db) {
    this->gain_db = gain_db;
    this->m_gain_db_isSet = true;
}

qint32
SWGFileSourceSettings::getRgbColor() {
    return rgb_color;
}
void
SWGFileSourceSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGFileSourceSettings::getTitle() {
    return title;
}
void
SWGFileSourceSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGFileSourceSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGFileSourceSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGFileSourceSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGFileSourceSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGFileSourceSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGFileSourceSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGFileSourceSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGFileSourceSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGFileSourceSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGFileSourceSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGFileSourceSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(file_name != nullptr && *file_name != QString("")){ isObjectUpdated = true; break;}
        if(m_loop_isSet){ isObjectUpdated = true; break;}
        if(m_log2_interp_isSet){ isObjectUpdated = true; break;}
        if(m_filter_chain_hash_isSet){ isObjectUpdated = true; break;}
        if(m_gain_db_isSet){ isObjectUpdated = true; break;}
        if(m_rgb_color_isSet){ isObjectUpdated = true; break;}
        if(title != nullptr && *title != QString("")){ isObjectUpdated = true; break;}
        if(m_use_reverse_api_isSet){ isObjectUpdated = true; break;}
        if(reverse_api_address != nullptr && *reverse_api_address != QString("")){ isObjectUpdated = true; break;}
        if(m_reverse_api_port_isSet){ isObjectUpdated = true; break;}
        if(m_reverse_api_device_index_isSet){ isObjectUpdated = true; break;}
        if(m_reverse_api_channel_index_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

