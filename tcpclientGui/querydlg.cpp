#include "querydlg.h"
#include "utils.h"
#include "sqlwork.h"
#include <QMessageBox>

querydlg::querydlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDLg)
{
    ui->setupUi(this);

    utils = new Utils;
    db_connection = SqlWork::getConnectionByName(MainSqlName);

    Querymodel = new QSqlQueryModel();
    Querymodel1 = new QSqlQueryModel();
    //���õ�ǰҳ
    currentPage = 1;

    //��ʼĬ�ϲ��ܵ����һҳ
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    //���õ�ǰҳ
    currentPage1 = 1;

    //��ʼĬ�ϲ��ܵ����һҳ
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

}

querydlg::~querydlg()
{

}

//������־
void querydlg::on_pushButton_clicked()
{
//    //��ѯ�豸����
    QString position = ui->comboBox_3->currentText();
    tcc = ui->comboBox_5->currentText();
    Querymodel->setHeaderData(0, Qt::Horizontal, QStringLiteral("�豸ID"));
    Querymodel->setHeaderData(1, Qt::Horizontal, QStringLiteral("��λ��"));
    Querymodel->setHeaderData(2, Qt::Horizontal, QStringLiteral("����"));
    Querymodel->setHeaderData(3, Qt::Horizontal, QStringLiteral("������Ϣ"));
    Querymodel->setHeaderData(4, Qt::Horizontal, QStringLiteral("����ʱ��"));

    ui->tableView->setModel(Querymodel);
    ui->tableView->show();

    if(!tcc.isEmpty())
    {
        QSqlQuery query(db_connection);

        QString sql = QString("SELECT count(*)  FROM dev_warn i  LEFT JOIN dev_attr a on (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL AND i.DEVID = a.DEVID ")
                .arg(tcc);
        query.exec(sql);
        query.next();

        totalRecrodCount =  query.value(0).toInt();

    }else
    {
        QMessageBox::warning(this,"Infomation",QStringLiteral("����Ϊ��!"));
        return;
    }
        totalPage = getSumPageNum();

        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        if (currentPage == totalPage)
        {
           ui->pushButton_2->setEnabled(false);
        }
        QString label2Text = QString(QStringLiteral("��%1ҳ")).arg(QString::number(totalPage));
        ui->label_6->setText(label2Text);
    RecordQuery(currentPage);
    currentPage++;
//    Querymodel->setQuery(total_sql,db_connection);

}

//������־����
void querydlg::on_pushButton_5_clicked()
{
//    //��ѯ�豸����
    username = ui->lineEdit_4->text();
    QStringList headerlist;
    headerlist<<QStringLiteral("���")<<QStringLiteral("ҵ������");
    headerlist<<QStringLiteral("��������");
    headerlist<<QStringLiteral("������")<<QStringLiteral("����ʱ��")<<QStringLiteral("��ע");
    for(int i = 0; i < 6; i++)
    {
         Querymodel1->setHeaderData(i, Qt::Horizontal, headerlist.at(i));
    }

    ui->tableView_2->setModel(Querymodel1);
    ui->tableView_2->show();

    if(!username.isEmpty())
    {
        QSqlQuery query(db_connection);

        QString sql = QString("SELECT count(*)  FROM operation_log WHERE CZR = '%1' ")
                .arg(username);
        query.exec(sql);
        query.next();

        totalRecrodCount1 =  query.value(0).toInt();

    }else
    {
        QMessageBox::warning(this,"Infomation",QStringLiteral("�û���Ϊ��!"));
        return;
    }
        totalPage1 = getSumPageNum();

        ui->pushButton_7->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        if (currentPage == totalPage)
        {
           ui->pushButton_7->setEnabled(false);
        }
        QString label2Text = QString(QStringLiteral("��%1ҳ")).arg(QString::number(totalPage1));
        ui->label_13->setText(label2Text);
    RecordQuery1(currentPage1);
    currentPage1++;
//    Querymodel->setQuery(total_sql,db_connection);

}

