#ifndef PARADLG_H
#define PARADLG_H

#include "ui_paradlg.h"
#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlError>
#include <QStandardItem>
#include <QFileDialog>

#include "combodelegate.h"
#include "spindelegate.h"
#include "checkdelegate.h"
#include "mycheckdelegate.h"
#include "constant.h"
#include "Utils.h"
#include "paramodel.h"

struct devAttr
{
    QString devid;
    QString devpos;
    QString devarea;
    QString tcc;
};

namespace Ui {
    class ParaDlg;
}

class paradlg: public QDialog
{
    Q_OBJECT
public:
    paradlg(QWidget *parent = 0);
    ~paradlg();
    Utils *utils;
    void initTableWidget();
    void initSettingPara();
    quint8 *tableLengthCalc(SettingParaSimp para);
    int tableRowsNum();
    int getSumPageNum();
    void RecordQuery(int pageNum);

    quint8 *textbytes;
    quint8 crrtime[6];
    quint8 Frame ; //同步传输
    quint8 Command ;
    quint32 Length ; //(msg:"")
    quint8 flag ;
    quint16 tagcount ;

    //inittags()
    quint32 tagid ;
    quint8 type ;

private:
     Ui::ParaDlg *ui;
     QSqlTableModel *model ;
     ComboDelegate *comboDelegate;
     spindelegate *spinDelegate;
     checkdelegate *checkDelegate;
     ParaModel *paramodel;
     mycheckDelegate *mycheckdelegate;
     SettingParaSimp settingpara;
     QSqlDatabase db_connection;
     QString total_sql;
     QList< QStringList > grid_data_list;
     QString Area;
     QString tcc;
     QString  postion;
     QString sqlfilter;
     QString username;
     QHash <int ,devAttr> tempAttrList;

     QString uploadfilepath;
     int uploadfileFlag;

     int       currentPage;      //当前页
     int       totalPage;    //总页数
     int       totalRecrodCount;     //总记录数
     enum      {PageRecordCount = 10};//每页显示记录数
signals:
     void sendParaSignal(QString block);
     void uploadfileNameSignal(QString path);
     void StartUploadFileSignal();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void ParaSettingSlot(quint8 data);
    void UsernameSlot(QString userName);
    void onparaSuccSignal();
    void getFileName();
};

#endif // PARADLG_H
