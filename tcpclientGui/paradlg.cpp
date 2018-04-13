#include "paradlg.h"
#include "sqlwork.h"
#include <QDebug>


paradlg::paradlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaDlg)
{
    ui->setupUi(this);

    uploadfileFlag = 0;
    utils = new Utils;

    comboDelegate = new ComboDelegate;
    spinDelegate  = new spindelegate;
    //checkDelegate  = new checkdelegate;
    db_connection = SqlWork::getConnectionByName(MainSqlName);
    initTableWidget();
    initSettingPara();
    //���õ�ǰҳ
    currentPage = 1;

    //��ʼĬ�ϲ��ܵ����һҳ
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_5->setEnabled(false);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(getFileName()));

}

paradlg::~paradlg()
{

}

void paradlg::UsernameSlot(QString userName)
{
    username = userName;
}

void paradlg::initTableWidget()
{

//    ui->lineEdit->setText("0");
//    ui->comboBox->setText("0");
//    ui->lineEdit_3->setText("a");
    paramodel = new ParaModel();

//    QSqlQuery query(total_sql);
//    model->setQuery(query);
//    model->setTable("DEV_PARA");
//    model->select(); //ѡȡ�������������


    QStringList headlist;
    headlist<<QStringLiteral("���к�")<<QStringLiteral("��λ��")<<QStringLiteral("������")<<QStringLiteral("������")
           <<QStringLiteral("����ֵ����")<<QStringLiteral("����/����")<<QStringLiteral("�汾")<<QStringLiteral("ѡ��");
    paramodel->setHorizontalHeaderList(headlist);
//   model->setEditStrategy(QSqlTableModel::OnManualSubmit);   //���ñ������Ϊ�ֶ��ύ
     paramodel->setModalDatas(&grid_data_list);

     ui->tableView->setItemDelegateForColumn(2, spinDelegate);
     ui->tableView->setItemDelegateForColumn(3, spinDelegate);
     ui->tableView->setItemDelegateForColumn(5, comboDelegate);
     //ui->tableView->setItemDelegateForColumn(6, checkDelegate);
     paramodel->insertColumn(7);

     ui->tableView->setItemDelegate(new mycheckDelegate(ui->tableView));      // 4\7
    ui->tableView->setModel(paramodel);

     ui->tableView->show();
        paramodel->refrushModel();
}

