#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class SqlWork;

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);
    QString ve;
    QByteArray msg;
    QJsonObject json_obj;
    QThread *m_thread;
    QTimer  *jsonSendtimer;
    QByteArray byte_array_test;
    QNetworkAccessManager *m_accessManager;
    QMap <QString, QString > berth2send;
    SqlWork *sqlwork ;
    QSqlDatabase db_connection;
signals:
       void  Send2httpserverSignal(int result);
public slots:
       void Initial();
       void finishedSlot(QNetworkReply* reply);
       void timerSlot();
       void MsgFromTcpSlot(QByteArray msg);

};

#endif // HTTPCLIENT_H
