#ifndef CONSTANT_H
#define CONSTANT_H
#include <QtCore>
#include <QMetaType>
#include <QVariant>

#define BATTERYCHARGE 0x04
#define DEVICEREQ     0x06
#define HEARTBEAT     0x08
#define COMMDATA      0x05
#define PLATFORMCMD   0x00
#define PRODUCTKEY "T4su6nQsWaqZYYP5dl3o6XqYW48= "

#define MSGSTR     "msg"
#define MAGSTR     "mag"
#define TSSTR      "berth"


extern quint8 Id[16] ;
extern quint32 Ver;
extern QString AppVer;
extern QString Coord;
extern quint8 AuthCode[95];
extern quint8 QueryData[39];
extern quint8 TranData[34];
extern QString password;
extern const QString siteIp;
extern const int sitePort;
extern const QString MainSqlName;
extern const QString TcpSqlName;
extern const QString SqlthreadName;
extern const QString LogthreadName;
extern const QString Partner;
extern const QString HttpSecret;

struct tableHeader
{
    quint8 header;
    quint8 frame;
    quint8 length[4];
    quint8 command;
    quint32 version;
};

struct Tag
{
    quint8 id[4];
    quint8  Type;
    quint16 valuelen;
    quint8 *value;
    quint8 timestamp[6];
    quint16 qualitystamp;
};

struct DeviceTag
{
    quint8 deviceID[16];
    quint8 tagcount[2];
    Tag    *tag;
};

//pc->device
struct SettingParaSimp
{

    quint8 header[5];
    quint8 tabNo;               //0x02
    quint8 tabLengthH;
    quint8 tabLengthL;
    quint8 updateFlag;
    quint8 deltaTHUp[2];
    quint8 deltaTHDown[2];
    quint8 updateEnvValue;
    quint8 reserve[2];
    quint8 crc;
    QString deviceID;

};

//RTC校时     PC->DEVICE
struct RTCPara
{ 
    quint8 platformCmd;
    quint8 reserve[2];
    quint8 crc;
    QString deviceID;
};

//Battery charge device->pc
struct BatteryCharge
{
    quint8 header[5];
    quint8 tabNo;               //0x04
    quint8 tabLengthH;
    quint8 tabLengthL;
    quint8 batteryAlarm;
    quint8 reserve[2];
    quint8 crc;
};

//设备请求   device->pc
struct DeviceRequest
{
    quint8 header[5];
    quint8 tabNo;               //0x06
    quint8 tabLengthH;
    quint8 tabLengthL;
    quint8 appVer[4];
    quint8 requestType;
    quint8 reserve[2];
    quint8 crc;
};

//心跳包   Device->pc
struct HeartBeat
{
    quint8 header[5];
    quint8 tabNo;                   //0x08
    quint8 tabLengthH;
    quint8 tabLengthL;
    quint8 batteryAlarm;
    quint8 deltaTHUp[2];
    quint8 deltaTHDown[2];
    quint8 crc;
};

//数据传输 dev->pc
struct CommData
{
    quint8 header[5];
    quint8 tabNo;                   //0x05
    quint8 tabLengthH;
    quint8 tabLengthL;
    quint8 initX[2];
    quint8 initY[2];
    quint8 initZ[2];
    quint8 currX[2];
    quint8 currY[2];
    quint8 currZ[2];
    quint8 carInfo;
    quint8 RTC[4];
    quint8 reserve[2];
    quint8 crc;
};

//总结构体
struct DevicePc
{
    quint8 tabNo;
    quint8 errordataflag;
    CommData commdata;
    HeartBeat heartbeat;
    DeviceRequest devreq;
    BatteryCharge batterycharge;

};

struct DevicePc1
{

    quint8 tabNo;
    quint8 pairId;
    quint8 requestType;
    quint8 batteryAlarm;
    quint8 errordataflag;
    quint8 carInfo;
    quint8  reserve[2];
    quint8  crc;
    quint16 initX;
    quint16 initY;
    quint16 initZ;
    quint16 currX;
    quint16 currY;
    quint16 currZ;
    quint16 deltaTHUp;
    quint16 deltaTHDown;
    quint32 RTC;
    QString appVer;
    QString deviceID;

};

struct devinfo
{

};

struct DevicePc2
{
    quint8 tabNo;
    quint8 errordataflag;
    quint8 appVer[4];
    quint8 requestType;
    quint8 batteryAlarm;
    quint8 deltaTHUp[2];
    quint8 deltaTHDown[2];
};

enum ErrorFlag{

    connectError,
    writenError,
    readError,
    dataError
};

enum httpError{
    succ,
    nosucc
};

//     inline QDataStream& operator<<(QDataStream& out, const Tag& tags)
//     {
//         out<<tags.id<<userInfor.state<<userInfor.ip<<userInfor.port<<
//              userInfor.nickName<<userInfor.headPhoto<<userInfor.discription;
//         return out;
//     }

//     inline QDataStream& operator>>(QDataStream& in,UserInfor& userInfor)
//     {
//         in>>userInfor.id>>userInfor.state>>userInfor.ip>>userInfor.port>>userInfor.nickName
//             >>userInfor.headPhoto>>userInfor.discription;
//        return in;
//     }
Q_DECLARE_METATYPE(CommData)
Q_DECLARE_METATYPE(DeviceRequest)
Q_DECLARE_METATYPE(HeartBeat)
Q_DECLARE_METATYPE(BatteryCharge)
Q_DECLARE_METATYPE(SettingParaSimp)
Q_DECLARE_METATYPE(DevicePc1)


class constant
{
public:
  constant();

};

#endif // CONSTANT_H

//struct SettingPara
//{
//    quint8 header[5];
//    quint8 tabNo;
//    quint8 tabLengthH;
//    quint8 tabLengthL;
//    quint8 devid[16];
//    quint8 jumpFlag;
//    quint8 updateFlag;
//    quint8 updateSize;
//    quint8 deltaTHUp[2];
//    quint8 deltaTHDown[2];
//    quint8 envX[2];
//    quint8 envY[2];
//    quint8 envZ[2];
//    quint8 range;
//    quint8 reserve[6];
//    quint8 crc;
//};
