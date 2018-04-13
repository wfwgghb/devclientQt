#ifndef QUERYDLG_H
#define QUERYDLG_H

#include "ui_querydev.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
    class QueryDLg;
}
class Utils;
class querydlg: public QDialog
{
  Q_OBJECT
public:
    querydlg(QWidget *parent = 0);
    ~querydlg();
    int tableRowsNum();
    int getSumPageNum();
    int getSumPageNum1();
    void RecordQuery(int pageNum);
    void RecordQuery1(int pageNum);
private:
    Ui::QueryDLg *ui;
    QSqlQueryModel *Querymodel;
    QSqlQueryModel *Querymodel1;
    Utils *utils;
    QSqlDatabase db_connection;
    QString total_sql;
    //QString area;
    QString tcc;
    QString username;
    int       currentPage;      //��ǰҳ
    int       currentPage1;
    int       totalPage;    //��ҳ��
    int       totalRecrodCount;     //�ܼ�¼��
    enum      {PageRecordCount = 10};//ÿҳ��ʾ��¼��

    int       totalPage1;    //��ҳ��
    int       totalRecrodCount1;     //�ܼ�¼��
    enum      {PageRecordCount1 = 10};//ÿҳ��ʾ��¼��
signals:
    void SendSignal(QByteArray block);

private slots:
   void on_pushButton_clicked();
   void  on_pushButton_2_clicked();
   void  on_pushButton_3_clicked();
   void on_pushButton_4_clicked();
   void on_pushButton_5_clicked();
   void on_pushButton_6_clicked();
   void on_pushButton_7_clicked();
   void on_pushButton_8_clicked();

};

#endif // QUERYDLG_H
