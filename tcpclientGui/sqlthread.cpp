#include "sqlthread.h"
#include "sqlwork.h"


SqlThread::SqlThread(QObject *parent) : QObject(parent)
{
    onlineFlag = true;

    m_thread=new QThread;
    this->moveToThread(m_thread);
    connect(m_thread,SIGNAL(started()),this,SLOT(Initial()));
    m_thread->start();
}

SqlThread::~SqlThread()
{

}

void SqlThread::Initial()
{

    sqlwork = new SqlWork;
    checktimer = new QTimer;
    utils = new Utils;
    if(!sqlwork->ConnSqlDatabase(SqlthreadName))
    {
        //错误处理
    }
    db_connection = SqlWork::getConnectionByName(SqlthreadName);

    connect(checktimer,SIGNAL(timeout()),this,SLOT(checktimerSlot()));
    checktimer->start(CHECKTIME);

    //定时5min后扫描数据库
    QTimer::singleShot(2*60*1000,this,SLOT(checkOnlineSlot()));
}

void SqlThread::UsernameSlot(QString userName)
{
    username = userName;
}

void SqlThread::checkOnlineSlot()
{
//        QString s_OldData = QString("");
//    quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
//    QSqlQuery query(db_connection);
//    query.exec("START TRANSACTION");
//    QString sql = QString("UPDATE dev_info set CONNECT = 0 WHERE  (%1 - ONLINETIME) > %2 AND CONNECT = 1")
//            .arg(QString::number(LastRTC,10)).arg(QString::number(CHECKTIME,10));

//    query.exec(sql);

//    query.exec("COMMIT");
//    qDebug()<<"device inital finished! start to scanned database!"<<endl;
//    emit SqlfinishedSignal();   //  更新主界面图
//    //发送到loghandler线程
//    emit LogSignal(s_OldData);
}

void SqlThread::checktimerSlot()
{
    QString s_OldData = QString("");
    quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
    QSqlQuery query(db_connection);
    query.exec("START TRANSACTION");
    QString sql = QString("UPDATE dev_info set CONNECT = 0 WHERE  (%1 - ONLINETIME) > %2 and CONNECT = 1")
            .arg(QString::number(LastRTC,10)).arg(QString::number(CHECKTIME,10));
    QString sql1 = QString("UPDATE dev_info set CONNECT = 1 WHERE  (%1 - ONLINETIME) < %2 and CONNECT = 0")
            .arg(QString::number(LastRTC,10)).arg(QString::number(CHECKTIME,10));
//    QString sql2 = QString("INSERT INTO dev_warn VALUES(NULL,'%1',%2,%3,'%4','');")
//             .arg(devpc->deviceID).arg(QString::number(devpc->batteryAlarm,10)).arg(QString::number(LastRTC,10).arg(username));
//    s_OldData.append(sql2);
    query.exec(sql);
    query.exec(sql1);

    query.exec("COMMIT");
    emit SqlfinishedSignal();   //  更新主界面图
    //发送到loghandler线程

    emit LogSignal(s_OldData);
}

void SqlThread::onSendDataSignal(QByteArray recvdata)
{

    tableHeader tableheader;
    quint16 check;
    qDebug()<<"recv data of sqlthread is:"<<recvdata.toHex();
    QDataStream in(&recvdata,QIODevice::ReadWrite);
    in>>tableheader.header>>tableheader.frame;
    qDebug()<<"tableheader.header:"<<tableheader.header;
    qDebug()<<"tableheader.frame:"<<tableheader.frame;
    for(int i = 0; i < 4; i++)
    {
        in>>tableheader.length[i];
        //qDebug()<<"tableheader.length"<<tableheader.length[i];
    }
    int tablelength = bcd2int(tableheader.length);
    qDebug()<<"tablelength:"<<tablelength;
    in>>tableheader.command>>tableheader.version;


    int datasize = tablelength-sizeof(quint16)-5;
//        QByteArray tmpdata;
//        in>>tmpdata;
//        QByteArray msg = tmpdata.left(datasize);     //data

    quint8 *Data = new  quint8[datasize];
    if(datasize > 0)
    {
        for(int i = 0;i<datasize;i++)
        {
            in>>Data[i];
        }
    }
    in>>check;
    if(tableheader.command == 0x04)
    {
        //tag解析
        quint8 syncflag = Data[0];
        quint16 devicetagcount = Utils::uchar2ushort(Data+1);
        DevicePc1 *devpc = new DevicePc1[devicetagcount];
        utils->ParseTag(Data+3,datasize-3,devpc,devicetagcount);

        //写入数据库
        WriteData2sqlbase(devpc,devicetagcount);

        delete [] devpc;

    }if(tableheader.command == 0x05)
    {
        DevicePc1 *devpc = new DevicePc1;
        utils->ParseTag(Data+1,datasize-1,devpc,1);

        //写入数据库
        WriteData2sqlbase(devpc,1);
        delete devpc;

    }




}

