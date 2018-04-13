
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpconnection.h"
//#include "sqlwork.h"
#include "sqlthread.h"
#include "devdlg.h"
#include "querydlg.h"
#include "paradlg.h"
#include "searchdlg.h"
#include "myitemdelegate.h"
#include "loghandler.h"
#include "historydlg.h"
#include "devhttpclient.h"
#include "deviceinfomodel.h"
#include "requestlastdatahandler.h"
#include "httpclient.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(802,736);

    mylabel = new QLabel;
    mylabel->setText("");
    mylabel->setGeometry(rect().x()+10,rect().y()+670,110,23);
    mylabel->setParent(this);
    mylabel->close();


    ui->widget->show();
    ui->label_3->setText("");
    cursor = ui->textEdit->textCursor();
    cursor1 = ui->textEdit_2->textCursor();
    cursor2 = ui->textEdit_3->textCursor();
    cursor3 = ui->textEdit_4->textCursor();

    WindowSizeFlag = true;
    myitemdelegate = new MyItemDelegate;
    ui->tableView->setItemDelegate(new MyItemDelegate(ui->tableView));

    memtimer = new QTimer();
    connect(memtimer,SIGNAL(timeout()),this,SLOT(MemCleaning()));
    memtimer->start(5*1000*60*6);
//    DevicePc1 askData;
//    QVariant DataVar;
//    DataVar.setValue(askData);
//    qRegisterMetaType<QVariant>("QVariant"); //写在构造函数里

    //list1 = NULL;
    connect(this,SIGNAL(datebaseConnectionSignal(QString)),this,SLOT(SysInfoShow(QString)));

    utils = new Utils;
    //maintablemodel = new TableModel();
    mysqlquerymodel = new QSqlQueryModel();
    deviceinfomodel = new DeviceInfoModel();
    sqlwork = new SqlWork;
    if(!sqlwork->ConnSqlDatabase(MainSqlName))
    {
        //错误处理
        QString msg = QString("database connection failed!");
        emit datebaseConnectionSignal(msg);
    }
    db_connection = SqlWork::getConnectionByName(MainSqlName);

//    loghandler = new LogHandler();
//    sqlthread = new SqlThread();
//    comm_start = new TcpConnection();
    httpclient = new HttpClient();
    lastdatalog =new requestLastDataHandler();
    devhttpclient = new DevHttpClient();

    connect(lastdatalog,SIGNAL(HttpClientSignal(QByteArray)),httpclient,SLOT(MsgFromTcpSlot(QByteArray)));
    connect(httpclient,SIGNAL(Send2httpserverSignal(int)),this,SLOT(onSend2httpserverSignal(int)));

    connect(lastdatalog,SIGNAL(Send2DevhttpSignal(QByteArray,QString)),devhttpclient,SLOT(onSend2DevhttpSignal(QByteArray,QString)));
    connect(lastdatalog,SIGNAL(rtcSignal(QString,QString)),devhttpclient,SLOT(onsendrtcSignal(QString,QString)));

    connect(devhttpclient,SIGNAL(LastDataSendSignal(QString)),this,SLOT(onLastDataSignal(QString)));
    connect(devhttpclient,SIGNAL(ErrorHandlerSignal(int)),this,SLOT(onErrorHandlerSignal(int)));
    connect(this,SIGNAL(MsgForHttpSignal(QString)),devhttpclient,SLOT(onMsgForHttpSignal(QString)));

    connect(devhttpclient,SIGNAL(httpConnectSignal(QString)),this,SLOT(SysInfoShow(QString)));
    connect(lastdatalog,SIGNAL(httpConnectSignal(QString)),this,SLOT(SysInfoShow(QString)));
    connect(lastdatalog,SIGNAL(devOnlineSignal(QString,bool)),this,SLOT(ondevOnlineSignal(QString,bool)));
    connect(lastdatalog,SIGNAL(LowPowerSignal(QString)),this,SLOT(onLowPowerSignal(QString)));


