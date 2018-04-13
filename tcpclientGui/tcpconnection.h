#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QThread>
#include "utils.h"
#include "sqlwork.h"
#include "writelog.h"


#define TIMEOUT 10000
#define DEVMAX  1000


class HttpClient;

class TcpConnection : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnection(QObject *parent = 0);
    ~TcpConnection();

    SqlWork *sqlwork;
    QSqlDatabase db_connection;
    QSqlQuery *query;
    QByteArray m_buffer;

    void dataHander(quint8 * dat);
    void dataHander3(quint8 * dat);
    int bcd2int(quint8 *bcd ,int len = 4);
    void ResponseDevice(DevicePc1 *devpc, quint16 devicetagcount);
private:
    QTcpSocket *socket;
    QThread *m_thread;
    QTimer *timer;
    Utils *utils;
    HttpClient *httpclient ;
    QList <RTCPara> rtc_list;
    int count;
    QString str;
    ErrorFlag ef;
    bool ConnectionFlag;
    QTimer *singleTimer;
signals:
    void stopSocketSignal();
    void ConnectionSuccessSignal();
    void errorSignal(int flag);
    //void ComdataSignal(QVariant var1);
    void RcvmsgSignal(QString rcvmsg);
    void SendDataSignal(QByteArray recvdata);
    void RTCtimerSignal();
    void HttpClientSignal(QByteArray msg);
    void ParaSettingSignal(quint8 data);

public slots:
    void SendMsg(QByteArray data);
    void RcvMsg();
    void Initial();
    void sendHeartBeat();
    void stopSocketSlot();
    void RTCtimerSlot();
    void sendDeviceRequest();

};

#endif // TCPCONNECTION_H
