#ifndef SQLTHREAD_H
#define SQLTHREAD_H

#include <QThread>
#include <QObject>
#include <QSqlDataBase>
#include "utils.h"

#define CHECKTIME 6*60*60


class SqlWork;
class SqlThread : public QObject
{
    Q_OBJECT
public:
    explicit SqlThread(QObject *parent = 0);
    ~SqlThread();
    void WriteData2sqlbase(DevicePc1 *devpc,quint16 devicetagcount);
    int bcd2int(quint8 *bcd , int len = 4);
private:
    SqlWork *sqlwork;
    QThread *m_thread;
    QSqlDatabase db_connection;
    bool onlineFlag;
    QTimer *checktimer;
    Utils *utils;
    QString username;
signals:
    void SqlfinishedSignal();
    void LogSignal(QString s_OldData);
public slots:
      void Initial();
      void onSendDataSignal(QByteArray recvdata);
      //void WriteData2sqlbase(QVariant tcpdata);
      void checktimerSlot();
      void checkOnlineSlot();
      void UsernameSlot(QString userName);
};

#endif // SQLTHREAD_H
