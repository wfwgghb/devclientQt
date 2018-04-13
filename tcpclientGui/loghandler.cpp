#include "loghandler.h"
#include "sqlwork.h"


LogHandler::LogHandler(QObject *parent) : QObject(parent)
{
    onlineFlag = true;

    m_thread=new QThread;
    this->moveToThread(m_thread);
    connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
    m_thread->start();
}

LogHandler::~LogHandler()
{

}

void LogHandler::Initial()
{

    sqlwork = new SqlWork;
//    checktimer = new QTimer;

    if(!sqlwork->ConnSqlDatabase(LogthreadName))
    {
        //错误处理
    }
    db_connection = SqlWork::getConnectionByName(LogthreadName);

//    connect(checktimer,SIGNAL(timeout()),this,SLOT(checktimerSlot()));
//    checktimer->start(CHECKTIME);

    //定时5min后扫描数据库
//    QTimer::singleShot(2*60*1000,this,SLOT(checkOnlineSlot()));
}

void LogHandler::UsernameSlot(QString userName)
{
    username = userName;
}

void LogHandler::onLogSignal(QString olddata)
{
    quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
    if(olddata.isEmpty())
    {
        //扫描dev_info

        QSqlQuery query(db_connection);
        QSqlQuery query1(db_connection);
        query.exec("SELECT DEVID FROM (SELECT ROWID FROM dev_info WHERE CONNECT = 0) a,dev_attr b WHERE a.ROWID =b.ROWID");
        query1.exec("START TRANSACTION");
        while(query.next())
        {
            QString dev_id = query.value(0).toString();
            if(!dev_id.isEmpty())
            {
                QString sql1 = QString("INSERT INTO dev_warn VALUES(NULL,'%1','2',%2,'%3','');")
                        .arg(dev_id).arg(QString::number(LastRTC,10)).arg(username);
                query1.exec(sql1);
            }
        }
        query1.exec("COMMIT");
    }else
    {
        QStringList oldlist = olddata.split(";");
        QSqlQuery query(db_connection);
        //事务处理
        QTime tmptime;
        tmptime.start();
        query.exec("START TRANSACTION");
        for(int i = 0; i < oldlist.size()-1; i++)
        {
            query.exec(oldlist.at(i));
        }
        query.exec("COMMIT");
        qDebug()<<"log finished write spend time:"<<tmptime.elapsed()<<endl;
    }
}