void querydlg::RecordQuery(int pageNum)
{
    QString sql =  QString("SELECT a.TCC ,a.DEVPOSTION,i.WARNINFO,i.WARNTIME,a.DEVAREA FROM dev_warn i  LEFT JOIN dev_attr a on (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL AND i.DEVID = a.DEVID limit ")
            .arg(tcc);

    int beginNum = (pageNum-1)*PageRecordCount;

    QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
    sql.append(szQuery);
    Querymodel->setQuery(sql,db_connection);


}

void querydlg::RecordQuery1(int pageNum)
{

    QString sql =  QString("SELECT * FROM operation_log WHERE CZR='%1' limit ")
            .arg(username);
    int beginNum = (pageNum-1)*PageRecordCount1;

    QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount1));
    sql.append(szQuery);
    Querymodel1->setQuery(sql,db_connection);


}

//��һҳ
void querydlg::on_pushButton_2_clicked()
{
    currentPage++;
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    if (currentPage == totalPage)
    {
       ui->pushButton_2->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
    ui->label_5->setText(label2Text);
    RecordQuery(currentPage);
}

//��һҳ
void querydlg::on_pushButton_6_clicked()
{
    currentPage1++;
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage1 == totalPage1)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage1));
    ui->label_12->setText(label2Text);
    RecordQuery1(currentPage1);
}

//shangyiye
void querydlg::on_pushButton_3_clicked()
{
    currentPage--;
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    if (currentPage == 1)
    {
       ui->pushButton_3->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
    ui->label_5->setText(label2Text);
    RecordQuery(currentPage);
}

//shangyiye
void querydlg::on_pushButton_7_clicked()
{
    currentPage1--;
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    if (currentPage1 == 1)
    {
       ui->pushButton_7->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage1));
    ui->label_12->setText(label2Text);
    RecordQuery1(currentPage1);
}


//ת��--ҳ
void querydlg::on_pushButton_4_clicked()
{
    QString goPageNum = ui->lineEdit_3->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("����ҳ�볬������ʾ�����ҳ��������������"));
       msg.exec();
    }else{

        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        if (currentPage == 1)
        {
         ui->pushButton_3->setEnabled(false);
        }
        if (currentPage == totalPage)
        {
         ui->pushButton_2->setEnabled(false);
        }

        QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage));
        ui->label_5->setText(label2Text);
        RecordQuery(currentPage);
     }

}

//ת��--ҳ
void querydlg::on_pushButton_8_clicked()
{
    QString goPageNum = ui->lineEdit_6->text();
    currentPage1 = goPageNum.toInt();
    if (currentPage1 > totalPage1)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("����ҳ�볬������ʾ�����ҳ��������������"));
       msg.exec();
    }else{

        ui->pushButton_7->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        if (currentPage1 == 1)
        {
         ui->pushButton_7->setEnabled(false);
        }
        if (currentPage1 == totalPage1)
        {
         ui->pushButton_6->setEnabled(false);
        }

        QString label2Text = QString(QStringLiteral("��ǰ��%1ҳ")).arg(QString::number(currentPage1));
        ui->label_12->setText(label2Text);
        RecordQuery(currentPage1);
     }

}
int querydlg::tableRowsNum()
{

    QString position = ui->comboBox_3->currentText();
    QString area = ui->comboBox_4->currentText();

    if(!area.isEmpty())
    {
         QSqlQuery query(db_connection);
         QString sql = QString("SELECT count(*)  FROM dev_warn i  LEFT JOIN dev_attr a on (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL AND i.DEVID = a.DEVID ")
                 .arg(area);
         query.exec(sql);
         query.next();

        return query.value(0).toInt();
    }
    return 0;
}

int querydlg::getSumPageNum()
{
    return (totalRecrodCount%PageRecordCount == 0)?(totalRecrodCount/PageRecordCount):(totalRecrodCount/PageRecordCount+1);
}

int querydlg::getSumPageNum1()
{
    return (totalRecrodCount1%PageRecordCount1 == 0)?(totalRecrodCount1/PageRecordCount1):(totalRecrodCount1/PageRecordCount1+1);
}



