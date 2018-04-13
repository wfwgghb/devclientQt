#include "devdlg.h"
#include "utils.h"
#include "sqlwork.h"

devdlg::devdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DevDlg)
{
    ui->setupUi(this);
    utils = new Utils;
    db_connection = SqlWork::getConnectionByName(MainSqlName);
    templist<<"devid"<<"devpostion"<<"devarea"<<"tcc";
    //设置当前页
    currentPage = 1;

    //初始默认不能点击上一页
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    sqlfilter = QString("");
    initialTableView();

    m_accessManager = new QNetworkAccessManager();

    connect(m_accessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(finishedSlot(QNetworkReply*)));
    connect(this, SIGNAL(RegisterDeviceSignal()),
            this, SLOT(RegisterDevice()),Qt::QueuedConnection);
    regcode = "Cr14IfdSqtlzBZw0";
}


devdlg::~devdlg()
{

}

void devdlg::RecordQuery(int pageNum)
{



    int beginNum = (pageNum-1)*PageRecordCount +1;

    QString szQuery = QString("ROWID >= %1 and ROWID <= %2").arg(QString::number(beginNum)).arg(QString::number(pageNum*PageRecordCount));
    sqlfilter.append(szQuery);

    model->setFilter(sqlfilter);
    model->select();
    sqlfilter.clear();

}

//下一页
void devdlg::on_pushButton_6_clicked()
{

    currentPage++;
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage > totalPage)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
    ui->label_12->setText(label2Text);
    RecordQuery(currentPage);

}

//shangyiye
void devdlg::on_pushButton_7_clicked()
{

    currentPage--;
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage < 2)
    {
       ui->pushButton_7->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
    ui->label_12->setText(label2Text);
    RecordQuery(currentPage);

}
//转到--页
void devdlg::on_pushButton_8_clicked()
{

    QString goPageNum = ui->lineEdit_6->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("输入页码超过能显示的最大页数，请重新输入"));
       msg.exec();
    }else{

        ui->pushButton_7->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        if (currentPage == 1)
        {
         ui->pushButton_7->setEnabled(false);
        }
        if (currentPage == totalPage)
        {
         ui->pushButton_6->setEnabled(false);
        }

        QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
        ui->label_12->setText(label2Text);
        RecordQuery(currentPage);
     }

}

int devdlg::getSumPageNum()
{
    return (totalRecrodCount%PageRecordCount == 0)?(totalRecrodCount/PageRecordCount):(totalRecrodCount/PageRecordCount+1);
}

void devdlg::initialTableView()
{
    action_fillUserInfo = new QAction ( this);
    action_fillUserInfo ->setText ( QStringLiteral( "修改" ));

    action_fillUserInfo1 = new QAction ( this);
    action_fillUserInfo1 ->setText ( QStringLiteral( "添加" ));

    action_fillUserInfo2 = new QAction ( this);
    action_fillUserInfo2 ->setText ( QStringLiteral( "删除" ));

    popMenu = new QMenu( ui->tableView);
    popMenu->addAction(action_fillUserInfo);
    popMenu->addAction(action_fillUserInfo1);
    popMenu->addAction(action_fillUserInfo2);

    connect(action_fillUserInfo, &QAction::triggered, this, &devdlg::OpenSetttingDlg);
    connect(action_fillUserInfo1, &QAction::triggered, this, &devdlg::OpenSetttingDlg1);
    connect(action_fillUserInfo2, &QAction::triggered, this, &devdlg::deleDeviceSlot);

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
    model = new QSqlTableModel(0,db_connection);
    model->setTable("DEV_ATTR");
    model->select();

    //model->select(); //选取整个表的所有行
    model->setHeaderData(0, Qt::Horizontal, QStringLiteral("序列号"));
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("设备号"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("泊位号"));
    model->setHeaderData(3, Qt::Horizontal, QStringLiteral("区域"));
    model->setHeaderData(4, Qt::Horizontal, QStringLiteral("停车场"));

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);   //设置保存策略为手动提交
    ui->tableView->setModel(model);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    totalRecrodCount =  model->rowCount();

    totalPage = getSumPageNum();

    ui->pushButton_7->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage == totalPage)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage));
    ui->label_13->setText(label2Text);
    RecordQuery(currentPage);
    ui->tableView->show();

}

