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


#include "SWGArgInfo.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGArgInfo::SWGArgInfo(QString* json) {
    init();
    this->fromJson(*json);
}

SWGArgInfo::SWGArgInfo() {
    key = nullptr;
    m_key_isSet = false;
    value_type = nullptr;
    m_value_type_isSet = false;
    value_string = nullptr;
    m_value_string_isSet = false;
    name = nullptr;
    m_name_isSet = false;
    description = nullptr;
    m_description_isSet = false;
    units = nullptr;
    m_units_isSet = false;
    range = nullptr;
    m_range_isSet = false;
    value_options = nullptr;
    m_value_options_isSet = false;
    option_names = nullptr;
    m_option_names_isSet = false;
}

SWGArgInfo::~SWGArgInfo() {
    this->cleanup();
}

void
SWGArgInfo::init() {
    key = new QString("");
    m_key_isSet = false;
    value_type = new QString("");
    m_value_type_isSet = false;
    value_string = new QString("");
    m_value_string_isSet = false;
    name = new QString("");
    m_name_isSet = false;
    description = new QString("");
    m_description_isSet = false;
    units = new QString("");
    m_units_isSet = false;
    range = new SWGRangeFloat();
    m_range_isSet = false;
    value_options = new QList<QString*>();
    m_value_options_isSet = false;
    option_names = new QList<QString*>();
    m_option_names_isSet = false;
}

void
SWGArgInfo::cleanup() {
    if(key != nullptr) { 
        delete key;
    }
    if(value_type != nullptr) { 
        delete value_type;
    }
    if(value_string != nullptr) { 
        delete value_string;
    }
    if(name != nullptr) { 
        delete name;
    }
    if(description != nullptr) { 
        delete description;
    }
    if(units != nullptr) { 
        delete units;
    }
    if(range != nullptr) { 
        delete range;
    }
    if(value_options != nullptr) { 
        auto arr = value_options;
        for(auto o: *arr) { 
            delete o;
        }
        delete value_options;
    }
    if(option_names != nullptr) { 
        auto arr = option_names;
        for(auto o: *arr) { 
            delete o;
        }
        delete option_names;
    }
}

SWGArgInfo*
SWGArgInfo::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGArgInfo::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&key, pJson["key"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&value_type, pJson["valueType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&value_string, pJson["valueString"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&name, pJson["name"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&description, pJson["description"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&units, pJson["units"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&range, pJson["range"], "SWGRangeFloat", "SWGRangeFloat");
    
    
    ::SWGSDRangel::setValue(&value_options, pJson["valueOptions"], "QList", "QString");
    
    ::SWGSDRangel::setValue(&option_names, pJson["optionNames"], "QList", "QString");
}

QString
SWGArgInfo::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGArgInfo::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(key != nullptr && *key != QString("")){
        toJsonValue(QString("key"), key, obj, QString("QString"));
    }
    if(value_type != nullptr && *value_type != QString("")){
        toJsonValue(QString("valueType"), value_type, obj, QString("QString"));
    }
    if(value_string != nullptr && *value_string != QString("")){
        toJsonValue(QString("valueString"), value_string, obj, QString("QString"));
    }
    if(name != nullptr && *name != QString("")){
        toJsonValue(QString("name"), name, obj, QString("QString"));
    }
    if(description != nullptr && *description != QString("")){
        toJsonValue(QString("description"), description, obj, QString("QString"));
    }
    if(units != nullptr && *units != QString("")){
        toJsonValue(QString("units"), units, obj, QString("QString"));
    }
    if((range != nullptr) && (range->isSet())){
        toJsonValue(QString("range"), range, obj, QString("SWGRangeFloat"));
    }
    if(value_options->size() > 0){
        toJsonArray((QList<void*>*)value_options, obj, "valueOptions", "QString");
    }
    if(option_names->size() > 0){
        toJsonArray((QList<void*>*)option_names, obj, "optionNames", "QString");
    }

    return obj;
}

QString*
SWGArgInfo::getKey() {
    return key;
}
void
SWGArgInfo::setKey(QString* key) {
    this->key = key;
    this->m_key_isSet = true;
}

QString*
SWGArgInfo::getValueType() {
    return value_type;
}
void
SWGArgInfo::setValueType(QString* value_type) {
    this->value_type = value_type;
    this->m_value_type_isSet = true;
}

QString*
SWGArgInfo::getValueString() {
    return value_string;
}
void
SWGArgInfo::setValueString(QString* value_string) {
    this->value_string = value_string;
    this->m_value_string_isSet = true;
}

QString*
SWGArgInfo::getName() {
    return name;
}
void
SWGArgInfo::setName(QString* name) {
    this->name = name;
    this->m_name_isSet = true;
}

QString*
SWGArgInfo::getDescription() {
    return description;
}
void
SWGArgInfo::setDescription(QString* description) {
    this->description = description;
    this->m_description_isSet = true;
}

QString*
SWGArgInfo::getUnits() {
    return units;
}
void
SWGArgInfo::setUnits(QString* units) {
    this->units = units;
    this->m_units_isSet = true;
}

SWGRangeFloat*
SWGArgInfo::getRange() {
    return range;
}
void
SWGArgInfo::setRange(SWGRangeFloat* range) {
    this->range = range;
    this->m_range_isSet = true;
}

QList<QString*>*
SWGArgInfo::getValueOptions() {
    return value_options;
}
void
SWGArgInfo::setValueOptions(QList<QString*>* value_options) {
    this->value_options = value_options;
    this->m_value_options_isSet = true;
}

QList<QString*>*
SWGArgInfo::getOptionNames() {
    return option_names;
}
void
SWGArgInfo::setOptionNames(QList<QString*>* option_names) {
    this->option_names = option_names;
    this->m_option_names_isSet = true;
}


bool
SWGArgInfo::isSet(){
    bool isObjectUpdated = false;
    do{
        if(key != nullptr && *key != QString("")){ isObjectUpdated = true; break;}
        if(value_type != nullptr && *value_type != QString("")){ isObjectUpdated = true; break;}
        if(value_string != nullptr && *value_string != QString("")){ isObjectUpdated = true; break;}
        if(name != nullptr && *name != QString("")){ isObjectUpdated = true; break;}
        if(description != nullptr && *description != QString("")){ isObjectUpdated = true; break;}
        if(units != nullptr && *units != QString("")){ isObjectUpdated = true; break;}
        if(range != nullptr && range->isSet()){ isObjectUpdated = true; break;}
        if(value_options->size() > 0){ isObjectUpdated = true; break;}
        if(option_names->size() > 0){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