//    //connect(comm_start,SIGNAL(ComdataSignal(QVariant)),this,SLOT(ComdataShow(QVariant)));
//    //connect(this,SIGNAL(SendUsernameSignal(QString)),comm_start,SLOT(UsernameSlot(QString)));
//    connect(comm_start,SIGNAL(errorSignal(int)),this,SLOT(errorHandler(int)));
//    connect(comm_start,SIGNAL(RcvmsgSignal(QString)),this,SLOT(DebugInfoShow(QString)));
//    connect(comm_start,SIGNAL(stopSocketSignal()),this,SLOT(stopSocketSlot()));
//    connect(this,SIGNAL(errorSignal(int)),this,SLOT(errorHandler(int)));
//    connect(this,SIGNAL(SendSignal(QByteArray)),comm_start,SLOT(SendMsg(QByteArray)));
//    connect(comm_start,SIGNAL(ConnectionSuccessSignal()),this,SLOT(afterConnectionSuccess()));

//    connect(comm_start,SIGNAL(SendDataSignal(QByteArray)),sqlthread,SLOT(onSendDataSignal(QByteArray)));
//    //connect(comm_start,SIGNAL(ComdataSignal(QVariant)),sqlthread,SLOT(WriteData2sqlbase(QVariant)));
//    connect(sqlthread,SIGNAL(SqlfinishedSignal()),this,SLOT(UpdateMaintableView()));

//    connect(this,SIGNAL(SendUsernameSignal(QString)),loghandler,SLOT(UsernameSlot(QString)));
//    connect(sqlthread,SIGNAL(LogSignal(QString)),loghandler,SLOT(onLogSignal(QString)));


    initMainTable();
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::initMainTable()
{
    //信息初始化


//   model->setEditStrategy(QSqlTableModel::OnManualSubmit);   //设置保存策略为手动提交
    areaid = ui->comboBox_2->currentText();
    tccid = ui->comboBox->currentText();
    berthl = QString("");
    berthh = QString("");

    sql_condition = QString("WHERE DEVAREA = '%1' AND TCC = '%2'").arg(areaid).arg(tccid);
    //设置当前页
    currentPage = 1;

    //初始默认不能点击上一页
    ui->pushButton_15->setEnabled(false);



    QSqlQuery query(db_connection);
    QString sql1 = QString("SELECT count(*) FROM dev_attr %1").arg(sql_condition);
    query.exec(sql1);
    query.next();
    totalRecrodCount =  query.value(0).toInt();
    totalPage = getSumPageNum();
    QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage));
    ui->label_15->setText(label2Text);
    deviceinfomodel->setModalDatas(&grid_data_list);
    RecordQuery(currentPage);

    QStringList header;
    header  << QStringLiteral("泊位号")<< QStringLiteral("停车状态") << QStringLiteral("开始时间") << QStringLiteral("电量状态") << QStringLiteral("在线状态")
                << QStringLiteral("设备号")<<QStringLiteral("配对号");
    deviceinfomodel->setHorizontalHeaderList(header);
    ui->tableView->setModel(deviceinfomodel);
    ui->tableView->show();
}

void MainWindow::filterSqlSlot(QString filtersql)
{
    //清空列表
//    rowlist.clear();
    //设置当前页
    currentPage = 1;
    //初始默认不能点击上一页

    qDebug()<<"recv send filter signal ";
    list1 = filtersql.split(',');
    if(list1.count() ==  1)
    {
     sql_condition = QString("WHERE DEVAREA = '%1' ").arg(list1.at(0));
     ui->label_7->setText(list1.at(0));
     ui->label_12->setText(QStringLiteral("所有"));
    }else if(list1.count() == 2)
    {
     sql_condition = QString("WHERE DEVAREA = '%1' and DEVPOSTION = '%2' ").arg(list1.at(0)).arg(list1.at(1));
     ui->label_7->setText(list1.at(0));
     ui->label_12->setText(list1.at(1));
    }

    QSqlQuery query(db_connection);
    QString sql1 = QString("SELECT count(*) FROM dev_attr where %1 ")
            .arg(sql_condition);
    query.exec(sql1);
    query.next();
    totalRecrodCount =  query.value(0).toInt();
    totalPage = getSumPageNum();
    RecordQuery(currentPage);
}