void devdlg::slotContextMenu(QPoint pos)
{
    QModelIndex index = ui->tableView->indexAt(pos);

    if (index.isValid())
    {
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
    }
}

void devdlg::OpenSetttingDlg()
{
    menudlg = new Dialog;
    //关联信号和槽函数
    connect(menudlg,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
    connect(this,SIGNAL(sendData(QString)),menudlg,SLOT(recvData(QString)));
    menudlg->setModal(true); //不论是模态或者非模态都可以正常传值
    menudlg->show();

    //传值到子窗口
    curRow = ui->tableView->currentIndex().row();

    for(int i = 1; i <5; i++ )
    {
        QString temp = model->data(model->index(curRow,i)).toString();
        oldtempList << temp;
        old_json_obj.insert(templist.at(i-1),temp);


    }
    QString temp = QString(QJsonDocument(old_json_obj).toJson(QJsonDocument::Compact));
    emit sendData(temp);
}

void devdlg::OpenSetttingDlg1()
{
    menudlg = new Dialog;
    //关联信号和槽函数
    connect(menudlg,SIGNAL(sendData(QString)),this,SLOT(receiveData1(QString)));

    menudlg->setModal(true); //不论是模态或者非模态都可以正常传值
    menudlg->show();


}
void devdlg::receiveData(QString recvdata)
{
    Loginfo loginfo;
    loginfo.CZLX = 2;
    loginfo.CZR = username;
    loginfo.YWLX = 0;
    loginfo.CZSJ = QDateTime::currentDateTime().toTime_t();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(recvdata.toLocal8Bit().data());
    if( jsonDocument.isNull() ){

    }
    QJsonObject jsonObject = jsonDocument.object();
    QString devid =  jsonObject.value(templist.at(0)).toString();
    QString pos = jsonObject.value(templist.at(1)).toString();
    QString area = jsonObject.value(templist.at(2)).toString();
    QString tcc = jsonObject.value(templist.at(3)).toString();

    QStringList newList;
    QJsonObject json;
    newList << devid <<pos << area <<tcc;
    for(int i = 0; i < 4; i++)
    {
        if(oldtempList.at(i) == newList.at(i))
        {
            old_json_obj.take(templist.at(i));
            jsonObject.take(templist.at(i));
            continue;

        }
        QString tempo = jsonObject.value(templist.at(i)).toString();
        //写入属性表中
        model->setData(model->index(curRow,i+1),tempo);
    }

    if (model->submitAll()) // 提交所有被修改的数据到数据库中
    {
        model->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        model->database().rollback();//回滚
        QMessageBox::warning(this, QStringLiteral("tableModel"),QStringLiteral("数据库错误: %1").arg(model->lastError().text()));
    }
    ui->tableView->show();
    json.insert("old", QJsonValue(old_json_obj));
    json.insert("new", QJsonValue(jsonObject));
    loginfo.CZNR = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));


//写入操作日志
    if(!SqlWork::LogInfoTable(&loginfo,1,db_connection))
    {
        //写入失败处理
    }

    emit DevattrChangedSignal();


}

void devdlg::receiveData1(QString recvdata)
{
    Loginfo loginfo;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(recvdata.toLocal8Bit().data());
    if( jsonDocument.isNull() ){

    }
    QJsonObject jsonObject = jsonDocument.object();

    QString devid =  jsonObject.value(templist.at(0)).toString();
    QString pos = jsonObject.value(templist.at(1)).toString();
    QString area = jsonObject.value(templist.at(2)).toString();
    QString tcc = jsonObject.value(templist.at(3)).toString();
    loginfo.CZLX = 0;
    loginfo.CZR = username;
    loginfo.YWLX = 0;
    loginfo.CZSJ = QDateTime::currentDateTime().toTime_t();
    //json

    QJsonObject json;
    json.insert("old", QString(""));
    json.insert("new", QJsonValue(jsonObject));
    loginfo.CZNR = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));

//    QStringList sqllist;

