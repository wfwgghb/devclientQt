#ifndef HISTORYDLG_H
#define HISTORYDLG_H

#include "ui_historydlg.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
    class Historydlg;
}
class Utils;
class HistoryDlg: public QDialog
{
  Q_OBJECT
public:
    HistoryDlg(QWidget *parent = 0);
    ~HistoryDlg();
    void currentTime(quint8 *time);
    int tableRowsNum();
    int getSumPageNum();
    void RecordQuery(int pageNum);
private:
    Ui::Historydlg *ui;
    QSqlQueryModel *Querymodel;
    Utils *utils;
    QSqlDatabase db_connection;
    QString total_sql;
    QString area;
    int       currentPage;      //��ǰҳ
    int       totalPage;    //��ҳ��
    int       totalRecrodCount;     //�ܼ�¼��
    enum      {PageRecordCount = 10};//ÿҳ��ʾ��¼��
signals:


private slots:
    void on_pushButton_clicked();
   void  on_pushButton_2_clicked();
   void  on_pushButton_3_clicked();
    void  on_pushButton_4_clicked();
};

#endif // HISTORYDLG_H
