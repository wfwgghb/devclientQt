#ifndef REQUESTLASTDATAHANDLER_H
#define REQUESTLASTDATAHANDLER_H

#include <QObject>
#include <QTimer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "utils.h"


#define DEVID2 "80094928"
//#define CONNECT "1"
//#define DISCONNECT "0"

class SqlWork;

class requestLastDataHandler : public QObject
{
    Q_OBJECT
public:
    explicit requestLastDataHandler(QObject *parent = 0);
    void sqlHandler();
    void getUploadFile();
private:
    QString uploadfilename;
    char dataBuf[1024*64];
    QSqlDatabase db_connection;
     QString devids;
    QString urlpara;
    QThread *m_thread;
    QNetworkAccessManager *m_accessManager;
    QTimer *n_timer;
    QTimer *m_timer;
    Utils *utils ;
    SqlWork *sqlwork;

    QStringList ParseText(QString &text);
    QString ParseText1(QString &text);
    QStringList ParseText2(QString &text);
    void HttpRequest(QByteArray &str,QString &devid);
    QByteArray Cmd4Send(QJsonObject &jsonObject);
    QString short2string(ushort temp);

    QMap <QString ,bool > onlineinfo;
    QMap <QString , QByteArray> cmdinfo;
    QMap <QString , QString> rtcCheck;
    QMap <QString ,QString > hisInfo;
    QMap <QString, QString > dev_lastTime;
     QMap <QString, QString > berth2send;
    bool oneflag;
signals:
    void ErrorHandlerSignal(int errorno);
    void LastDataSendSignal(QString str);
    void HttpClientSignal(QByteArray byte_array);
    void Send2DevhttpSignal(QByteArray cmd,QString dev_id);
    void rtcSignal(QString devid,QString rtc);
    void httpConnectSignal(QString msg);
    void devOnlineSignal(QString devid,bool online);
    void paraSuccSignal();
    void LowPowerSignal(QString dev_id);
public slots:
    void finishedSlot(QNetworkReply* reply);
    void Initial();
    void TimeoutSlot2();
    void TimeoutSlot3();
    void TimeoutSlot4();
    void onMsgForHttpSignal(QString temp);
    void DevattrChangedSlot();
    void onsendParaSignal(QString msg);
    void onUploadfileNameSignal(QString path);
    void onStartUploadFileSignal();

};


#endif // REQUESTLASTDATAHANDLER_H
