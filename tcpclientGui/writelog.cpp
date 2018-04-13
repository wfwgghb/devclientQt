#include "WriteLog.h"
//#include "globaldata.h"
#include  <qdebug.h>
#include <qtextcodec.h>
#include <QMutex>
//记录当前时间
void WriteLogFile(QString filename ,int flag,QString msg)
{

     QString text;
//	 QString timenow=currenttime();
    // QTextCharFormat chfmt;
        //设置状态信息标签
    switch (flag) {
    case 1:
        text = "INFO:";
        break;
    case 2:
        text = "WARN:";
       // chfmt.setForeground(QBrush(Qt::yellow));
        break;
    case 3:
        text = "ERROR:";
       // chfmt.setForeground(QBrush(Qt::red));
        break;
    default:
        break;
    }

     text.append("[");
     //在标签之后附加状态信息
 //   text.append(timenow);
    text.append("]");
    text.append(msg);
    QFile writefile("D:\\datalog.txt");
    if(writefile.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream out(&writefile);

        out<<text<<endl;
        writefile.close();
    }

}

void createLogFile()
{
    createlogdir("Log");
    QString timenow=currentdate();
    QString LogFile="Log/"+timenow+".txt";
    QFile file(LogFile);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        //qDebug()<<"Can't open the file!"<<endl;
    }
    file.close();
}

void createlogdir(QString logdir)
{
    QDir *temp = new QDir;
    bool exist = temp->exists(logdir);
    if(!exist)
    {
        bool ok = temp->mkdir(logdir);
        if( !ok )
        {
            qDebug("create file failed");
        }
    }
}

QString  currentdate()
{
     QDateTime dt;
     QTime time;
     QDate date;
    // dt.setTime(time.currentTime());
     dt.setDate(date.currentDate());
     QString currenttime = dt.toString("yyyy-MM-dd");
     return currenttime;
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();
    //QTextCodec *code=QTextCodec::codecForName("GBK");//本人采用的是UTF8格式显示的


    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Info:");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    /*case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;*/
    /*case QtInfoMsg:
        strMsg = QString("Info:");
        break;*/
    case QtFatalMsg:
        strMsg = QString("Error:");
        break;
    }
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("%1%2,DateTime:%3,%4").arg(strMsg)
            .arg(msg).arg(strDateTime).arg(context_info);

    // 输出信息至文件中（读写、追加形式）
    createlogdir("ClientLog");
    QString timenow=currentdate();
    QString LogFile="ClientLog/"+timenow+".txt";

    QFile file(LogFile);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    //stream.setCodec(code);//输出流的设置
    stream << strMessage << "\r\n";
    file.flush();
    file.close();
    //QDIRINFO


//    if(globaldata::oldLogFile!=LogFile)
//    {
//        globaldata::LogCount++;
//    }
//    //30天文件保存设置
//    if(globaldata::LogCount>30)
//    {
//         QDir dir;
//         dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
//         dir.setSorting(QDir::Size | QDir::Reversed);

//         QFileInfoList list = dir.entryInfoList();
//         QMap<QString, int> map;
//         for (int i = 0; i < list.size(); ++i)
//         {
//             QFileInfo fileInfo = list.at(i);
//             map.insert(fileInfo.fileName(),i);
//         }
//         QList<QString> kList = map.keys();
//         QString msg1="delete Log file:"+kList[0];
//         qDebug()<<msg1;
//         //删除文件
//         QFile::remove(kList[1]);

//    }
//    globaldata::oldLogFile=LogFile;
    // 解锁
    mutex.unlock();
}
