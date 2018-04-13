#include "requestlastdatahandler.h"
#include "sqlwork.h"

requestLastDataHandler::requestLastDataHandler(QObject *parent) : QObject(parent)
{

    m_thread=new QThread;
    this->moveToThread(m_thread);
    connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
    m_thread->start();
}

void requestLastDataHandler::Initial()
{
    oneflag = true;
    sqlwork = new SqlWork;
    if(!sqlwork->ConnSqlDatabase(TcpSqlName))
    {
        //错误处理
    }
    db_connection = SqlWork::getConnectionByName(TcpSqlName);

    QSqlQuery query(db_connection);
    QString sql = QString("SELECT * FROM dev_attr");
    query.exec(sql);
    //500个设备
    while (query.next()) {

        QString devid = query.value(1).toString();
        devids.append(devid);
        devids.append(",");
        onlineinfo.insert(devid,false);

        QJsonObject json_obj;
        json_obj.insert(MAGSTR,devid);
        json_obj.insert(MSGSTR,QString("online"));
        json_obj.insert(QString("voltage"),QString("2"));
        QByteArray byte_array = QJsonDocument(json_obj).toJson(QJsonDocument::Compact);
        emit HttpClientSignal(byte_array);

        QString devberth  = query.value(2).toString();
        QString devarea  = query.value(3).toString();
        QString tcc  = query.value(4).toString();
        QString temp;
        temp.append(devarea);
        temp.append(tcc);
        temp.append(devberth);

        berth2send.insert(devid,temp);

    }
    qDebug()<<"History data is :"<<devids;
    utils = new Utils;
    m_accessManager = new QNetworkAccessManager();
    n_timer = new QTimer;
    m_timer = new QTimer;
    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(finishedSlot(QNetworkReply*)));

    connect(n_timer, SIGNAL(timeout()), this, SLOT(TimeoutSlot2()));
    connect(n_timer, SIGNAL(timeout()), this, SLOT(TimeoutSlot3()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimeoutSlot4()));
    //开启定时器
    n_timer->setTimerType(Qt::PreciseTimer);
    n_timer->start(1*1000);

    //开启定时器
    m_timer->setTimerType(Qt::PreciseTimer);
    m_timer->start(7*1000*60*60);
    //m_timer->start(6*1000);
//    m_timer->setTimerType(Qt::PreciseTimer);
//    m_timer->start(5*1000);


}

void requestLastDataHandler::TimeoutSlot4()
{
    QMap <QString ,bool >::iterator it_onlineinfo;
    //检测online设备
    for(it_onlineinfo=onlineinfo.begin();it_onlineinfo!=onlineinfo.end();it_onlineinfo++)
    {
        QString devid = it_onlineinfo.key();
        bool online = it_onlineinfo.value();
        qDebug()<<"devid,online"<<devid<<online;
        emit devOnlineSignal(devid,online);

        QJsonObject json_obj;
        json_obj.insert(MAGSTR,devid);
        if(online){
            json_obj.insert(MSGSTR,QString("online"));
        }else{
             json_obj.insert(MSGSTR,QString("offline"));
        }

        json_obj.insert(QString("voltage"),QString("2"));
        QByteArray byte_array = QJsonDocument(json_obj).toJson(QJsonDocument::Compact);
        emit HttpClientSignal(byte_array);

        if(online) // 在线
        {
            onlineinfo[devid] = false;
        }
    }
}

void requestLastDataHandler::TimeoutSlot2()
{
    QNetworkRequest *request = new QNetworkRequest();

    QString url = QString("http://api.js.cmcconenet.com/devices/datapoints?devIds=%1,").arg(DEVID2);
    //QString url = QString("http://api.heclouds.com/devices/datapoints?devIds=%1,").arg(devids);
    QByteArray key = QByteArray(PRODUCTKEY);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",cmd_size);
    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->get(*request);
}

void requestLastDataHandler::TimeoutSlot3()
{
    QNetworkRequest *request = new QNetworkRequest();

    QString url = QString("http://api.js.cmcconenet.com/devices/status?devIds=%1,").arg(DEVID2);
    //QString url = QString("http://api.heclouds.com/devices/datapoints?devIds=%1,").arg(devids);
    QByteArray key = QByteArray(PRODUCTKEY);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",cmd_size);
    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->get(*request);
}