//
void MainWindow::UpdateMaintableView()
{

    if(!list1.isEmpty())
    {

        QString sql =  QString("SELECT a.DEVID,a.DEVPOSTION,i.CARINFO,i.RTC,i.POWER,i.CONNECT FROM dev_attr a LEFT JOIN dev_info i ON a.ROWID = i.ROWID %1 ")
                .arg(sql_condition);

        sql.append("limit ");
        int beginNum = (currentPage-1)*PageRecordCount;

        QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
        sql.append(szQuery);
        mysqlquerymodel->setQuery(sql,db_connection);

    }else
    {
        QString sql =  QString("SELECT a.DEVID,a.DEVPOSTION,i.CARINFO,i.RTC,i.POWER,i.CONNECT FROM dev_attr a LEFT JOIN dev_info i ON a.ROWID = i.ROWID limit ");

        int beginNum = (currentPage-1)*PageRecordCount;

        QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
        sql.append(szQuery);
        mysqlquerymodel->setQuery(sql,db_connection);
    }

}

void MainWindow::RecordQuery(int pageNum)
{

    //grid_data_list.clear();
    if(!devinfo.isEmpty())
    devinfo.clear();
    QSqlQuery query(db_connection);
    QString sql;
    QString sql1;

    if(berthh.isEmpty()&&berthl.isEmpty())
    {
        sql = QString("SELECT * from dev_attr  WHERE  DEVID IS NOT NULL and  DEVAREA = '%1' and  TCC = '%2' limit ")
            .arg(areaid).arg(tccid);
    }else
    {

    }
    int beginNum = (pageNum-1)*PageRecordCount;

    QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
    sql.append(szQuery);
    sql1.append(szQuery);
    if(!query.exec(sql))
    {
        qDebug()<<query.lastError().text();
        QMessageBox::warning(this,"warning","database  written is error !");
        return;
    }

    QString temp;
    while(query.next())
    {
        QString devid = query.value(1).toString();
        QString devpos = query.value(2).toString();
        devinfo.insert(devid,devpos);
        temp.append(devid);
        temp.append(",");


    }
    if(!devinfo.isEmpty())
    {
    emit MsgForHttpSignal(temp);
    }
//    query.clear();
//    if(!query.exec(sql1))
//    {
//        QMessageBox::warning(this,"warning","database  written is error !");
//        return;
//    }
//    devAttr devattr;
//    while(query.next())
//    {

//        devattr.devid = query.value(1).toString();
//        devattr.devpos = query.value(2).toString();
//        devattr.devarea = query.value(3).toString();
//        devattr.tcc = query.value(4).toString();
//        tempAttrList.insert(query.value(0).toInt(),devattr);
//        //qDebug()<<"tempattrlist:"<<tempAttrList.value(query.value(0).toInt()).devid;
//    }


}

//下一页
void MainWindow::on_pushButton_16_clicked()
{
    currentPage++;
    ui->pushButton_15->setEnabled(true);
    ui->pushButton_16->setEnabled(true);
    if (currentPage >= totalPage)
    {
       ui->pushButton_16->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
    ui->label_14->setText(label2Text);

    RecordQuery(currentPage);
}

//shangyiye
void MainWindow::on_pushButton_15_clicked()
{
    currentPage--;
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    if (currentPage == 1)
    {
       ui->pushButton_15->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
    ui->label_14->setText(label2Text);
    RecordQuery(currentPage);
}
//转到--页
void MainWindow::on_pushButton_14_clicked()
{
    QString goPageNum = ui->lineEdit_8->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("输入页码超过能显示的最大页数，请重新输入"));
       msg.exec();
    }else{

        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        if (currentPage == 1)
        {
         ui->pushButton_15->setEnabled(false);
        }
        if (currentPage == totalPage)
        {
         ui->pushButton_16->setEnabled(false);
        }

        QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
        ui->label_14->setText(label2Text);
        RecordQuery(currentPage);
     }

}
int MainWindow::tableRowsNum()
{

//    QString position = ui->lineEdit->text();
//    QString area = ui->lineEdit_2->text();

//    if(!area.isEmpty())
//    {
//         QSqlQuery query(db_connection);
//         QString sql = QString("SELECT count(*)  FROM dev_warn i  LEFT JOIN dev_attr a on (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL AND i.DEVID = a.DEVID ")
//                 .arg(area);
//         query.exec(sql);
//         query.next();

//        return query.value(0).toInt();
//    }
    return 0;
}