//������������
void paradlg::on_pushButton_3_clicked()
{

    sqlfilter.clear();
    //���õ�ǰҳ
    currentPage = 1;

    //��ʼĬ�ϲ��ܵ����һҳ
    ui->pushButton_6->setEnabled(false);
 //   ui->pushButton_5->setEnabled(false);

    tcc = ui->comboBox->currentText();
    Area = ui->comboBox_2->currentText();
    postion = ui->comboBox_3->currentText();
    if(!postion.isEmpty())
    {
        sqlfilter.append(QString("DEVPOSTION='%1' and ").arg(postion));
    }
    if(!Area.isEmpty())
    {
        sqlfilter.append(QString("DEVAREA='%1' and ").arg(Area));
    }
    if(!tcc.isEmpty())
    {
        sqlfilter.append(QString("TCC='%1' and ").arg(tcc));
    }
    sqlfilter.append("0 = 0 ");

    QSqlQuery query(db_connection);
    QString sql = QString("SELECT count(*) FROM dev_attr where %1 ")
            .arg(sqlfilter);

    query.exec(sql);
    query.next();

    totalRecrodCount =  query.value(0).toInt();

    totalPage = getSumPageNum();

    ui->pushButton_6->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    if (currentPage == totalPage)
    {
        ui->pushButton_5->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��%1ҳ")).arg(QString::number(totalPage));
    ui->label_12->setText(label2Text);
    RecordQuery(currentPage);

     currentPage++;

}


void paradlg::RecordQuery(int pageNum)
{
    grid_data_list.clear();
    tempAttrList.clear();
    QSqlQuery query(db_connection);
    QString sql;
    QString sql1;

    if(postion.isEmpty())
    {
        sql =  QString("SELECT a.ROWID,a.DEVPOSTION,i.DELTATHUP,i.DELTATHDOWN,i.UPDATINITVAL,i.APPDOWNLOAD,i.VERSION  FROM dev_attr a LEFT JOIN dev_para i ON a.ROWID = i.ROWID WHERE a.DEVID IS NOT NULL and a.DEVAREA = '%1' and a.tcc = '%2' limit ")
            .arg(Area).arg(tcc);

        sql1 = QString("SELECT * from dev_attr  WHERE  DEVID IS NOT NULL and  DEVAREA = '%1' and  TCC = '%2' limit ")
            .arg(Area).arg(tcc);
    }else
    {
        sql =  QString("SELECT a.ROWID,a.DEVPOSTION,i.DELTATHUP,i.DELTATHDOWN,i.UPDATINITVAL,i.APPDOWNLOAD,i.VERSION FROM dev_attr a LEFT JOIN dev_para i ON a.ROWID = i.ROWID WHERE a.DEVID IS NOT NULL and a.DEVAREA = '%1' and a.tcc = '%2' AND a.DEVPOSTION = '%3' limit ")
            .arg(Area).arg(tcc).arg(postion);

        sql1 = QString("SELECT * from dev_attr  WHERE  DEVID IS NOT NULL and  DEVAREA = '%1' and  TCC = '%2' AND a.DEVPOSTION = '%3' limit ")
            .arg(Area).arg(tcc).arg(postion);
    }
    int beginNum = (pageNum-1)*PageRecordCount;

    QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
    sql.append(szQuery);
    sql1.append(szQuery);
    if(!query.exec(sql))
    {
        QMessageBox::warning(this,"warning","database  written is error !");
        return;
    }

    int i = 0;

    while(query.next())
    {
        QStringList data_list;
        for(int j = 0; j < 7; j++)
        {
            data_list.append(query.value(j).toString());
        }
        data_list.append("0");
        grid_data_list.append(data_list);
        i++;
    }
    query.clear();
    if(!query.exec(sql1))
    {
        QMessageBox::warning(this,"warning","database  written is error !");
        return;
    }
    devAttr devattr;
    while(query.next())
    {

        devattr.devid = query.value(1).toString();
        devattr.devpos = query.value(2).toString();
        devattr.devarea = query.value(3).toString();
        devattr.tcc = query.value(4).toString();
        tempAttrList.insert(query.value(0).toInt(),devattr);
        //qDebug()<<"tempattrlist:"<<tempAttrList.value(query.value(0).toInt()).devid;
    }

    paramodel->refrushModel();

}

//��һҳ
void paradlg::on_pushButton_5_clicked()
{
    grid_data_list.clear();
    currentPage++;
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    if (currentPage > totalPage)
    {
       ui->pushButton_5->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
    ui->label_11->setText(label2Text);
    RecordQuery(currentPage);

}

//shangyiye
void paradlg::on_pushButton_6_clicked()
{
    grid_data_list.clear();
    currentPage--;
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage < 2)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
    ui->label_11->setText(label2Text);
    RecordQuery(currentPage);

}
//ת��--ҳ
void paradlg::on_pushButton_4_clicked()
{
    grid_data_list.clear();
    QString goPageNum = ui->lineEdit_7->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("����ҳ�볬������ʾ�����ҳ��������������"));
       msg.exec();
    }else{

        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        if (currentPage == 1)
        {
         ui->pushButton_6->setEnabled(false);
        }
        if (currentPage == totalPage)
        {
         ui->pushButton_5->setEnabled(false);
        }

        QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
        ui->label_11->setText(label2Text);
        RecordQuery(currentPage);
     }

}

