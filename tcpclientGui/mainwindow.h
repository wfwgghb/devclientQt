#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>
#include<QString>
#include<QDataStream>
#include<QByteArray>
#include <QTimer>
#include <QDateTime>
#include <QTextCursor>
#include <QComboBox>
#include <QVariant>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QLabel>
#include "writelog.h"



namespace Ui {
class MainWindow;
}

class Utils;
class TcpConnection;
class SqlWork;
class SqlThread;
class devdlg;
class querydlg;
class paradlg;
class SearchDlg;
class MyItemDelegate;
class LogHandler;
class HistoryDlg;
class DevHttpClient;
class DeviceInfoModel;
class requestLastDataHandler;
class HttpClient;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTextCursor cursor;
    QTextCursor cursor1;
    QTextCursor cursor2;
    QTextCursor cursor3;
    QTimer *memtimer;
    //TcpConnection *comm_start;
    Utils *utils;
    SqlWork *sqlwork;    
    devdlg *AddDevDlg;
    querydlg *queryDevDlg;
    paradlg *writeparadlg;
    HistoryDlg *hisdlg;
    SearchDlg *sedlg;
    MyItemDelegate *myitemdelegate;
    QSqlQueryModel *mysqlquerymodel;
    SqlThread *sqlthread;
    LogHandler *loghandler;
    DevHttpClient *devhttpclient;
    requestLastDataHandler *lastdatalog;
    HttpClient *httpclient;
    DeviceInfoModel *deviceinfomodel;
    quint8 bytesToInt(QByteArray bytes);
    QSqlDatabase db_connection;
    void dataHander1(quint8 *dat, int size);
    void dataHander3(quint8 * dat);
    void initMainTable();
    void sqlFilterHandler();
    //void currentTime(quint8 *time);
    quint16 quint8Toquint16(quint8 *delta, int len);
    void DevAuth();
    //TableModel *maintablemodel;
    QList <QStringList> grid_data_list_info;
    QList< QStringList > grid_data_list;
    int tableRowsNum();
    int getSumPageNum();
    void RecordQuery(int pageNum);
    QStringList ParseText(QString text, QString devpos, QString connect, QString devid);
    void msgShow(QString& msg);
   // qint16 checkByBit( char* buffer, int offset, int count,quint16 initValue,	quint16 polynomial);
private:
    Ui::MainWindow *ui;

    QString str;
    QString str1;
    int count;
    QByteArray BUFFER;
    quint64 starttime;
    QString rcvmsg;
    QString msg1;
    QString comdataMsg;
    QString ErrorHandler;
    QString searchSql;
    QString SQL_str;
    QStringList list1;
    bool WindowSizeFlag;
    QString sql_condition;

    QString areaid;
    QString tccid;
    QString berthl;
    QString berthh;
    QMap <QString ,QString> devinfo;
    QMap <QString ,QString> devconn;
    int       currentPage;      //当前页
    int       totalPage;    //总页数
    int       totalRecrodCount;     //总记录数
    enum      {PageRecordCount = 10};//每页显示记录数
    int       currentPageNum;
    QString username;
    QString pwd;
    QLabel *mylabel;
    QString s_lastdata;
signals:
    void SendSignal(QByteArray block);
    void errorSignal(int flag);
    void SendUsernameSignal(QString username);
    void SendSqlfilterSignal(QString filter);
    void MsgForHttpSignal(QString temp);
    void datebaseConnectionSignal(QString msg);
private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    //void ComdataShow(QVariant data);
    void errorHandler(int flag);
    void DebugInfoShow(QString msg);
    void SysInfoShow(QString msg);
    void filterSqlSlot(QString filtersql);
    void stopSocketSlot();
    void afterConnectionSuccess();
    void UpdateMaintableView();
    void onLastDataSignal(QString str);
    void onErrorHandlerSignal(int errorno);
    void ondevOnlineSignal(QString devid,bool online);
    void onSend2httpserverSignal(int result);
    void onLowPowerSignal(QString dev_id);
    void MemCleaning();
};

#endif // MAINWINDOW_H
