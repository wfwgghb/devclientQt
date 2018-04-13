#include "devhttpclient.h"


DevHttpClient::DevHttpClient(QObject *parent) : QObject(parent)
{

    m_thread=new QThread;
    this->moveToThread(m_thread);
    connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
    m_thread->start();
}

void DevHttpClient::Initial()
{
    utils = new Utils;
    m_accessManager = new QNetworkAccessManager();
    n_timer = new QTimer;
    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(finishedSlot(QNetworkReply*)));

    connect(n_timer, SIGNAL(timeout()), this, SLOT(TimeoutSlot2()));
    urlpara = DEVID2;

}
//发送命令
void DevHttpClient::HttpRequest(QByteArray &str,QString &devid)
{
    //post
    QNetworkRequest *request = new QNetworkRequest();
    //QByteArray strpost = str.toLatin1();
    QByteArray key = QByteArray(PRODUCTKEY);
    //QByteArray bytesize = QByteArray::number(strpost.size(),10);
    QString url = QString("http://api.js.cmcconenet.com/cmds?device_id=%1").arg(devid);
    request -> setUrl(QUrl(url));
    //request -> setRawHeader("User-Agent","Fiddler");
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",bytesize);

    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->post(*request,str);
    qDebug()<<"cmd is :"<<str;
}

void DevHttpClient::onSend2DevhttpSignal(QByteArray str,QString devid)
{
    HttpRequest(str,devid);
}

void DevHttpClient::TimeoutSlot2()
{
    QNetworkRequest *request = new QNetworkRequest();

    //QString url = QString("http://api.heclouds.com/devices/datapoints?devIds=%1,").arg(urlpara);
    QString url = QString("http://api.js.cmcconenet.com/devices/datapoints?devIds=%1,").arg(urlpara);
    QByteArray key = QByteArray(PRODUCTKEY);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",cmd_size);
    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->get(*request);
}


void DevHttpClient::onMsgForHttpSignal(QString temp)
{
    if(n_timer->isActive())
        n_timer->stop();

    //urlpara = temp;
    QNetworkRequest *request = new QNetworkRequest();

    QString url = QString("http://api.js.cmcconenet.com/devices/datapoints?devIds=%1,").arg(urlpara);
    QByteArray key = QByteArray(PRODUCTKEY);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",cmd_size);
    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->get(*request);

    //开启定时器
    n_timer->start(2*1000);
}

