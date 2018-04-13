#include "utils.h"

#include <QCryptographicHash>

Utils::Utils()
{

}

QByteArray Utils::MsgForSend(quint8 Frame,quint8 (&Length)[4], quint8 Command,quint32 Version, QByteArray Data, quint16 devicetagcount)
{

    quint8 Header = 0xEE;
    quint8 Synflag = 1;

    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);

    quint8 *hexdata;
    quint8 * blockdata;

    out<<Header<<Frame;
    for(int i = 0; i < 4; i++)
    {
    out<<Length[i];
    }
    out<<Command<<Version;
    if(Command == 0x04)
    {
        out<<Synflag<<devicetagcount;
    }
    hexdata = (quint8 *)Data.data();
    for(int i = 0;i<Data.size();i++)
    {
        out<<hexdata[i];
        //qDebug()<<"hexdata:"<<QString("%1").arg(hexdata[i]&0xff,2,16,QLatin1Char('0'));
    }

    //qDebug()<<"Data.size():"<<Data.size();
    blockdata = (quint8 *)block.data();
    unsigned short check = checkByBit(blockdata,1,10+Data.size(),(quint16)0x00,(quint16)0xa001);
    //qDebug()<<"check:"<<check;
    out<<check;
    //qDebug()<<"AuthData:"<<block;
    return block;

}

QByteArray Utils::AuthData(quint8 (&id)[16], QString pwd, QString coord,quint8 (&Starttime)[6], QString appver, quint8 SynctagFlag)
{
    quint8 pwdSize , coordSize , appverSize;
    QByteArray block , pwdbyte, coordbyte, appverbyte;
    quint8  *HexData;
    quint8 *HexData1;
    quint8 *HexData2;

    QDataStream out(&block,QIODevice::ReadWrite);
    //out.setByteOrder(QDataStream::LittleEndian);
    for(int i = 0;i<16;i++)
    {
        out<<id[i];
    }

    pwdSize = pwd.size();

    coordSize = coord.size();

    appverSize = appver.size();

    pwdbyte.append(pwd);
    HexData = (quint8 *)pwdbyte.data();

    coordbyte.append(coord);
    HexData1 = (quint8 *)coordbyte.data();

    appverbyte.append(appver);
    HexData2 = (quint8 *)appverbyte.data();

    out<<pwdSize;
    for(int i = 0; i<32 ; i++)
    {
        out <<HexData[i];
    }
    out<<coordSize;

    for(int i = 0; i<coordSize ; i++)
    {
        out <<HexData1[i];
    }

    for(int i = 0; i<6 ; i++)
    {
      out<<Starttime[i];
    }
      out<<appverSize;
      for(int i = 0; i<appverSize ; i++)
      {
          out <<HexData2[i];
      }
    out <<SynctagFlag;

    return block;

}


QString Utils::byte2string(quint8 *data,int len )
{
    QString ss;
    for(int i = 0; i <len; i++)
    {
       QString  s = QString::number(data[i],16);

       ss.append(s);
    }
    qDebug()<<"ss:"<<ss;
    return  ss;
}


//text内容序列化
QByteArray Utils::WritePara_NO_2(SettingParaSimp para)
{
    quint8 tabNo = 0x02;
    quint16 tagcount = 1;
    quint32 tagid = 3;
    quint8 tagtype = 10;
    quint8 crrtime[6] ;
    quint16 valuelen = 17;
    quint8 paraheader[5] = {0xfe,0xfe,0xfe,0xfe,0xfe} ;
    Utils::currentTime(crrtime);       //时间戳;
    quint16  qualitystamp = 0x0c00;

    //deviceid + tagcount + tagid + tagtype + valuelen
    //+ value(head,tabno,tablength,rtc,cmd,re,crc)
    //+ timestamp + qualitystamp

    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);
   //out<<SyncFlag<<devicetagcount;
    QByteArray deviceid = QString2Hex(para.deviceID);
    quint8* deviceidp =(quint8 *) deviceid.data();
        for(int i = 0; i < 16; i++)
        {
            out<<deviceidp[i];
        }
        out<<tagcount<<tagid<<tagtype;

        out<<valuelen ;             //子协议总长度  16
        for(int i = 0; i < 5; i++)
        {
            out<<paraheader[i];
        }
        out<<tabNo<<valuelen;
        //  当前时间
        out<<para.updateFlag<<para.deltaTHUp[0]<<para.deltaTHUp[1]<<para.deltaTHDown[0]<<para.deltaTHDown[1];
        out<<para.updateEnvValue<<para.reserve[0]<<para.reserve[1]<<para.crc ;

        for(int i = 0 ;i < 6; i++)
        {
            out<<crrtime[i];
        }
        out<<qualitystamp;


    return block;
}

