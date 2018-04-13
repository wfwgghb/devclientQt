#include "dialog.h"

//dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include <QTextEdit>
#include <qdebug.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    flag = 0;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    setData();
    close();
}

void Dialog::setData()
{
    QString devid = ui->lineEdit->text();
    QString pos = ui->lineEdit_2->text();
    QString area = ui->lineEdit_3->text();
    QString tcc = ui->lineEdit_4->text();


    QJsonObject json_obj;
    json_obj.insert("devid",devid);
    json_obj.insert("devpostion",pos);
    json_obj.insert("devarea",area);
    json_obj.insert("tcc",tcc);
   QString temp = QString(QJsonDocument(json_obj).toJson(QJsonDocument::Compact));
   emit sendData(temp);
}

void Dialog::on_pushButton_2_clicked()
{
    close();
}

void Dialog::recvData(QString recvdata)
{

    QJsonDocument jsonDocument = QJsonDocument::fromJson(recvdata.toLocal8Bit().data());
    if( jsonDocument.isNull() ){

    }
    QJsonObject jsonObject = jsonDocument.object();
    QString devid =  jsonObject.value("devid").toString();
    QString pos = jsonObject.value("devpostion").toString();
    QString area = jsonObject.value("devarea").toString();
    QString tcc = jsonObject.value("tcc").toString();
    qDebug()<<" ui->lineEdit->setText(devid);"<<devid;
    ui->lineEdit->setText(devid);
     ui->lineEdit_2->setText(pos);
     ui->lineEdit_3->setText(area);
      ui->lineEdit_4->setText(tcc);
}
