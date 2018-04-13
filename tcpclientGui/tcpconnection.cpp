#include "tcpconnection.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "HttpClient.h"


TcpConnection::TcpConnection(QObject *parent) : QObject(parent)
{
        timer = NULL;
        ConnectionFlag = false;
        DevicePc1 askData;
        QVariant DataVar;
        DataVar.setValue(askData);
        qRegisterMetaType<QVariant>("QVariant"); //写在构造函数里

        m_thread=new QThread;
        this->moveToThread(m_thread);
        connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
        m_thread->start();
}

TcpConnection::~TcpConnection()
{
        socket->close();
}

void TcpConnection::Initial()
{
    //tcp连接
    //socket = new QTcpSocket();
    count = 0;
    //timer = new QTimer();
    //singleTimer = new QTimer();
    utils = new Utils;
    sqlwork = new SqlWork;
    //创建HttpClient子线程
    httpclient = new HttpClient();

    connect(this,SIGNAL(HttpClientSignal(QByteArray)),httpclient,SLOT(MsgFromTcpSlot(QByteArray)));
    if(!sqlwork->ConnSqlDatabase(TcpSqlName))
    {
        //错误处理
    }
    db_connection = SqlWork::getConnectionByName(TcpSqlName);


}

void TcpConnection::SendMsg(QByteArray data)
{
    ErrorFlag ef = writenError;
    int tempflag = ef;
    qDebug()<<"sendmsg:"<<data;
    if(socket->isWritable())
    {
        socket->write(data,data.size());
    }

    if(!socket->waitForBytesWritten())
    {
        emit errorSignal(tempflag);
    }

}

void TcpConnection::sendDeviceRequest()
{

}

//定时发送心跳包
void TcpConnection::sendHeartBeat()
{
}

void TcpConnection::stopSocketSlot()
{

}
//#define BATTERYCHARGE 0x04
//#define DEVICEREQ     0x06
//#define HEARTBEAT     0x08
//#define COMMDATA      0x05
//接收数据、解析数据
void TcpConnection::RcvMsg()
{
    //QString buffer;
    tableHeader tableheader;
    quint16 check ;
    DevicePc1 *devpc;
    QString rcvmsg;
    QString strmsg = "wrong data!";

    qint64 readbyte = socket->bytesAvailable();
    if(readbyte <= 0)
    {
        qDebug()<<strmsg;
        return;
    }

    QByteArray ba = socket->readAll();

//    qDebug()<<"rcvmsg is:"<<ba;
    m_buffer.append(ba);
    int totallen = m_buffer.size();
    qDebug()<<"total len start :"<<totallen<<endl;
    while(totallen)
    {
        QDataStream in(&m_buffer,QIODevice::ReadWrite);
        if(totallen < 13)
        {
            qDebug()<<"data is too short"<<endl;
            break;
        }
        in>>tableheader.header>>tableheader.frame;
        qDebug()<<"tableheader.header:"<<tableheader.header;
        qDebug()<<"tableheader.frame:"<<tableheader.frame;
        for(int i = 0; i < 4; i++)
        {
            in>>tableheader.length[i];
            //qDebug()<<"tableheader.length"<<tableheader.length[i];
        }
        int tablelength = bcd2int(tableheader.length);
        qDebug()<<"tablelength:"<<tablelength;
        in>>tableheader.command>>tableheader.version;


        int datasize = tablelength-sizeof(quint16)-5;
//        QByteArray tmpdata;
//        in>>tmpdata;
//        QByteArray msg = tmpdata.left(datasize);     //data

        quint8 *Data = new  quint8[datasize];
        if(datasize > 0)
        {
            for(int i = 0;i<datasize;i++)
            {
                in>>Data[i];
            }
        }
        in>>check;
        qDebug()<<"Command is:"<<tableheader.command;

        if(tableheader.command == 0x03)
        {
           dataHander(Data);

        }else if(tableheader.command == 0x04)
        {
            if(tablelength == 8)
            {
                //参数修改响应            
                dataHander3(Data);
            }
            else
            {
                //tag解析
                quint8 syncflag = Data[0];
                quint16 devicetagcount = Utils::uchar2ushort(Data+1);

                qDebug()<<"flag:"<<syncflag;
                qDebug()<<"devicetagcount:"<<devicetagcount;

                QByteArray recvdata = m_buffer.left(tablelength+6);
                emit SendDataSignal(recvdata);

                devpc = new DevicePc1[devicetagcount];
                utils->ParseTag(Data+3,datasize-3,devpc,devicetagcount);
                ResponseDevice(devpc,devicetagcount);
                delete [] devpc;


            }
        }else if(tableheader.command == 0x05)       // 设备单个请求
        {
            //tag解析
            quint8 result = Data[0];

            QByteArray recvdata = m_buffer.left(tablelength+6);

            qDebug()<<"result is :"<<result<<endl;
            qDebug()<<"recv data :"<<recvdata.toHex();
            emit SendDataSignal(recvdata);

            devpc = new DevicePc1;
            utils->ParseTag(Data+1,datasize-1,devpc,1);


            ResponseDevice(devpc,1);
            delete  devpc;

        }


     //   qDebug()<<"rcvmsg:"<<rcvmsg<<endl;
    //qDebug()<<Header<<Frame<<Length<<LongHeartCommand<<Ver<<check;
        delete [] Data;
       ba = m_buffer.right(totallen - 6 - tablelength) ;
       totallen = ba.size();

       qDebug()<<"rest of total len is :"<<totallen<<endl;
       qDebug()<<"rest of total msg is :"<<ba<<endl;
       m_buffer = ba;

    }
}