//    sqllist<<devid <<pos <<area<<tcc;

    QSqlQuery query(db_connection);
    QString sql = QString("INSERT INTO dev_attr VALUES(NULL,'%1','%2','%3','%4')")
            .arg(devid).arg(pos).arg(area).arg(tcc);

   if(!query.exec(sql)){

       QMessageBox::warning(this, QStringLiteral("tableModel"),QStringLiteral("数据库错误: %1").arg(query.lastError().text()));
       return;
    }
    RecordQuery(currentPage);
//    int rowNum = model->rowCount();//获得表的行数
//     qDebug()<<"rowNum"<<rowNum;
//     model->insertRow(rowNum); //添加一行
//     model->setData(model->index(rowNum,0),rowNum+1);
//     for(int i = 1; i < 5; i++)
//     {
//        model->setData(model->index(rowNum,i),sqllist.at(i-1));
//     }

//     if (model->submitAll()) // 提交所有被修改的数据到数据库中
//     {
//         model->database().commit(); //提交成功，事务将真正修改数据库数据
//     } else {
//         model->database().rollback();//回滚
//         QMessageBox::warning(this, QStringLiteral("tableModel"),QStringLiteral("数据库错误: %1").arg(model->lastError().text()));
//     }
//        ui->tableView->show();
//    //写入log数据库

    if(!SqlWork::LogInfoTable(&loginfo,1,db_connection))
    {
        //写入失败处理
    }

    QNetworkRequest *request = new QNetworkRequest();

    QString url = QString("http://api.js.cmcconenet.com/devices/status?devIds=%1,").arg(devid);
    //QString url = QString("http://api.heclouds.com/devices/datapoints?devIds=%1,").arg(devids);
    QByteArray key = QByteArray(PRODUCTKEY);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","api.js.cmcconenet.com");
    request -> setRawHeader("api-key",key);
    //request -> setRawHeader("Content-Length",cmd_size);
    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->get(*request);


    //emit AddNewDevSignal(devid);
}

void devdlg::finishedSlot(QNetworkReply *reply){

    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        qDebug()<<"Http request result is :"<<bytes;
        QJsonParseError jsonErr;
        QJsonDocument doc = QJsonDocument::fromJson(bytes, &jsonErr);
        if (!doc.isNull() && (jsonErr.error == QJsonParseError::NoError))
        {
            if(doc.isObject())
            {
                 QJsonObject obj = doc.object();
                 if(obj.contains("errno"))
                 {
                     QJsonValue value = obj.value("errno");
                     int error = value.toInt();
                     if(error == 3){
                         //设备不匹配
                         emit RegisterDeviceSignal();

                     }else if(error == 0)
                     {
                         if(obj.contains("data"))
                         {
                             QJsonValue val = obj.value("data");
                             if(val.isObject())
                             {
                                 QString device_id_created;
                                 QString key_created;
                                 QJsonObject obj1 = val.toObject();
                                 /**************创建设备****************/
                                 if(obj1.contains("device_id"))
                                 {
                                     QJsonValue value = obj1.value("device_id");
                                     if(value.isString())
                                     {
                                         device_id_created = value.toString();
                                         qDebug() << "device_id_created : " << device_id_created;
                                     }
                                 }
                             }
                         }else{
                             QMessageBox::warning(this, QStringLiteral("提示"),QStringLiteral("设备已存在！"));

                         }
                     }

                 }
            }
        }
    }
}

void devdlg::RegisterDevice(){

    QString data1;
    QDateTime T = QDateTime::currentDateTime();
    QString T_str = T.toString("yyyyMMddHHmmss");
    //获取URL
    const QString url = QString("http://183.207.215.140/register_de?register_code=%1").arg(regcode);
    //获取内容
    data1.append("{\"sn\":\"");
    data1.append(T_str);
    data1.append("\",\"title\":\"");
    data1.append(T_str);
    data1.append("\"}");
    //post
    QNetworkRequest *request = new QNetworkRequest();
    QByteArray strpost = data1.toLatin1();
    QByteArray bytesize = QByteArray::number(strpost.size(),10);
    request -> setUrl(QUrl(url));
    request -> setRawHeader("Host","183.207.215.140");
    request -> setRawHeader("Content-Length",bytesize);

    //QNetworkReply* reply = m_accessManager->post(*request,strpost);
    m_accessManager->post(*request,strpost);
}

