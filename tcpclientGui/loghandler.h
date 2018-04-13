#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QThread>
#include <QObject>
#include <QSqlDataBase>
#include "utils.h"

class SqlWork;
class LogHandler : public QObject
{
    Q_OBJECT
public:
    explicit LogHandler(QObject *parent = 0);
    ~LogHandler();

private:
    SqlWork *sqlwork;
    QThread *m_thread;
    QSqlDatabase db_connection;
    bool onlineFlag;
    QString username;
signals:
    void SqlfinishedSignal();
public slots:
      void Initial();
      void onLogSignal(QString olddata);
    void UsernameSlot(QString userName);
      //void WriteData2sqlbase(QVariant tcpdata);
};
#endif // LOGHANDLER_H