//设备响应处理
void TcpConnection::ResponseDevice(DevicePc1 *devpc,quint16 devicetagcount)
{
    QJsonObject json_obj;
    QByteArray block;
    RTCPara rtcpara;
    tableHeader tabhead;
    quint16 count = 0;
    tabhead.frame = 0x00;
    tabhead.command = 0x04;
    tabhead.version = 0x10000000;

    for(int i = 0; i < devicetagcount; i++)
    {
        if(devpc->tabNo == DEVICEREQ)
        {
            if(devpc->requestType == 0x03)      //PC端校时 , 带版本信息
            {

                rtcpara.deviceID = (devpc+i)->deviceID ;
                rtcpara.platformCmd = PLATFORMCMD;
                rtcpara.reserve[0] = (devpc+i)->reserve[0];
                rtcpara.reserve[1] = (devpc+i)->reserve[1];
                rtcpara.crc = (devpc+i)->crc;
                QByteArray t_block = utils->WritePara_NO_3(rtcpara);
                block.append(t_block);
                //放入列表
                rtc_list.append(rtcpara);
                count++;

            }
            qDebug()<<"current time is :"<<endl;
        }else if(devpc->tabNo == HEARTBEAT)         //心跳包判断 ，
        {
            //无需响应

        }else if(devpc->tabNo == COMMDATA)      //配对处理（数据异常检测）
        {
            //编码json
            if(devpc->carInfo == 1)
            {
                json_obj.insert(MSGSTR,"leaving");
                json_obj.insert(MAGSTR,devpc->deviceID);
                json_obj.insert(TSSTR,int(devpc->RTC));
            }else if(devpc->carInfo == 2)
            {
                json_obj.insert(MSGSTR,"parking");
                json_obj.insert(MAGSTR,devpc->deviceID);
                json_obj.insert(TSSTR,int(devpc->RTC));
            }

            //无需响应
            //devpc->pairId;
        }else if(devpc->tabNo == BATTERYCHARGE)
        {
//            json_obj.insert(MSGSTR,"alarm");
//            json_obj.insert(MAGSTR,devpc->deviceID);
            //json_obj.insert(TS,devpc->RTC);
        }
        QByteArray byte_array = QJsonDocument(json_obj).toJson(QJsonDocument::Compact);
        emit HttpClientSignal(byte_array);

    }

    int len = 10 + block.size();
    Utils::int2bcd(tabhead.length,len);

    QByteArray msg = utils->MsgForSend(tabhead.frame,tabhead.length,tabhead.command,tabhead.version,block,count);
    if(!rtc_list.isEmpty())
    {
        //rtc计时器激活
        QTimer::singleShot(2000,this,SLOT(RTCtimerSlot()));
        SendMsg(msg);
        qDebug()<<"rtc msg :"<<msg.toHex();
    }


}

