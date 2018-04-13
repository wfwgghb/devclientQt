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
    //设置当前页
    currentPage = 1;

    //初始默认不能点击上一页
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    //设置当前页
    currentPage1 = 1;

    //初始默认不能点击上一页
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

}

querydlg::~querydlg()
{

}

//警告日志
void querydlg::on_pushButton_clicked()
{
//    //查询设备属性
    QString position = ui->comboBox_3->currentText();
    tcc = ui->comboBox_5->currentText();
    Querymodel->setHeaderData(0, Qt::Horizontal, QStringLiteral("设备ID"));
    Querymodel->setHeaderData(1, Qt::Horizontal, QStringLiteral("泊位号"));
    Querymodel->setHeaderData(2, Qt::Horizontal, QStringLiteral("区域"));
    Querymodel->setHeaderData(3, Qt::Horizontal, QStringLiteral("警告信息"));
    Querymodel->setHeaderData(4, Qt::Horizontal, QStringLiteral("警告时间"));

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
        QMessageBox::warning(this,"Infomation",QStringLiteral("区域为空!"));
        return;
    }
        totalPage = getSumPageNum();

        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        if (currentPage == totalPage)
        {
           ui->pushButton_2->setEnabled(false);
        }
        QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage));
        ui->label_6->setText(label2Text);
    RecordQuery(currentPage);
    currentPage++;
//    Querymodel->setQuery(total_sql,db_connection);

}

//操作日志搜索
void querydlg::on_pushButton_5_clicked()
{
//    //查询设备属性
    username = ui->lineEdit_4->text();
    QStringList headerlist;
    headerlist<<QStringLiteral("序号")<<QStringLiteral("业务类型");
    headerlist<<QStringLiteral("操作类型");
    headerlist<<QStringLiteral("操作人")<<QStringLiteral("操作时间")<<QStringLiteral("备注");
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
        QMessageBox::warning(this,"Infomation",QStringLiteral("用户名为空!"));
        return;
    }
        totalPage1 = getSumPageNum();

        ui->pushButton_7->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        if (currentPage == totalPage)
        {
           ui->pushButton_7->setEnabled(false);
        }
        QString label2Text = QString(QStringLiteral("总%1页")).arg(QString::number(totalPage1));
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

//下一页
void querydlg::on_pushButton_2_clicked()
{
    currentPage++;
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    if (currentPage == totalPage)
    {
       ui->pushButton_2->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
    ui->label_5->setText(label2Text);
    RecordQuery(currentPage);
}

//下一页
void querydlg::on_pushButton_6_clicked()
{
    currentPage1++;
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    if (currentPage1 == totalPage1)
    {
       ui->pushButton_6->setEnabled(false);
    }
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage1));
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
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
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
    QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage1));
    ui->label_12->setText(label2Text);
    RecordQuery1(currentPage1);
}


//转到--页
void querydlg::on_pushButton_4_clicked()
{
    QString goPageNum = ui->lineEdit_3->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("输入页码超过能显示的最大页数，请重新输入"));
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

        QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage));
        ui->label_5->setText(label2Text);
        RecordQuery(currentPage);
     }

}

//转到--页
void querydlg::on_pushButton_8_clicked()
{
    QString goPageNum = ui->lineEdit_6->text();
    currentPage1 = goPageNum.toInt();
    if (currentPage1 > totalPage1)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("输入页码超过能显示的最大页数，请重新输入"));
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

        QString label2Text = QString(QStringLiteral("当前第%1页")).arg(QString::number(currentPage1));
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



