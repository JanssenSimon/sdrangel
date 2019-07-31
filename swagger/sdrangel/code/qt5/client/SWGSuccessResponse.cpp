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


#include "SWGSuccessResponse.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGSuccessResponse::SWGSuccessResponse(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSuccessResponse::SWGSuccessResponse() {
    message = nullptr;
    m_message_isSet = false;
}

SWGSuccessResponse::~SWGSuccessResponse() {
    this->cleanup();
}

void
SWGSuccessResponse::init() {
    message = new QString("");
    m_message_isSet = false;
}

void
SWGSuccessResponse::cleanup() {
    if(message != nullptr) { 
        delete message;
    }
}

SWGSuccessResponse*
SWGSuccessResponse::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSuccessResponse::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&message, pJson["message"], "QString", "QString");
    
}

QString
SWGSuccessResponse::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSuccessResponse::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(message != nullptr && *message != QString("")){
        toJsonValue(QString("message"), message, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGSuccessResponse::getMessage() {
    return message;
}
void
SWGSuccessResponse::setMessage(QString* message) {
    this->message = message;
    this->m_message_isSet = true;
}


bool
SWGSuccessResponse::isSet(){
    bool isObjectUpdated = false;
    do{
        if(message != nullptr && *message != QString("")){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