//rtc timer开始
void TcpConnection::RTCtimerSlot()
{
    //发送RTC消息
    QByteArray block;
    tableHeader tabhead;

    tabhead.frame = 0x00;
    tabhead.command = 0x04;
    tabhead.version = 0x10000000;
    quint16 rtclist_size = rtc_list.size();
    for(int i = 0; i < rtclist_size; i++)
    {

        QByteArray t_block = utils->WritePara_NO_3(rtc_list.at(i));
        block.append(t_block);

    }

    int len = 10 + block.size();
    Utils::int2bcd(tabhead.length,len);

    QByteArray msg = utils->MsgForSend(tabhead.frame,tabhead.length,tabhead.command,tabhead.version,block,rtclist_size);

    SendMsg(msg);

    qDebug()<<"rtc msg after 2 s:"<<msg.toHex();
    rtc_list.clear();


}

//授权回表处理
void TcpConnection::dataHander(quint8 * dat)
{
        QString rcvmsg;
        quint8 data = dat[0];
        if(data == 0x00)
        {
            rcvmsg.append("\r\nauthenerity success!\r\n");            

        }else if(data == 0x01)
        {
            rcvmsg.append("\r\nclient do not exist!\r\n");

        }
        else if(data == 0x02)
        {
            rcvmsg.append("\r\nId illegal!\r\n");

        } else if(data == 0x03)
        {
            rcvmsg.append("\r\npassword error!\r\n");

        } else if(data == 0x04)
        {
            rcvmsg.append("\r\nchong fu shou quan !\r\n");

        }
        else if(data == 0x05)
        {
            rcvmsg.append("\r\nprogram is already auth!\r\n");

        }else if(data == 0x06)
        {
            rcvmsg.append("\r\nunkown roles!\r\n");

        }else if(data == 0x07)
        {
            rcvmsg.append("\r\nthis device is out of date!\r\n");

        }else if(data == 0xFE)
        {
            rcvmsg.append("\r\ndatabase error!\r\n");

        }else if(data == 0xFF)
        {
            rcvmsg.append("\r\ncommunication error!\r\n");

        }
        emit RcvmsgSignal(rcvmsg);

}

//传输参数回表处理
void TcpConnection::dataHander3(quint8 * dat)
{

        QString rcvmsg;
        quint8 data = dat[0];

        if(data == 0x00)
        {

            rcvmsg.append("\r\npara setting success!\r\n");


        }else if(data == 0x01)
        {

            rcvmsg.append("\r\ntag count error!\r\n");

        }
        else if(data == 0x02)
        {
            rcvmsg.append("\r\ntag id reused!\r\n");

        } else if(data == 0x03)
        {
            rcvmsg.append("\r\nclient not auth!\r\n");

        }
        emit ParaSettingSignal(data);
         emit RcvmsgSignal(rcvmsg);
//    ui->textEdit_2->setText(rcvmsg);
//    cursor1.movePosition(QTextCursor::End);
//    ui->textEdit_2->setTextCursor(cursor1);
}

int TcpConnection::bcd2int(quint8 *bcd , int len)
{
    int dec = 0;
    int temp = 1000000;
    for(int i = 0; i < len; i++) {
        dec += ((int) ((bcd[i] & 0xf0) >> 4)*10 + (int) (bcd[i] & 0x0f))*temp;
        temp /= 100;
    }
    return dec;
}
