#include "sqlwork.h"
#include "utils.h"

SqlWork::SqlWork(QObject *parent) : QObject(parent)
{

}
SqlWork::~SqlWork()
{
    database.close();
}
bool SqlWork::ConnSqlDatabase(const QString &connectionName)
{

            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL",connectionName);
            db.setHostName("127.0.0.1");  //设置数据库所在位置
            db.setUserName("root");       //设置数据库的用户名
            db.setPassword("123");     //设置数据库的密码
            db.setDatabaseName("nbiot");  //设置数据库名称
            bool bRet = db.open();        //打开数据库连接

            if(bRet == false)
            {
                //说明可以通过db.lastError()的方式得到错误信息
                qDebug() << "error open database" << db.lastError().text();
                exit(0);
            }
            qDebug() << "open database success";

return true;

}

QSqlDatabase SqlWork::getConnectionByName(const QString &connectionName) {
    return QSqlDatabase::database(connectionName);
}

bool SqlWork::LogInfoTable(Loginfo *loginfo, int count, QSqlDatabase dbname)
{
    QSqlQuery query(dbname);
    for(int i = 0; i < count; i++)
    {
        QString sql = QString("insert into operation_log values(null,%1,%2,'%3',%4,'%5')")
                .arg((loginfo+i)->YWLX).arg((loginfo+i)->CZLX).arg((loginfo+i)->CZR)
                .arg((loginfo+i)->CZSJ).arg((loginfo+i)->CZNR);
        if(!query.exec(sql))
        {
            return false;
        }
    }
    return true;
}

void SqlWork::UpdateInfoTable(DevicePc1 *devpc ,quint16 devicetagcount,QSqlDatabase dbname )
{

    QSqlQuery query(dbname);
    //事务处理
    query.exec("START TRANSACTION");
    for(int i = 0; i <devicetagcount; i++)
    {
        if(devpc->tabNo == COMMDATA)
        {
            //历史数据库
            QString sql = QString("INSERT INTO geo_val VALUES(NULL,'%1',%2,%3,%4,%5,%6,%7,%8,%9)")
                    .arg(devpc->deviceID)
                    .arg(devpc->initX).arg(devpc->initY).arg(devpc->initZ)
                    .arg(devpc->currX).arg(devpc->currY).arg(devpc->currZ)
                    .arg(devpc->carInfo).arg(devpc->RTC);
            QString sql1 = QString("UPDATE ");
            query.exec(sql);

        }/*else if(devpc->tabNo == BATTERYCHARGE)      //电量
        {
            if(devpc->batteryAlarm != 2)     //0:无数据     1:低电量       2:正常电量
            {
                QString sql = QString("UPDATE dev_para p, dev_attr a set p.DEVPOWER = '%1' where p.ROWID =(SELECT) ")
                        .arg(devpc->batteryAlarm)
                        .arg(devpc->initX);
                query.exec(sql);
            }
        }else if(devpc->tabNo == DEVICEREQ)         //版本
        {
            QString sql = QString("UPDATE dev_warn w, dev_attr a set w.DEVPOWER = '%1' where w.ROWID =(SELECT) ")
                    .arg(devpc->batteryAlarm)
                    .arg(devpc->initX);
            query.exec(sql);
        }else if(devpc->tabNo == HEARTBEAT)         //电量 上下限
        {
            QString sql = QString("UPDATE dev_warn w, dev_attr a set w.DEVPOWER = '%1' where w.ROWID =(SELECT) ")
                    .arg(devpc->batteryAlarm)
                    .arg(devpc->initX);
            query.exec(sql);
        }*/
    }

    query.exec("COMMIT");
//    QString(devpc->deviceID)
}

