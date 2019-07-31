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

#ifndef _SWG_OBJECT_H_
#define _SWG_OBJECT_H_

#include <QJsonValue>

namespace SWGSDRangel {

class SWGObject {
  public:
    virtual QJsonObject* asJsonObject() {
      return new QJsonObject();
    }
    virtual ~SWGObject() {}
    virtual SWGObject* fromJson(QString &jsonString) {
        Q_UNUSED(jsonString);
        return new SWGObject();
    }
    virtual void fromJsonObject(QJsonObject &json) {
        Q_UNUSED(json);
    }
    virtual QString asJson() {
        return QString("");
    }
    virtual bool isSet() {
        return false;
    }
};

}

#endif /* _SWG_OBJECT_H_ */
