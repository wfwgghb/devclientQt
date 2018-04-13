#include "httpclient.h"
#include "constant.h"

#include "sqlwork.h"

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    m_thread=new QThread;
    this->moveToThread(m_thread);
    connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
    m_thread->start();
    ve = QString("1.0");

}


void HttpClient::Initial()
{
    sqlwork = new SqlWork;
    if(!sqlwork->ConnSqlDatabase(SqlthreadName))
    {
        //错误处理
    }
    db_connection = SqlWork::getConnectionByName(SqlthreadName);

    QSqlQuery query(db_connection);
    QString sql = QString("SELECT * FROM dev_attr");
    query.exec(sql);
    //500个设备
    while (query.next()) {

        QString devid = query.value(1).toString();
        QString devberth  = query.value(2).toString();
        QString devarea  = query.value(3).toString();
        QString tcc  = query.value(4).toString();
        QString temp;
        temp.append(devarea);
        temp.append(tcc);
        temp.append(devberth);

        berth2send.insert(devid,temp);
    }

    m_accessManager = new QNetworkAccessManager();
    jsonSendtimer = new QTimer;
    connect(jsonSendtimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
    jsonSendtimer->start(1000*5);

}

//void HttpClient::ondevAttrChangedSignal()
//{
//    QSqlQuery query(db_connection);
//    QString sql = QString("SELECT * FROM dev_attr");
//    query.exec(sql);
//    //500个设备
//    while (query.next()) {

//        QString devid = query.value(1).toString();
//        QString devberth  = query.value(2).toString();
//        QString devarea  = query.value(3).toString();
//        QString tcc  = query.value(4).toString();
//        QString temp;
//        temp.append(devarea);
//        temp.append(tcc);
//        temp.append(devberth);

//        berth2send.insert(devid,temp);
//    }
//}

//测试
void HttpClient::timerSlot()
{
    uint ts = QDateTime::currentDateTime().toTime_t();
    json_obj.insert(MSGSTR,"checktime");

    byte_array_test = QJsonDocument(json_obj).toJson(QJsonDocument::Compact);
    //post

    QString temp;
    QByteArray array;
    array.append("data=");
    array.append(byte_array_test);
//    byte_array_test.clear();
//    byte_array_test.append("msg=checktime");
    qDebug()<<"http byte_array_test:"<<QString(array);
    QJsonObject json_object = QJsonDocument::fromJson(byte_array_test).object();

    QString tsstr = QString::number(ts);


    QByteArray data1 = QJsonDocument(json_object).toJson(QJsonDocument::Compact);
    QString data = QString(data1);

    temp = QString("data=%1&partner=%2&ts=%3&ve=%4&secret=%5")
            .arg(data).arg(Partner).arg(tsstr).arg(ve).arg(HttpSecret);

    QByteArray b = QCryptographicHash::hash(temp.toLatin1(),QCryptographicHash::Md5 );
    QString md5=b.toHex();

    QString temp1 = QString("http://192.168.40.124:9076/lesiot/dici?partner=%1&ts=%2&ve=%3&sign=%4")
            .arg(Partner).arg(tsstr).arg(ve).arg(md5);
 //   qDebug()<<"http temp1:"<<temp1;
    QNetworkRequest *request = new QNetworkRequest();

//    QByteArray bytesize = QByteArray::number(msg.size(),10);

    request -> setUrl(QUrl(temp1));
//    request -> setRawHeader("User-Agent","Fiddler");
    request -> setRawHeader("Host","192.168.40.124:9076");
   // request -> setRawHeader("Content-Type","application/x-www-form-urlencoded");
   // request -> setRawHeader("Content-Length",QByteArray(13));
//request->setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
   // request->setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));;
    qDebug()<<"msg.size()"<<byte_array_test.size();
    //request->setHeader(QNetworkRequest::ContentLengthHeader,byte_array_test.size());
    m_accessManager->post(*request,array);
}


void HttpClient::MsgFromTcpSlot(QByteArray msg)
{
    //post
    //qDebug()<<"http msg:"<<QString(msg);
    QString temp;


    QJsonObject json_object = QJsonDocument::fromJson(msg).object();
    QString tsstr = json_object.value("ts").toString();
    json_object.take("ts");

    QByteArray data1 = QJsonDocument(json_object).toJson(QJsonDocument::Compact);
    QString data = QString(data1);

    temp = QString("data=%1&partner=%2&ts=%3&ve=%4&secret=%5")
            .arg(data).arg(Partner).arg(tsstr).arg(ve).arg(HttpSecret);

    QByteArray b = QCryptographicHash::hash(temp.toLatin1(),QCryptographicHash::Md5 );
    QString md5=b.toHex();

    QString temp1 = QString("http://192.168.40.124:9076/lesiot/dici?partner=%1&ts=%2&ve=%3&sign=%4")
            .arg(Partner).arg(tsstr).arg(ve).arg(md5);
     qDebug()<<"http url test:"<<temp1;
    QNetworkRequest *request = new QNetworkRequest();

//    QByteArray bytesize = QByteArray::number(msg.size(),10);

    request -> setUrl(QUrl(temp1));
//    request -> setRawHeader("User-Agent","Fiddler");
    request -> setRawHeader("Host","192.168.40.124:9076");
//    request -> setRawHeader("api-key","MlStkjUK4Z6rSlUG5yj920O1ntA=");
    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    qDebug()<<"msg.size()"<<msg.size();
    QByteArray array;
    array.append("data=");
    array.append(msg);
    qDebug()<<"array is:"<<QString(array);
    //request->setHeader(QNetworkRequest::ContentLengthHeader,msg.size());
    //m_accessManager->post(*request,data1);
m_accessManager->post(*request,array);
}

void HttpClient::finishedSlot(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        qDebug()<<"Http request result is :"<<bytes;
        QJsonParseError jsonErr;
        QJsonDocument doc = QJsonDocument::fromJson(bytes, &jsonErr);
        if (!doc.isNull() && (jsonErr.error == QJsonParseError::NoError))
        {
            if(doc.isObject())
            {
                 QJsonObject obj = doc.object();
                 if(obj.contains("result"))
                 {
                     int result = obj.value("result").toInt();
                     qDebug()<<"Http request result is :"<<result;

                     emit Send2httpserverSignal(result);

                     if(result == 1)
                     {
                         //http发送失败处理
                         //QString msg = QString(QStringLiteral("上传信息到平台，失败！"));

                     }else if(result == 0){
                         //http发送失败处理
                         //QString msg = QString(QStringLiteral("上传信息到平台，成功！"));
                     }
                 }
                 if(obj.contains("time"))
                 {
                     QString result = obj.value("time").toString();
                     qDebug()<<"Http request time is :"<<result;

                 }
            }
        }
    }
}