int MainWindow::getSumPageNum()
{
    return (totalRecrodCount%PageRecordCount == 0)?(totalRecrodCount/PageRecordCount):(totalRecrodCount/PageRecordCount+1);
}

//************************************************************************************************************

//登录
void MainWindow::on_pushButton_17_clicked()
{
    //获取
    username = ui->lineEdit->text();
    pwd = ui->lineEdit_2->text();

    if(username.isEmpty()||pwd.isEmpty())
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("用户名或密码不能为空！"));
        msg.exec();
        return;
    }
    QSqlQuery query(db_connection);
    QString sql = QString("select * from user_info where USERNAME='%1' AND PWD='%2'").arg(username).arg(pwd);
    query.exec(sql);
    if(query.next())
    {
        ui->widget->close();
        ui->label_16->close();
        ui->label_17->close();
        ui->lineEdit->close();
        ui->lineEdit_2->close();
        ui->pushButton_17->close();
        QString text = QString(QStringLiteral("当前操作员:%1")).arg(username);
        mylabel->setText(text);
        mylabel->show();
        emit SendUsernameSignal(username);

    }else
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("用户名或密码错误！"));
        msg.exec();
        return;
    }


}

//设备属性管理
void MainWindow::on_pushButton_8_clicked()
{

    AddDevDlg = new devdlg;

    connect(this,SIGNAL(SendUsernameSignal(QString)),AddDevDlg,SLOT(UsernameSlot(QString)));
    connect(AddDevDlg,SIGNAL(sendParaSignal(QString)),devhttpclient,SLOT(onsendParaSignal(QString)));
    connect(AddDevDlg,SIGNAL(DevattrChangedSignal()),lastdatalog,SLOT(DevattrChangedSlot()));

    AddDevDlg->show();
    emit SendUsernameSignal(username);
}

//调试信息
void MainWindow::on_pushButton_9_clicked()
{
    if(WindowSizeFlag)
    {
        this->setFixedSize(1363,736);
        WindowSizeFlag = false;
    }else
    {
       this->setFixedSize(802,736);
        WindowSizeFlag = true;
    }
}

//查看设备状态
void MainWindow::on_pushButton_10_clicked()
{

    queryDevDlg = new querydlg;

    //connect(queryDevDlg,SIGNAL(SendSignal(QByteArray)),comm_start,SLOT(SendMsg(QByteArray)));
    queryDevDlg->show();

}

//参数修改界面
void MainWindow::on_pushButton_11_clicked()
{
    writeparadlg = new paradlg;

     connect(this,SIGNAL(SendUsernameSignal(QString)),writeparadlg,SLOT(UsernameSlot(QString)));
//    connect(writeparadlg,SIGNAL(sendParaSignal(QByteArray)),comm_start,SLOT(SendMsg(QByteArray)));
//    connect(comm_start,SIGNAL(ParaSettingSignal(quint8)),writeparadlg,SLOT(ParaSettingSlot(quint8)));
     connect(writeparadlg,SIGNAL(sendParaSignal(QString)),lastdatalog,SLOT(onsendParaSignal(QString)));
     connect(lastdatalog,SIGNAL(paraSuccSignal()),writeparadlg,SLOT(onparaSuccSignal()));
    connect(writeparadlg,SIGNAL(uploadfileNameSignal(QString)),lastdatalog,SLOT(onUploadfileNameSignal(QString)));
    connect(writeparadlg,SIGNAL(StartUploadFileSignal()),lastdatalog,SLOT(onStartUploadFileSignal()));

    writeparadlg->show();
    emit SendUsernameSignal(username);
}

void MainWindow::sqlFilterHandler()
{
    QString areaid = ui->comboBox_2->currentText();
    QString tcc = ui->comboBox->currentText();
    QString pos0 = ui->comboBox_3->currentText();
    QString pos1 = ui->comboBox_4->currentText();

    QJsonObject json_obj;
    json_obj.insert("areaid",areaid);
    json_obj.insert("tcc",tcc);


    QString temp;
    if((!pos0.isEmpty())&&(!pos1.isEmpty()))
    {
        json_obj.insert("pos0",pos0);
        json_obj.insert("pos1",pos1);
        temp = QString(QJsonDocument(json_obj).toJson(QJsonDocument::Compact));
        emit SendSqlfilterSignal(temp);
    }else if(pos0.isEmpty()&&pos1.isEmpty())
    {
         temp = QString(QJsonDocument(json_obj).toJson(QJsonDocument::Compact));
        emit SendSqlfilterSignal(temp);
    }else
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("请填写完全！"));
        msg.exec();
        return;
    }
}