void DevHttpClient::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QJsonParseError jsonErr;
        QJsonDocument doc = QJsonDocument::fromJson(bytes, &jsonErr);
        if (!doc.isNull() && (jsonErr.error == QJsonParseError::NoError))
        {
            if(doc.isObject())
            {
                QJsonObject obj = doc.object();
                if(obj.contains("data"))
                {
                    QJsonValue val = obj.value("data");
                    if(val.isObject())
                    {
                        QString device_id_created;
                        QString key_created;
                        QJsonObject obj1 = val.toObject();
                        /**************创建设备****************/
                        if(obj1.contains("device_id"))
                        {
                            QJsonValue value = obj1.value("device_id");
                            if(value.isString())
                            {
                                device_id_created = value.toString();
                                qDebug() << "device_id_created : " << device_id_created;
                            }
                        }
                        if(obj1.contains("key"))
                        {
                            QJsonValue value = obj1.value("key");
                            if(value.isString())
                            {
                                key_created = value.toString();
                                qDebug() << "key_created : " << key_created;
                            }

                        }
                        //写入设备注册信息到数据库
                        //WriteToSqlbase( device_id_created, key_created);

                        /**************更新并保存设备信息文件******************/
                        if(obj1.contains("devices"))
                        {

                            QJsonValue value1 = obj1.value("devices");

                            QJsonArray arr1 = value1.toArray();
                            int testcount = 0 ;
                            QJsonArray json_array;

                            for(int j = 0; j < arr1.size(); j++)
                            {
                                QJsonValue jsonvalue = arr1.at(j);
                                QJsonObject object = jsonvalue.toObject();
                                if(object.contains("datastreams"))
                                {
                                    //批量查询设备最新数据

                                    QJsonArray arr = object.value("datastreams").toArray();
                                    QString dev_id = object.value("id").toString();

                                    for (int i = 0;i<arr.size(); i++)
                                    {

                                        QJsonValue value = arr.at(i);
                                        QJsonObject obj = value.toObject();

                                        QString id = obj.value("id").toString();
                                        QString time = obj.value("at").toString();
                                        QString temp1 = obj.value("value").toString();
                                        //QString temp_s = QString::number(temp1);
                                        QString str = dev_id+","+id+","+temp1+","+time;
                                        //qDebug()<<"recv str :"<<str;
                                        if(id == "05") //地磁信息
                                        {
                                            QJsonObject json_obj;
                                            json_obj.insert("dev_id",dev_id);
                                            json_obj.insert("value",temp1);
                                            json_array.insert(testcount,QJsonValue(json_obj));
                                            testcount++;
                                        }
                                        if(id == "03") //rtc校时
                                        {

                                        }

                                    }

                                }
                            }
                            QJsonDocument document;
                            document.setArray(json_array);
                            QByteArray byte_array = document.toJson(QJsonDocument::Compact);
                            QString json_str(byte_array);
                            emit LastDataSendSignal(json_str);

                        }
                        /**************命令行响应******************/
                        if(obj1.contains("cmd_uuid"))
                        {
                            QJsonValue valuer = obj1.value("cmd_uuid");
                            QString cmd_uuid = valuer.toString();

                            //emit Send_cmd_uuid_Signal(cmd_uuid);
                        }
                        if(obj1.contains("status"))
                        {
                            QJsonValue valuer = obj1.value("status");
                            int status = valuer.toInt();
                            //statusHandle(status);
                        }

                        /**************查询数据流******************/
                        if(obj1.contains("count"))
                        {
                            QJsonValue value = obj1.value("count");
                            int  data_size = value.toInt();
                            qDebug() << "data_size : " << data_size;

                        }
                        if(obj1.contains("datastreams"))
                        {
                            QJsonValue value = obj1.value("datastreams");
                            if(value.isArray())
                            {
                                QJsonArray array = value.toArray();
                                for(int i = 0; i<array.size(); i++)
                                {
                                    QJsonValue value = array.at(i);
                                    if(value.isObject())
                                    {
                                        QJsonObject obj2 = value.toObject();
                                        if(obj2.contains("datapoints"))
                                        {
                                            QJsonValue valu = obj2.value(("datapoints"));
                                            if(valu.isArray())
                                            {
                                                QJsonArray arr = valu.toArray();
                                                for(int i = 0; i<arr.size(); i++)
                                                {
                                                    QJsonValue obj = arr.at(i);
                                                    QJsonObject obj1 = obj.toObject();
                                                    if(obj1.contains("at"))
                                                    {
                                                        QJsonValue val = obj1.value("at");
                                                        if(val.isString())
                                                        {
                                                            QString attime = val.toString();
                                                            qDebug() << "attime : " << attime;
                                                        }
                                                    }
                                                    if(obj1.contains("value"))
                                                    {
                                                        QJsonValue value = obj1.value("value");
                                                        int value1 = value.toInt();
                                                        qDebug() << "value1 : " << value1;
                                                    }
                                                }
                                            }
                                        }
                                        if(obj2.contains("id"))
                                        {
                                            QJsonValue val = obj2.value("id");
                                            if(val.isString())
                                            {
                                                QString id = val.toString();
                                                qDebug() << "id : " << id;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(obj.contains("errno"))
                {
                    QJsonValue value = obj.value("errno");
                    int error = value.toInt();
                    if(error == 10){
                        //设备不在线

                    }
                    emit ErrorHandlerSignal(error);

                }
            }
        }
        //qDebug()<<bytes;

    }
    else
    {
        qDebug()<<"handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug( "found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
        QString msg  = QString("found error ....code: %1 %2\n")
                .arg(QString::number(statusCodeV.toInt()))
                .arg(QString::number((int)reply->error()));
        emit  httpConnectSignal(msg);
    }
    reply->deleteLater();
}


void DevHttpClient::onsendrtcSignal(QString devid,QString rtc)
{
    bool ok;
    quint32  RTC_DEV = rtc.toUInt(&ok, 16);
    quint32  RTC_CUR = QDateTime::currentDateTime().toTime_t();
    //quint32 RTC = RTC_CUR*2-RTC_DEV;
    quint32 RTC = RTC_CUR;
qDebug()<<"RTC_DEV  str is :"<<rtc;
    qDebug()<<"RTC_DEV is :"<<RTC_DEV;

 qDebug()<<"RTC_CUR is :"<<RTC_CUR;
  qDebug()<<"RTC is :"<<RTC;
    quint8 tabno = 0x03;
    quint16 tablength = 0x0010;

    QString tabno_str = QString("03");
    QString tablength_str = QString("000A");

    //协议组合
//    QByteArray block;
//    QDataStream out(&block,QIODevice::ReadWrite);
//    for(int i = 0 ; i < 5; i++){
//        out<<quint8(0xfe);
//    }
//    out<<tabno<<tablength<<RTC<<quint8(0)<<quint16(0)<<quint8(0x00);

    QString block;

    block.append("FEFEFEFEFE");
    block.append(tabno_str);
    block.append(tablength_str);
    block.append(QString("%1").arg(RTC&0xFFFFFFFF,8,16,QLatin1Char('0')));
    block.append("00000000");
    qDebug()<<"block is :"<<block;
    QByteArray blockarray = block.toLatin1();
    HttpRequest(blockarray,devid);
}

//发送参数命令
void DevHttpClient::onsendParaSignal(QString msg)
{
qDebug()<<"onsendParaSignal:";
    QJsonDocument jsonDocument = QJsonDocument::fromJson(msg.toLocal8Bit().data());
    if( jsonDocument.isNull() ){
        return;
    }
    QJsonArray jsonarray = jsonDocument.array();
    //qDebug()<<"jsonObject.size():"<<jsonObject.size();

    for(int i = 0 ; i < jsonarray.size(); i++)
    {
        QJsonObject jsonObject = jsonarray.at(i).toObject();
         QString devid =  jsonObject.value("devid").toString();
        //协议组合
quint16 deltaup = jsonObject.value("deltaup").toInt();
qDebug()<<"deltaup:"<<deltaup;
        HttpRequest(Cmd4Send(jsonObject),devid);

    }
}

QByteArray DevHttpClient::Cmd4Send(QJsonObject &jsonObject)
{
    quint8 tabno = 0x02;
    quint16 tablength = 0x0011;
    quint8 updataflag =  jsonObject.value("appdownload").toInt();
    quint16 deltaup = jsonObject.value("deltaup").toInt();
    quint16 deltadown = jsonObject.value("deltadown").toInt();
    quint16 setinit = jsonObject.value("setinit").toInt();


    //协议组合
//    QByteArray block;
//    QDataStream out(&block,QIODevice::ReadWrite);
//    for(int i = 0 ; i < 5; i++){
//        out<<quint8(0xfe);
//    }
//    out<<tabno<<tablength<<updataflag<<deltaup<<deltadown<<setinit<<quint16(0)<<quint8(0x00);
    QString block;
    block.append("FEFEFEFEFE");
    block.append("02");
    block.append("0011");
    block.append(QString("%1").arg(updataflag&0xFF,2,16,QLatin1Char('0')));
    block.append(QString("%1").arg(deltaup,4,16,QLatin1Char('0')));
    block.append(QString("%1").arg(deltadown,4,16,QLatin1Char('0')));

    block.append(QString("%1").arg(setinit&0xFFFF,4,16,QLatin1Char('0')));
    block.append("000000");

    return block.toLatin1();

}

//设备响应处理
void DevHttpClient::ResponseDevice(DevicePc1 *devpc,quint16 devicetagcount)
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
                //rtc_list.append(rtcpara);
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
//    if(!rtc_list.isEmpty())
//    {
//        //rtc计时器激活
//        QTimer::singleShot(2000,this,SLOT(RTCtimerSlot()));
//        SendMsg(msg);
//        qDebug()<<"rtc msg :"<<msg.toHex();
//    }


}

//rtc timer开始
void DevHttpClient::RTCtimerSlot()
{
    //发送RTC消息
//    QByteArray block;
//    tableHeader tabhead;

//    tabhead.frame = 0x00;
//    tabhead.command = 0x04;
//    tabhead.version = 0x10000000;
//    quint16 rtclist_size = rtc_list.size();
//    for(int i = 0; i < rtclist_size; i++)
//    {

//        QByteArray t_block = utils->WritePara_NO_3(rtc_list.at(i));
//        block.append(t_block);

//    }

//    int len = 10 + block.size();
//    Utils::int2bcd(tabhead.length,len);

//    QByteArray msg = utils->MsgForSend(tabhead.frame,tabhead.length,tabhead.command,tabhead.version,block,rtclist_size);

//    SendMsg(msg);

//    qDebug()<<"rtc msg after 2 s:"<<msg.toHex();
//    rtc_list.clear();


}