void requestLastDataHandler::DevattrChangedSlot()
{

    QSqlQuery query(db_connection);
    QString sql = QString("SELECT * FROM dev_attr");
    query.exec(sql);

    while (query.next()) {
        QString devid =query.value(1).toString();
        devids.append(devid);
        devids.append(",");

        QString devberth  = query.value(2).toString();
        QString devarea  = query.value(3).toString();
        QString tcc  = query.value(4).toString();
        QString temp;
        temp.append(devarea);
        temp.append(tcc);
        temp.append(devberth);

        berth2send.insert(devid,temp);
    }
}

void requestLastDataHandler::sqlHandler()
{

}

void requestLastDataHandler::onMsgForHttpSignal(QString temp)
{


}

void requestLastDataHandler::finishedSlot(QNetworkReply* reply)
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

                            QMap <QString , QString>::iterator  it_rtcCheck;
                            QMap <QString , QString>::iterator it_hisInfo;
                            QMap <QString , QString>::iterator it_dev_lastTime;
                            QMap <QString , QString>::iterator it_berth2send;

                            QJsonValue value1 = obj1.value("devices");

                            QJsonArray arr1 = value1.toArray();
                            int testcount = 0 ;
                            QJsonArray json_array;
                            QSqlQuery query(db_connection);
                            QTime tmptime;
                            tmptime.start();
                            query.exec("START TRANSACTION");

                            QMap <QString ,QByteArray >::iterator mi;
                            for(int j = 0; j < arr1.size(); j++)
                            {
                                QJsonValue jsonvalue = arr1.at(j);
                                QJsonObject object = jsonvalue.toObject();
                                if(object.contains("datastreams"))
                                {
                                    //批量查询设备最新数据

                                    QJsonArray arr = object.value("datastreams").toArray();
                                    QString dev_id = object.value("id").toString();
                                    onlineinfo[dev_id] = true;
                                    //onlineinfo.insert(dev_id,CONNECT);
                                    for (int i = 0;i<arr.size(); i++)
                                    {

                                        QJsonValue value = arr.at(i);
                                        QJsonObject obj = value.toObject();

                                        QString id = obj.value("id").toString();
                                        QString time = obj.value("at").toString();
                                        QString temp1 = obj.value("value").toString();
                                        //QString temp_s = QString::number(temp1);
                                        QString str = dev_id+","+id+","+temp1+","+time;
                                        QJsonObject json_obj;
                                        if(id == "05") //地磁信息
                                        {
                                            QStringList info = ParseText(temp1);
                                            //qDebug()<<"enter into space"<<endl;
                                            it_hisInfo = hisInfo.find(dev_id);
                                            if(it_hisInfo != hisInfo.end())
                                            {

                                                if(it_hisInfo.value() != temp1)
                                                {
                                                    qDebug()<<"insert into data ！！！！"<<endl;

                                                    //时间不同，请求命令返回
                                                    QString sql = QString("INSERT INTO geo_val VALUES(NULL,'%1','%2','%3','%4','%5','%6','%7','%8','%9','%10');")
                                                            .arg(dev_id).arg(info.at(0)).arg(info.at(1))
                                                            .arg(info.at(2)).arg(info.at(3)).arg(info.at(4))
                                                            .arg(info.at(5)).arg(info.at(6)).arg(info.at(7)).arg(info.at(9));
                                                    if(!query.exec(sql)){
                                                        qDebug()<<"insert into data failed"<<endl;
                                                        qDebug()<<query.lastError().text();

                                                    }
                                                    hisInfo[dev_id] = temp1;
                                                    it_berth2send = berth2send.find(dev_id);
                                                     QString berth;
                                                    if(it_berth2send != berth2send.end()){
                                                         berth = it_berth2send.value();
                                                    }

                                                    if(info.at(6) == QString("01")){

                                                        json_obj.insert(MSGSTR,QString("leaving"));
                                                    }else if(info.at(6) == QString("02")){
                                                        json_obj.insert(MSGSTR,QString("parking"));
                                                    }
                                                    json_obj.insert(MAGSTR,dev_id);
                                                    json_obj.insert(TSSTR,berth);
                                                    json_obj.insert(QString("ts"),info.at(7));
                                                    json_obj.insert(QString("voltage"),QString("2"));
                                                    QByteArray byte_array = QJsonDocument(json_obj).toJson(QJsonDocument::Compact);
                                                    emit HttpClientSignal(byte_array);

                                                    if(info.at(8) == "01")//电量警告
                                                    {
                                                        QJsonObject json_obj1;
                                                        json_obj1.insert(MSGSTR,QString("alarm"));
                                                        json_obj1.insert(MAGSTR,dev_id);
                                                        QString ts = QString::number(QDateTime::currentDateTime().toTime_t());
                                                        json_obj1.insert(QString("ts"),ts);
                                                        json_obj1.insert(QString("voltage"),QString("1"));
                                                        QByteArray byte_array = QJsonDocument(json_obj1).toJson(QJsonDocument::Compact);
                                                        emit HttpClientSignal(byte_array);
                                                        emit LowPowerSignal(dev_id);
                                                    }

                                                }

                                            }else{
                                                //未找到添加
                                                hisInfo.insert(dev_id,temp1);
//                                                QString sql = QString("INSERT INTO geo_val VALUES(NULL,'%1','%2','%3','%4','%5','%6','%7','%8','%9');")
//                                                        .arg(dev_id).arg(info.at(0)).arg(info.at(1))
//                                                        .arg(info.at(2)).arg(info.at(3)).arg(info.at(4))
//                                                        .arg(info.at(5)).arg(info.at(6)).arg(info.at(7));
//                                                if(query.exec(sql)){
//                                                    qDebug()<<"insert into data succ"<<endl;
//
 //                                               }

                                            }

                                            //qDebug()<<"recv sql:"<<sql;
                                        }
                                        if(id == "03")//设备请求（校时）
                                        {
                                            QString rtc = ParseText1(temp1);
                                            it_rtcCheck = rtcCheck.find(dev_id);
                                            if(it_rtcCheck != rtcCheck.end())
                                            {
                                                if(it_rtcCheck.value() != rtc)
                                                {
                                                    //时间不同，请求命令返回
                                                    emit rtcSignal(dev_id,rtc);
                                                    rtcCheck[dev_id] = rtc;
                                                    qDebug()<<" emit rtcSignal(dev_id,rtc);";
                                                }

                                            }else{
                                                //未找到添加
                                                rtcCheck.insert(dev_id,rtc);
                                                emit rtcSignal(dev_id,rtc);
                                                qDebug()<<" emit rtcSignal(dev_id,rtc);";

                                            }

                                        }if(id == "02")//参数回表
                                        {

                                            it_dev_lastTime = dev_lastTime.find(dev_id);
                                            if(it_dev_lastTime != dev_lastTime.end())
                                            {
                                              if(it_dev_lastTime.value() != time)
                                              {
                                                    //时间不同，请求命令返回
                                                    emit paraSuccSignal();

                                                    dev_lastTime.insert(dev_id,time);
                                              }


                                            }else{

                                                emit paraSuccSignal();
                                                dev_lastTime.insert(dev_id,time);
                                            }

                                        }


                                    }

                                }
                                if(object.contains("online"))
                                {
                                    QString dev_id = object.value("id").toString();
                                    bool online = object.value("online").toBool();

                                    //onlineinfo.insert(dev_id,online);
                                    //5s 刷新检测在线状态
                                    if(online)
                                    {
                                        //QTimer::singleShot(0, this, SLOT(calculate()));

                                            mi = cmdinfo.find(dev_id);
                                            if(mi != cmdinfo.end()&&mi.key() == dev_id){
                                                QByteArray cmd = mi.value();
                                                emit Send2DevhttpSignal(cmd ,dev_id);

                                            //    HttpRequest(cmd,dev_id);
                                                cmdinfo.remove(dev_id);
                                            }
                                            onlineinfo[dev_id] = true;

                                    }

                                }
                            }
                            query.exec("COMMIT");
                            qDebug()<<"sqldatabase write spend time:"<<tmptime.elapsed()<<endl;


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
//void requestLastDataHandler::calculate()
//{
//   QMap <QString ,QByteArray >::iterator mi;
//    mi = cmdinfo.find(dev_id);
//    QByteArray cmd = mi.value();
//    HttpRequest(cmd,dev_id);
//    cmdinfo.remove(dev_id);
//}
//发送命令
void requestLastDataHandler::HttpRequest(QByteArray &str,QString &devid)
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
}