void devdlg::UsernameSlot(QString userName)
{
    username = userName;
    qDebug()<<"username :"<<username;
}

//搜索
void devdlg::on_pushButton_clicked()
{

    QString devid = ui->lineEdit->text();
    QString devpostion = ui->comboBox_2->currentText();
    QString devarea = ui->comboBox_3->currentText();
    QString partnerid = ui->comboBox_4->currentText();
    if(!devid.isEmpty())
    {
        sqlfilter.append(QString("DEVID='%1' and ").arg(devid));
    }
    if(!devpostion.isEmpty())
    {
        sqlfilter.append(QString("DEVPOSTION='%1' and ").arg(devpostion));
    }
    if(!devarea.isEmpty())
    {
        sqlfilter.append(QString("DEVAREA='%1' and ").arg(devarea));
    }
    if(!partnerid.isEmpty())
    {
        sqlfilter.append(QString("TCC='%1' and ").arg(partnerid));
    }
    sqlfilter.append("0=0");
    //录入信息检查
    QSqlQuery query(db_connection);
    QString sql = QString("SELECT count(*) FROM dev_attr where %1")
            .arg(sqlfilter);
    query.exec(sql);
    query.next();

    totalRecrodCount =  query.value(0).toInt();

    totalPage = getSumPageNum();

    ui->pushButton_6->setEnabled(true);
    if (currentPage == totalPage)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage));
    ui->label_13->setText(label2Text);
    RecordQuery(currentPage);
    currentPage++;

}



//删除(未写完)
void devdlg::deleDeviceSlot()
{

    int curRow = ui->tableView->currentIndex().row();

    QJsonObject json_obj;

    for(int i = 1; i < 5; i++)
    {
        json_obj.insert(templist.at(i-1),model->data(model->index(curRow,i)).toString());
    }

    model->removeRow(curRow);   //删除一行   ,数据库记录未删

    //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),
                                  QMessageBox::Yes,QMessageBox::No);
//    if(ok == QMessageBox::No)
//    {
//        model->revertAll();//如果不删除，则撤销
//    }
//    else
//    {
//        model->submitAll(); //否则提交，在数据库中删除该行
//    }
//    //写入log表中
//    Loginfo loginfo;
//    loginfo.CZLX = 1;
//    loginfo.CZR = username;
//    loginfo.YWLX = 0;
//    loginfo.CZSJ = QDateTime::currentDateTime().toTime_t();
//    //json

//    QJsonObject json;
//    json.insert("old", QJsonValue(json_obj));
//    json.insert("new", QString(""));
//    loginfo.CZNR = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));

//    if(!SqlWork::LogInfoTable(&loginfo,1,db_connection))
//    {
//        //写入失败处理
//    }
}
//授权


void devdlg::DevAuth()
{
//    quint8 Frame = 0x00;
//    quint8 Length[4] = {0x00,0x00,0x00,0x89};
//    quint8 Command = 0x03;
//    quint8 syncflag= 0x01;
//    quint8 Starttime[6];
//    quint8 *id;
//    Utils::currentTime(Starttime);
//    id = Id;
//    QString ss = utils->md5(id,password);
//    QString SS = ss.toUpper();
//    //qDebug()<<"ss:"<<SS;
//    QByteArray Data = utils->AuthData(Id,SS,Coord,Starttime,AppVer,syncflag);
//    //授权信息
//    QByteArray block = utils->MsgForSend(Frame,Length,Command,Ver,Data);
//    quint8 *hexblock;
//    hexblock = (quint8 *)block.data();
    //qDebug()<<"block.size():"<<block.size();
//    for(int i = 0;i<block.size();i++)
//    {
//        //str.append("0x");
//        //str.append(QString("%1").arg(hexblock[i], 2, 16, QChar('0')));
//        //str.append(",");
//    }
//    ui->textEdit->setText(str);
//    emit SendSignal(block);
    //注册
    //checkLastData();
}


void devdlg::checkLastData()
{

}

