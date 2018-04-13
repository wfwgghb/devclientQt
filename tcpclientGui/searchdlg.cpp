#include "searchdlg.h"
#include "ui_searchdlg.h"
#include <QDebug>

SearchDlg::SearchDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDlg)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
}

SearchDlg::~SearchDlg()
{
    delete ui;
}

void SearchDlg::on_pushButton_clicked()
{
    getSearchInfo();
    close();
}

void SearchDlg::on_pushButton_2_clicked()
{
    close();
}
void SearchDlg::getSearchInfo()
{
    QString sql;
    //获取界面信息
    QString Area = ui->lineEdit_3->text();
    QString  postion = ui->lineEdit_8->text();
    if(Area.isEmpty()&&Area.isNull())
    {
        QMessageBox::warning(this,"Infomation","Area number is required fields");
        return;
    }
    //正则表达式
//    if(Area.size()!=1)
//    {
//        QMessageBox::warning(this,"Infomation","devarea data format error!");
//        return;
//    }

    if(!postion.isEmpty())
    {
        //sql = QString("(select rowid,devid,devpostion from dev_attr where devarea = '%1' and devpostion = '%2')").arg(Area).arg(postion);
        sql.append(Area);
        sql.append(",");
        sql.append(postion);
    }else
    {
        //sql = QString("(select rowid,devid,devpostion from dev_attr  where  devarea = '%1')").arg(Area);
        sql.append(Area);
    }
    qDebug()<<"filter signal send!";
    emit filterSignal(sql);

}