void requestLastDataHandler::onsendParaSignal(QString msg)
{

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

        cmdinfo.insert(devid,Cmd4Send(jsonObject));
        //HttpRequest(Cmd4Send(jsonObject),devid);

    }
}

QByteArray requestLastDataHandler::Cmd4Send(QJsonObject &jsonObject)
{
    QString tabno = "02";
    QString tablength = "000B";
    quint8 updataflag =  jsonObject.value("appdownload").toInt();
    QString ss;
    ss.append(QString("%1").arg(updataflag&0xff,2,16,QLatin1Char('0')));
    quint16 deltaup = jsonObject.value("deltaup").toInt();
    ss.append(QString("%1").arg(deltaup&0xffff,4,16,QLatin1Char('0')));
    qDebug()<<"deltaup"<<deltaup;

    quint16 deltadown = jsonObject.value("deltadown").toInt();
    ss.append(QString("%1").arg(deltadown&0xffff,4,16,QLatin1Char('0')));
    quint16 setinit = jsonObject.value("setinit").toInt();
    ss.append(QString("%1").arg(setinit&0xffff,4,16,QLatin1Char('0')));
    //协议组合
    QByteArray block;

    QString sstemp = QString("FEFEFEFEFE");
    sstemp.append(tabno);
    sstemp.append(tablength);
    sstemp.append(ss);
    sstemp.append("00");
    //out<<tabno<<tablength<<updataflag<<deltaup<<deltadown<<setinit<<quint8(0x00);
    block = sstemp.toLatin1();
    return block;

}

