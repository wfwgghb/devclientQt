#ifndef UTILS_H
#define UTILS_H
#include<QtCore>

#include "constant.h"

using namespace std;

union Tempr{
unsigned char TempHL[2];
unsigned int TempResult;
};

//全局变量
//QList <DevicePc2> tag_list;

qint16 checkByBit(quint8 *buffer, int offset, int count, quint16 initValue  ,	quint16 polynomial);

QByteArray qint8ToQbytearray(quint8 * data , int size);
void bytesToInt8(quint8 *hexdata, QByteArray data);
char ConvertHexChar(char ch);
QByteArray QString2Hex(QString str);

class Utils
{


public:
    Utils();
    QString  md5(quint8 *id  , QString Password);
    QString Hex2Str(quint8 *id);

    QByteArray MsgForSend(quint8 Frame, quint8 (&Length)[4], quint8 Command, quint32 Version, QByteArray Data, quint16 devicetagcount = 0);
    QByteArray AuthData(quint8 (&id)[16], QString pwd, QString coord,quint8 (&Starttime)[6], QString appver, quint8 SynctagFlag);
    quint8 *table2LengthCalc(SettingParaSimp para);


    static QByteArray WritePara_NO_2(SettingParaSimp para);
    QByteArray WritePara_NO_3(RTCPara para);
    static QString  byte2string(quint8 *data, int len);
    static quint32  uchar2uint(quint8 *data,int len = 4);
    static quint16  uchar2ushort(quint8 *data,int len = 2);

    void ParseTag(quint8 *data, int len, DevicePc1 *devpc, quint16 devicetagcount);
    //void ParseText(QByteArray text1, DevicePc1 *devicepc);
    //Tag * InitTags(quint32 id , quint8 type , quint8 *value, quint8 (&timestamp)[6], quint16 qualitystamp);
    static void int2bcd(quint8 (&bcd)[4],int len);
    static void currentTime(quint8 *time);
    static void ParseText(QString text);

private :
signals:
    void SendMsgSignal(QString msg);

};

#endif // UTILS_H
