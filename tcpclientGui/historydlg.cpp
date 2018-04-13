#include "historydlg.h"

#include "utils.h"
#include "sqlwork.h"
#include <QMessageBox>

HistoryDlg::HistoryDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historydlg)
{
    ui->setupUi(this);

    //utils = new Utils;
    db_connection = SqlWork::getConnectionByName(MainSqlName);

    //设置当前页
    currentPage = 1;
     Querymodel = new QSqlQueryModel();
    //初始默认不能点击上一页
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

}

HistoryDlg::~HistoryDlg()
{

}

void HistoryDlg::on_pushButton_clicked()
{

//    //查询设备属性
    QString position = ui->comboBox->currentText();
    area = ui->comboBox_2->currentText();
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);


    if(!area.isEmpty())
    {
        QSqlQuery query(db_connection);
        QString sql = QString("SELECT count(*) FROM geo_val i LEFT JOIN dev_attr a on  (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL and i.DEVID = a.DEVID ")
                .arg(area);
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


        ui->tableView->setModel(Querymodel);
         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
         ui->tableView->show();
    RecordQuery(currentPage);
    QStringList headerlist;
    headerlist<<QStringLiteral("设备ID")<<QStringLiteral("设备区域")<<QStringLiteral("设备位置");
    headerlist<<QStringLiteral("车辆信息")<<QStringLiteral("当前x值")<<QStringLiteral("当前y值");
    headerlist<<QStringLiteral("当前z值")<<QStringLiteral("环境x值")<<QStringLiteral("环境y值");
    headerlist<<QStringLiteral("环境z值")<<QStringLiteral("时间")<<QStringLiteral("配对号");
    for(int i = 0; i < 12; i++)
    {
        Querymodel->setHeaderData(i, Qt::Horizontal,headerlist.at(i));
    }
    //currentPage++;
//    Querymodel->setQuery(total_sql,db_connection);

}

void HistoryDlg::RecordQuery(int pageNum)
{
    QString sql =  QString("SELECT i.DEVID ,a.DEVAREA ,a.DEVPOSTION,i.CARINFO,i.CURX,i.CURY,i.CURZ,i.INITX,i.INITY,i.INITZ,i.RTC ,i.PAIRID FROM geo_val i LEFT JOIN dev_attr a on  (i.DEVID = a.DEVID) AND a.DEVAREA = '%1' WHERE i.DEVID IS NOT NULL and i.DEVID = a.DEVID limit ")
            .arg(area);
    int beginNum = (pageNum-1)*PageRecordCount;

    QString szQuery = QString("%1,%2").arg(QString::number(beginNum)).arg(QString::number(PageRecordCount));
    sql.append(szQuery);
    Querymodel->setQuery(sql,db_connection);


}

//下一页
void HistoryDlg::on_pushButton_2_clicked()
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

//shangyiye
void HistoryDlg::on_pushButton_3_clicked()
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
//转到--页
void HistoryDlg::on_pushButton_4_clicked()
{
    QString goPageNum = ui->lineEdit_3->text();
    currentPage = goPageNum.toInt();
    if (currentPage > totalPage)
    {
       QMessageBox msg;
       msg.setText(QStringLiteral("输入页码超过能显示的最大页数，请重新输入"));
       msg.exec();
    }else{

        ui->pushButton_3->setEnabled(true);
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
int HistoryDlg::tableRowsNum()
{

    QString position = ui->comboBox->currentText();
    QString area = ui->comboBox_2->currentText();

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

int HistoryDlg::getSumPageNum()
{
    return (totalRecrodCount%PageRecordCount == 0)?(totalRecrodCount/PageRecordCount):(totalRecrodCount/PageRecordCount+1);
}