QString requestLastDataHandler::short2string(ushort temp){

    short pairid;

    if(temp >= 32768){
         pairid = temp-65536;

    }else{
         pairid = temp;
    }
    QString pairid_str = QString::number(pairid);
    //qDebug()<<"pairid:"<<pairid_str;
    return pairid_str;
}

QStringList requestLastDataHandler::ParseText(QString &text)
{
    QString pairid = text.mid(16,2);
    ushort initx = text.mid(18,4).toUShort(Q_NULLPTR,16);
    ushort inity = text.mid(22,4).toUShort(Q_NULLPTR,16);
    ushort initz = text.mid(26,4).toUShort(Q_NULLPTR,16);
    ushort currx = text.mid(30,4).toUShort(Q_NULLPTR,16);
    ushort curry = text.mid(34,4).toUShort(Q_NULLPTR,16);
    ushort currz = text.mid(38,4).toUShort(Q_NULLPTR,16);

    QString u_initx_str = short2string(initx);

    QString u_inity_str = short2string(inity);
    QString u_initz_str = short2string(initz);
    QString u_currx_str = short2string(currx);
    QString u_curry_str = short2string(curry);
    QString u_currz_str = short2string(currz);
//        QString u_initx_str = QString::number(initx);
//        QString u_inity_str = QString::number(inity);
//        QString u_initz_str = QString::number(initz);
//        QString u_currx_str = QString::number(currx);
//        QString u_curry_str = QString::number(curry);
//        QString u_currz_str = QString::number(currz);
    QString carinfo = text.mid(42,2);
    QString rtc = text.mid(44,8);
    uint u_rtc = rtc.toUInt(Q_NULLPTR,16);
    QString u_rtc_str = QDateTime::fromTime_t(u_rtc).toString("yyyy-MM-dd hh:mm:ss");
    //QString u_rtc_str = QString::number(u_rtc);
    QString power = text.mid(52,2);
    QStringList info_list;
    info_list<<u_initx_str<<u_inity_str<<u_initz_str<<u_currx_str<<u_curry_str<<u_currz_str<<carinfo<<u_rtc_str<<power<<pairid;
    return info_list;

}

QString requestLastDataHandler::ParseText1(QString &text)
{
    //QString rtctimer;
    //QString REQTYPE = text.mid(20,2);

//    QStringList info_list;
//    info_list<<APPVERSION<<REQTYPE;

    QString rtcstr = text.mid(16,8);

    return rtcstr;


}

QStringList requestLastDataHandler::ParseText2(QString &text)
{
    //QString rtctimer;
    //QString REQTYPE = text.mid(20,2);

    QStringList info_list;
//    info_list<<APPVERSION<<REQTYPE;

    QString appdownload = text.mid(16,2);

    QString dev_up = text.mid(18,4);
    QString dev_down = text.mid(22,4);

    QString init_env = text.mid(26,2);
    info_list<<appdownload<<dev_up<<dev_down<<init_env;
    return info_list;


}
//文件上传
void requestLastDataHandler::onUploadfileNameSignal(QString path){

     qDebug()<<" enter into onUploadfileNameSignal"<<endl;
    uploadfilename = path;

    getUploadFile();

}

void requestLastDataHandler::getUploadFile(){

    QFile *loadFile=new QFile(uploadfilename);
      QDataStream in(loadFile);
      if(!loadFile->open(QIODevice::ReadOnly))
      {
          qDebug()<<"uploadfile not open!"<<endl;
          return;
      }
      int dataLen=in.readRawData(dataBuf,1024*64); //其中dataBuf为char类型预先申请的空间

         qDebug()<<"datalen:"<<dataLen<<endl;

}

void requestLastDataHandler::onStartUploadFileSignal(){

}
