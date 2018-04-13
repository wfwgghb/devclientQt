#ifndef DEVHTTPCLIENT_H
#define DEVHTTPCLIENT_H

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
#include "utils.h"

#define PRODUCTKEY "T4su6nQsWaqZYYP5dl3o6XqYW48= "
#define DEVID2 "80094928"

class DevHttpClient : public QObject
{
    Q_OBJECT
public:
    explicit DevHttpClient(QObject *parent = 0);
private:
    QString urlpara;
    QThread *m_thread;
    QNetworkAccessManager *m_accessManager;
    QTimer *n_timer;
    Utils *utils ;
    void HttpRequest(QByteArray &str, QString &devid);
    void ResponseDevice(DevicePc1 *devpc,quint16 devicetagcount);
    QByteArray Cmd4Send(QJsonObject &jsonObject);
signals:
    void ErrorHandlerSignal(int errorno);
    void LastDataSendSignal(QString str);
    void HttpClientSignal(QByteArray byte_array);
    void httpConnectSignal(QString msg);

public slots:
    void finishedSlot(QNetworkReply* reply);
    void Initial();
    void TimeoutSlot2();
    void onMsgForHttpSignal(QString temp);
    void RTCtimerSlot();
    void onsendParaSignal(QString msg);
    void onsendrtcSignal(QString devid,QString rtc);
    void onSend2DevhttpSignal(QByteArray str, QString devid);

};

#endif // DEVHTTPCLIENT_H