//搜索设备信息
void MainWindow::on_pushButton_12_clicked()
{
//    sedlg = new SearchDlg;

//    connect(sedlg,SIGNAL(filterSignal(QString)),this,SLOT(filterSqlSlot(QString)));

//    sedlg->show();
    areaid = ui->comboBox_2->currentText();
    tccid = ui->comboBox->currentText();
    berthl = ui->comboBox_3->currentText();
    berthh = ui->comboBox_4->currentText();
        //sqlFilterHandler();

    sql_condition = QString("WHERE DEVAREA = '%1' AND TCC = '%2'").arg(areaid).arg(tccid);
    //设置当前页
    currentPage = 1;

    //初始默认不能点击上一页
    ui->pushButton_15->setEnabled(false);



    QSqlQuery query(db_connection);
    QString sql1 = QString("SELECT count(*) FROM dev_attr %1").arg(sql_condition);
    query.exec(sql1);
    query.next();
    totalRecrodCount =  query.value(0).toInt();
    totalPage = getSumPageNum();
    QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage));
    ui->label_15->setText(label2Text);
    RecordQuery(currentPage);

}

void MainWindow::on_pushButton_13_clicked()
{
    hisdlg = new HistoryDlg;

    hisdlg->show();
}
//发送授权信息
void MainWindow::on_pushButton_3_clicked()
{


}

//网络连接成功后，执行以下操作
void MainWindow::afterConnectionSuccess()
{
    //显示网络连接成功标志
    ui->label_3->setText(QStringLiteral("网络连接成功！"));

    //开始授权
    //DevAuth();

}
void MainWindow:: stopSocketSlot()
{
    //显示网络连接失败标志
    ui->label_3->setText(QStringLiteral("网络连接断开..."));

}

void MainWindow::DevAuth()
{

}

//最新数据显示
void MainWindow::onLastDataSignal(QString str)
{
    if(devinfo.isEmpty()){
        return;
    }

    grid_data_list.clear();
//    s_lastdata.append(str);
//    s_lastdata.append("\r\n");
//    ui->textEdit_3->setText(s_lastdata);
//    cursor2.movePosition(QTextCursor::End);
//    ui->textEdit_3->setTextCursor(cursor2);

    QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toLocal8Bit().data());
    if( jsonDocument.isNull() ){
        return;
    }
    QJsonArray jsonarray = jsonDocument.array();
    //qDebug()<<"jsonObject.size():"<<jsonObject.size();
    QMap<QString ,QString>::iterator mi;
    QMap<QString ,QString>::iterator it;
    QString connect;



        for(int i = 0 ; i < jsonarray.size(); i++)
        {
            QJsonObject jsonObject = jsonarray.at(i).toObject();
            QString devid =  jsonObject.value("dev_id").toString();
            QString text = jsonObject.value("value").toString();
            mi = devinfo.find(devid);
            QString devpos = mi.value();

            it = devconn.find(devid);
            if(it!=devconn.end()){
                connect = it.value();
            }else{
                connect = QString("1");
            }

            //qDebug()<<"devid and text:"<<devpos<<text<<devid;
            //text 解析
            QStringList info = ParseText(text,devpos,connect,devid);

            grid_data_list.append(info);
        }


    deviceinfomodel->refrushModel();
    //qDebug()<<"deviceinfomodel->columnCount()"<<deviceinfomodel->columnCount();


}