QByteArray Utils::WritePara_NO_3(RTCPara para)
{
    quint8 tabNo = 0x03;
    quint16 tagcount = 1;
    quint32 tagid = 3;
    quint8 tagtype = 10;
    quint8 crrtime[6] ;
    quint16 valuelen = 16;
    quint8 paraheader[5] = {0xfe,0xfe,0xfe,0xfe,0xfe} ;
    quint8 platformCmd = PLATFORMCMD;
    Utils::currentTime(crrtime);       //时间戳;
    quint16  qualitystamp = 0x0c00;

    //deviceid + tagcount + tagid + tagtype + valuelen
    //+ value(head,tabno,tablength,rtc,cmd,re,crc)
    //+ timestamp + qualitystamp

    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);
   //out<<SyncFlag<<devicetagcount;
    QByteArray deviceid = QString2Hex(para.deviceID);
    quint8* deviceidp =(quint8 *) deviceid.data();
        for(int i = 0; i < 16; i++)
        {
            out<<deviceidp[i];
        }
        out<<tagcount<<tagid<<tagtype;

        out<<valuelen ;             //子协议总长度  16
        for(int i = 0; i < 5; i++)
        {
            out<<paraheader[i];
        }
        out<<tabNo<<valuelen;
        //  当前时间
        quint32 RTC = QDateTime::currentDateTime().toTime_t();
        out<<RTC<<platformCmd<<para.reserve[0]<<para.reserve[1]<<para.crc ;

        for(int i = 0 ;i < 6; i++)
        {
            out<<crrtime[i];
        }
        out<<qualitystamp;


    return block;
}


void Utils::int2bcd(quint8 (&bcd)[4],int len)
{
    int temp = 0;
    for(int i = 3; i >= 0; i--)
    {
        temp = len % 100;
        bcd[i] = (quint8) (((temp / 10) <<4) + ((temp % 10) &0x0f));

        len /= 100;
    }

}

//合并byte
quint32  Utils::uchar2uint(quint8 *data,int len )
{

quint32 temp = 0;
    for(int i = 0;i<len;i++)
    {
        temp |=data[i]<<((len-i-1)*8);
    }



    return temp;
}
quint16  Utils::uchar2ushort(quint8 *data,int len )
{

quint16 temp = 0;
    for(int i = 0;i<len;i++)
    {
        temp |=data[i]<<((len-i-1)*8);
    }



    return temp;
}

void Utils::ParseText(QString text)
{
    QString pairid = text.mid(0,1);
    QString initx = text.mid(1,2);
    QString inity = text.mid(3,2);
    QString initz = text.mid(5,2);
    QString currx = text.mid(7,2);
    QString curry = text.mid(9,2);
    QString currz = text.mid(11,2);
    QString carinfo = text.mid(13,1);
    QString rtc = text.mid(14,4);


}

//tag 解析
void Utils::ParseTag( quint8  *data, int len, DevicePc1 *devpc,quint16 devicetagcount)
{

}


QString Utils::md5(quint8 *id, QString Password)
{
    QString ID = Hex2Str(id);
    QString idandpwd = ID + Password;

    QByteArray b = QCryptographicHash::hash(idandpwd.toLatin1(),QCryptographicHash::Md5 );
    QString md5=b.toHex();

    return md5;
}


QString Utils::Hex2Str(quint8 *id)
{
    QString ss;
    for(int i = 0;i<4;i++)
    {
        ss.append(QString("%1").arg(id[i]&0xff,2,16,QLatin1Char('0')));
    }
    ss.append("-");
    for(int i = 4;i<6;i++)
    {
        ss.append(QString("%1").arg(id[i]&0xff,2,16,QLatin1Char('0')));
    }
    ss.append("-");
    for(int i = 6;i<8;i++)
    {
        ss.append(QString("%1").arg(id[i]&0xff,2,16,QLatin1Char('0')));
    }
    ss.append("-");
    for(int i = 8;i<10;i++)
    {
        ss.append(QString("%1").arg(id[i]&0xff,2,16,QLatin1Char('0')));
    }
    ss.append("-");
    for(int i = 10;i<16;i++)
    {
        ss.append(QString("%1").arg(id[i]&0xff,2,16,QLatin1Char('0')));
    }
    QString SS = ss.toUpper();
    //qDebug()<<"ss:"<<SS;
    return SS;

}


char ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
    return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
    return ch-'a'+10;
    else return (-1);
}


QByteArray QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
        break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
        break;
        else
        hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

void bytesToInt8(quint8 *hexdata,QByteArray data)
{

    hexdata = (quint8 *)data.data();
}

//CRC 校验，详见代码如下：
qint16 checkByBit(quint8 * buffer, int offset, int count,quint16 initValue,	quint16 polynomial)
{
    for	(int	i	=	offset;	i	<	count + offset;	i++)
    {
        initValue	=	(unsigned short)(initValue	^	buffer[i]);

        for	(int	j	=	0;	j	<	8;	j++)
        {
            int	msbInfo	=	initValue	&	0x0001;
            initValue	=	(unsigned short)(initValue	>>	1);
            if	(msbInfo	!=	0)
            {
                initValue	=	(unsigned short)(initValue	^	polynomial);
            }
        }
    }
    return	initValue;
}


QByteArray qint8ToQbytearray(quint8 * data , int size)
{

    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);
    for(int i = 0; i<size; i++)
    {
        out<<data[i];
    }
    return block;

}

void Utils::currentTime(quint8 *time)
{

    QString oldtime = "2010-01-01 00:00:00";
    QDateTime datetime =  QDateTime::fromString(oldtime, "yyyy-MM-dd hh:mm:ss");
    QDateTime curtime = QDateTime::currentDateTime();
    quint64 curtimems = curtime.msecsTo(datetime);
    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);
    out <<curtimems;
    time = (quint8 *)block.data();

}


