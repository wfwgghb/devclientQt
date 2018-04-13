#ifndef SQLWORK_H
#define SQLWORK_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

struct Loginfo
{
    int YWLX;
    int CZLX;
    uint CZSJ;
    QString  CZR;
    QString  CZNR;
};

struct DevicePc1;

class SqlWork : public QObject
{
    Q_OBJECT
public:
    explicit SqlWork(QObject *parent = 0);
    ~SqlWork();
    QSqlDatabase database;

    bool ConnSqlDatabase(const QString &connectionName);
    static QSqlDatabase getConnectionByName(const QString &connectionName);
    void UpdateInfoTable(DevicePc1 *devpc , quint16 devicetagcount, QSqlDatabase dbname);
    static bool LogInfoTable(Loginfo *loginfo,int count,QSqlDatabase dbname);
    //void AddInfo2Database(DevicePc1 *devpc,quint16 devicetagcount,QSqlDatabase db_connection);
signals:

public slots:

private:
    //QSqlDatabase db_connection;
};

#endif // SQLWORK_H