void SqlThread::WriteData2sqlbase(DevicePc1 *devpc,quint16 devicetagcount)
{

    QString s_OldData = QString("");
    quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
    QSqlQuery query(db_connection);
    //事务处理
    QTime tmptime;
    query.exec("START TRANSACTION");
    tmptime.start();
    for(int i = 0; i <devicetagcount; i++)
    {
        if(devpc->tabNo == COMMDATA)
        {
            //历史数据库
            QString sql = QString("INSERT INTO geo_val VALUES(NULL,'%1',%2,%3,%4,%5,%6,%7,'%8',%9);")
                    .arg(devpc->deviceID)
                    .arg(QString::number(devpc->initX,10)).arg(QString::number(devpc->initY,10)).arg(QString::number(devpc->initZ,10))
                    .arg(QString::number(devpc->currX,10)).arg(QString::number(devpc->currY,10)).arg(QString::number(devpc->currZ,10))
                    .arg(QString::number(devpc->carInfo,10)).arg(QString::number(devpc->RTC,10));
            QString sql1 = QString("UPDATE dev_info i ,dev_attr a  set i.CARINFO = '%1',i.RTC = %2,i.ONLINETIME = %3 WHERE DEVID = (SELECT ROWID from dev_attr where DEVID = '%4')")
                    .arg(QString::number(devpc->carInfo,10)).arg(QString::number(devpc->RTC,10)).arg(QString::number(LastRTC,10)).arg(devpc->deviceID);
            //query.exec(sql);
            query.exec(sql1);
            s_OldData.append(sql);
            qDebug()<<"insert into geo_val database"<<endl;
        }else if(devpc->tabNo == BATTERYCHARGE)      //电量
        {
            //0:无数据     1:低电量       2:正常电量
            QString sql = QString("UPDATE dev_info i ,dev_attr a  set i.POWER = '%1',i.ONLINETIME = %2 WHERE i.ROWID = (SELECT ROWID from dev_attr where DEVID = '%3')")
                    .arg(QString::number(devpc->batteryAlarm,10)).arg(QString::number(LastRTC,10)).arg(devpc->deviceID);
            if(devpc->batteryAlarm == 1)
            {
              QString sql1 = QString("INSERT INTO dev_warn VALUES(NULL,'%1','%2',%3,'%4','');")
                       .arg(devpc->deviceID).arg(QString::number(devpc->batteryAlarm,10)).arg(QString::number(LastRTC,10).arg(username));
              s_OldData.append(sql1);
            }
            query.exec(sql);

        }else if(devpc->tabNo == DEVICEREQ)         //版本
        {
            QString sql = QString("UPDATE dev_para p, dev_attr a set p.VERSION = '%1' where w.ROWID =(SELECT ROWID from dev_attr where DEVID = '%2') ")
                    .arg(devpc->appVer)
                    .arg(devpc->deviceID);
            QString sql1 = QString("UPDATE dev_info i ,dev_attr a  set i.ONLINETIME = %1 WHERE i.ROWID = (SELECT ROWID from dev_attr where DEVID = '%2')")
                    .arg(QString::number(LastRTC,10)).arg(devpc->deviceID);
            query.exec(sql);
            query.exec(sql1);
        }else if(devpc->tabNo == HEARTBEAT)         //电量 上下限,保活
        {
            QString sql = QString("UPDATE dev_info i ,dev_attr a  set i.POWER = '%1',i.ONLINETIME = %2 WHERE i.ROWID = (SELECT ROWID from dev_attr where DEVID = '%3')")
                    .arg(QString::number(devpc->batteryAlarm,10)).arg(QString::number(LastRTC,10)).arg(devpc->deviceID);
            QString sql1 = QString("UPDATE dev_para p, dev_attr a set p.DELTATHUP = %1,p.DELTATHDOWN = %2 where w.ROWID =(SELECT ROWID from dev_attr where DEVID = '%3') ")
                    .arg(QString::number(devpc->deltaTHUp,10)).arg(QString::number(devpc->deltaTHDown,10))
                    .arg(devpc->deviceID);
            if(devpc->batteryAlarm == 1)
            {
                QString sql1 = QString("INSERT INTO dev_warn VALUES(NULL,'%1','%2',%3,'%4','');")
                         .arg(devpc->deviceID).arg(QString::number(devpc->batteryAlarm,10)).arg(QString::number(LastRTC,10).arg(username));
                s_OldData.append(sql1);
            }
            query.exec(sql);
            query.exec(sql1);
        }
    }
    //初始化时检测设备是否在线
//    if(onlineFlag)
//    {
//        QString sql = QString("UPDATE dev_info set CONNECT = 0 WHERE  (%1 - ONLINETIME) > %2 AND CONNECT = 1")
//                .arg(QString::number(LastRTC,10)).arg(QString::number(CHECKTIME,10));
//        QString sql1 = QString("UPDATE dev_info set CONNECT = 1 WHERE  (%1 - ONLINETIME) < %2 AND CONNECT = 0")
//                .arg(QString::number(LastRTC,10)).arg(QString::number(CHECKTIME,10));
//        query.exec(sql);
//        query.exec(sql1);
//        onlineFlag = false;
//    }

    query.exec("COMMIT");
    qDebug()<<"0x05 sqldatabase write spend time:"<<tmptime.elapsed()<<endl;

    emit SqlfinishedSignal();
    //发送到loghandler线程 (插入新数据到geo_val、dev_warn（低电量）)
    emit LogSignal(s_OldData);
}

int SqlThread::bcd2int(quint8 *bcd , int len)
{
    int dec = 0;
    int temp = 1000000;
    for(int i = 0; i < len; i++) {
        dec += ((int) ((bcd[i] & 0xf0) >> 4)*10 + (int) (bcd[i] & 0x0f))*temp;
        temp /= 100;
    }
    return dec;
}