void MainWindow::ondevOnlineSignal(QString devid,bool online)
{
    QMap<QString ,QString>::iterator mi;

    mi = devinfo.find(devid);
    if(mi!=devinfo.end()){
        if(online){
             devconn.insert(devid,QString("1"));
        }else{
             devconn.insert(devid,QString("0"));

             QString msg2 = QString("device id %1 is offline").arg(devid);
             msgShow(msg2);
        }
        quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
        QSqlQuery query(db_connection);
        QString sql = QString("INSERT INTO dev_warn VALUES(NULL,'%1','%2',%3,'%4','');")
                .arg(devid).arg("2").arg(QString::number(LastRTC,10).arg(username));
        query.exec(sql);
       // QStringList data_list = grid_data_list.at();

    }

}
void MainWindow::onLowPowerSignal(QString dev_id)
{
    QString msg = QString(QStringLiteral("设备id:%1,电量低警告！")).arg(dev_id);
    msgShow(msg);

    quint32 LastRTC = QDateTime::currentDateTime().toTime_t();
    QSqlQuery query(db_connection);
    QString sql = QString("INSERT INTO dev_warn VALUES(NULL,'%1','%2',%3,'%4','');")
            .arg(dev_id).arg("1").arg(QString::number(LastRTC,10).arg(username));
    query.exec(sql);

}

void MainWindow::onSend2httpserverSignal(int result)
{
    QString msg;
    if(result != 0)
    {
        //http发送失败处理
         msg = QString(QStringLiteral("上传信息到平台，失败！"));

    }else {
        //http发送失败处理
         msg = QString(QStringLiteral("上传信息到平台，成功！"));

    }
    msgShow(msg);
}

QStringList MainWindow::ParseText(QString text,QString devpos,QString connect,QString devid)
{

    QString pairid = text.mid(16,2);
//    QString initx = text.mid(20,4);
//    QString inity = text.mid(24,4);
//    QString initz = text.mid(28,4);
//    QString currx = text.mid(32,4);
//    QString curry = text.mid(36,4);
//    QString currz = text.mid(38,4);


    QString carinfo = text.mid(42,2);
    QString rtc = text.mid(44,8);
    QString power = text.mid(52,2);
    //QString connect = QString("1");
    QStringList data_list;
    //qDebug()<<"devid and text:"<<devpos<<carinfo<<rtc<<power<<connect<<devid<<pairid;
    data_list<<devpos<<carinfo<<rtc<<power<<connect<<devid<<pairid;

    return data_list;

}

quint16 MainWindow::quint8Toquint16(quint8 *delta,int len)
{
    QByteArray deltabyte = qint8ToQbytearray(delta,len);
    quint16 re;
    QDataStream in(&deltabyte,QIODevice::ReadWrite);
    in >>re;
    return re;
}

void MainWindow::SysInfoShow(QString msg)
{
    msgShow(msg);
}

void MainWindow::msgShow(QString& msg)
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    msg1.append(time);
    msg1.append(":");
    msg1.append(msg);
    msg1.append("\r\n");
    ui->textEdit_4->setText(msg1);
    cursor3.movePosition(QTextCursor::End);
    ui->textEdit_4->setTextCursor(cursor3);
}

void MainWindow::MemCleaning()
{
    //msg1.clear();

}
void MainWindow::DebugInfoShow(QString msg)
{
        rcvmsg.append(msg);
        ui->textEdit_2->setText(rcvmsg);
        cursor1.movePosition(QTextCursor::End);
        ui->textEdit_2->setTextCursor(cursor1);
        //ui->label_3->setText(QStringLiteral("授权成功！"));
}


quint8 MainWindow::bytesToInt(QByteArray bytes)
{

    quint8 data = bytes[0] & 0xff;
    return data;
}
void MainWindow::onErrorHandlerSignal(int errorno)
{
        httpError e = (httpError) errorno;
        switch(e)
        {
            case succ :
            {
                //s_lastdata.append("recvice data error!\r\n");

            }break;
            case nosucc:
            {
//                s_lastdata.append("recvice data error!\r\n");
//                ui->textEdit_3->setText(str);
//                cursor2.movePosition(QTextCursor::End);
//                ui->textEdit_3->setTextCursor(cursor2);
            }break;
        default:
            break;

        }
}

void MainWindow::errorHandler(int flag)
{
    ErrorFlag ef =  (ErrorFlag) flag;

    switch(ef)
    {
        case dataError :
        {
            ErrorHandler.append("recvice data error!");

        }break;
        case writenError:
        {
            ErrorHandler.append("PC writen data error！");

        }break;
    default:
        break;

    }
}