int paradlg::tableRowsNum()
{

//    QString position = ui->lineEdit->text();
//    QString area = ui->comboBox->text();

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

int paradlg::getSumPageNum()
{
    return (totalRecrodCount%PageRecordCount == 0)?(totalRecrodCount/PageRecordCount):(totalRecrodCount/PageRecordCount+1);
}

void paradlg::initSettingPara()
{
    quint8 *temp;
    Frame = 0x01; //ͬ������
    Command = 0x04;
    Length = 23; //(msg:"")
    flag = 1;
    tagcount = 1;

    //inittags()
    tagid = 3;
    type = 10;
    for(int i= 0;i<5;i++)
    {
        settingpara.header[i] = 0xfe;
    }
    settingpara.tabNo = 0x02;
    temp = tableLengthCalc(settingpara);
    settingpara.tabLengthH = temp[1];
    settingpara.tabLengthL = temp[0];
    settingpara.updateFlag = 0;

    delete [] temp;

}

quint8 *paradlg::tableLengthCalc(SettingParaSimp para)
{
    quint8 *temp = new quint8[2];
    int length =   sizeof(para.header)+sizeof(para.tabNo)
            +sizeof(para.crc)+sizeof(para.deltaTHDown)
            +sizeof(para.deltaTHUp)+sizeof(para.tabLengthH)
            +sizeof(para.tabLengthL)+sizeof(para.reserve)
            +sizeof(para.updateEnvValue)+sizeof(para.updateFlag);
    temp[0] = length&0x00ff;//ȡ��8λ
    temp[1] = length&0xff00;//ȡ��8λ
    return temp;
}


void paradlg::on_pushButton_clicked()
{
    QHash<int ,devAttr>::iterator mi;
    quint16 count = 0;
    tableHeader tabhead;
    tabhead.frame = 0x00;
    tabhead.command = 0x04;
    tabhead.version = 0x10000000;
    QByteArray block;
    //ѡ���豸�����ε� ָ���豸
    int row = paramodel->rowCount();
    int col = paramodel->columnCount();

//    qDebug()<<"row count :"<<row;
//    qDebug()<<"col count :"<<col;

    QSqlQuery query(db_connection);
    query.exec("START TRANSACTION");
    QJsonArray json_array;
    //int count = 0;
    for(int i = 0;i<row;i++)
    {
        bool flag = paramodel->data(paramodel->index(i,7),Qt::DisplayRole).toBool();


        qDebug()<<"check data :"<<flag;
        if(flag == 1) //ѡ���򴫲ε�
        {
            int ROWID = paramodel->data(paramodel->index(i,0),Qt::DisplayRole).toInt();

            QString updataflag = paramodel->data(paramodel->index(i,5),Qt::DisplayRole).toString();
            QString s_deltaup = paramodel->data(paramodel->index(i,2),Qt::DisplayRole).toString();
            QString s_deltadown = paramodel->data(paramodel->index(i,3),Qt::DisplayRole).toString();
            bool s_setinit = paramodel->data(paramodel->index(i,4),Qt::DisplayRole).toBool();

            quint16 deltaup =s_deltaup.toUShort(Q_NULLPTR,10);
            quint16 deltadown =s_deltadown.toUShort(Q_NULLPTR,10);
            quint16 setinit = (quint16)s_setinit;
            qDebug()<<"s_deltaup:"<<deltaup;
            if(deltaup <= deltadown)
            {
                QMessageBox::warning(this,"warning",QStringLiteral("��������ֵ�����涨��Χ!"));
                return;
            }
            //Ŀǰ��֧�ָ��¡����ز������书��
            if(updataflag == "download")
            {
                 settingpara.updateFlag = 1;
                 uploadfileFlag = 1;
            }else if(updataflag == "update")
            {
                 settingpara.updateFlag = 2;
            }else if(updataflag == "update/download")
            {
                 settingpara.updateFlag = 3;
            }else
            {
                 settingpara.updateFlag = 0;
            }

            //д�����ݿ�
            QString sql = QString("UPDATE dev_para set APPDOWNLOAD = '%1',DELTATHUP=%2,DELTATHDOWN=%3 ,UPDATINITVAL = '%4' WHERE ROWID = %5 ")
                    .arg(updataflag).arg(s_deltaup).arg(s_deltadown).arg(s_setinit).arg(QString::number(ROWID));
            if(!query.exec(sql))
            {
                qDebug()<<query.lastError().text();
                qDebug()<<"upate database is error!"<<endl;
            }

            mi = tempAttrList.find(ROWID);
            settingpara.deviceID = mi.value().devid;


            QJsonObject json_obj;
            json_obj.insert("devid",settingpara.deviceID);
            json_obj.insert("appdownload",settingpara.updateFlag);
            json_obj.insert("deltaup",deltaup);
            json_obj.insert("deltadown",deltadown);
            json_obj.insert("setinit",setinit);
            json_array.insert(count,QJsonValue(json_obj));
            count++;

            Loginfo loginfo; //д��log����
            loginfo.CZLX = 2;
            loginfo.CZR = username;
            loginfo.YWLX = 1;
            loginfo.CZSJ = QDateTime::currentDateTime().toTime_t();
            //json

            QJsonObject json;
            json.insert("old", QString(""));
            json.insert("new", QJsonValue(json_obj));
            loginfo.CZNR = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));

            if(!SqlWork::LogInfoTable(&loginfo,1,db_connection))
            {
                //д��ʧ�ܴ���
            }

        }
    }
    query.exec("COMMIT");   
    //����Э�鵽http�߳�
    QJsonDocument document;
    document.setArray(json_array);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    ui->label_13->setText(QStringLiteral("����������..."));
    emit sendParaSignal(json_str);
}

void paradlg::getFileName(){
    QString filename;
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(QStringLiteral("ѡ�������ļ�"));
    fileDialog->setDirectory(".");
    //fileDialog->setFilter(tr("Image Files(*.jpg *.png)"));
    //fileDialog-> setFileMode( QFileDialog::DirectoryOnly );
    if(fileDialog->exec() == QDialog::Accepted) {
             filename = fileDialog->selectedFiles()[0];
           // QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
    } else {
            QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("δѡ���κα���·����"));
    }
    uploadfilepath =filename;
    ui->lineEdit_4->setText(filename);
    emit uploadfileNameSignal(filename);
}

void paradlg::ParaSettingSlot(quint8 data)
{
    //
    if(data == 0)
    {
    ui->label_13->setText(QStringLiteral("�������óɹ���"));

    }else
    {
        ui->label_13->setText(QStringLiteral("��������ʧ�ܣ�"));
    }
}


void paradlg::onparaSuccSignal()
{
    ui->label_13->setText(QStringLiteral("�������óɹ���"));
    if(!uploadfilepath.isNull()&&!uploadfilepath.isEmpty()){

        if(uploadfileFlag == 1){

            emit StartUploadFileSignal();
            ui->label_13->setText(QStringLiteral("��ʼ�ϴ�BIN�ļ�..."));
        }

    }
}



