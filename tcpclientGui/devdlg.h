#ifndef DEVDLG_H
#define DEVDLG_H

#include "ui_devdlg.h"
#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlError>
#include <QStandardItem>
#include <QMenu>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "dialog.h"

namespace Ui {
    class DevDlg;
}
class Utils;
class devdlg : public QDialog
{
   Q_OBJECT
public:
    devdlg(QWidget *parent = 0);
    ~devdlg();

    void initialTableView();
    void DevAuth();
    void checkLastData();
    int getSumPageNum();
    void RecordQuery(int pageNum);

private:
    Ui::DevDlg *ui;
    QSqlTableModel *model;
    Utils *utils;
    QSqlDatabase db_connection;
    QString username;
    QAction *action_fillUserInfo;
    QAction *action_fillUserInfo1;
    QAction *action_fillUserInfo2;
    QMenu *popMenu;
    Dialog *menudlg;
    QStringList oldtempList;
    QJsonObject old_json_obj;
    int curRow;
    QStringList templist ;
    QString sqlfilter;
    QNetworkAccessManager *m_accessManager;
      QString regcode;
    int       currentPage;      //当前页
    int       totalPage;    //总页数
    int       totalRecrodCount;     //总记录数
    enum      {PageRecordCount = 20};//每页显示记录数
signals:
    void SendSignal(QByteArray block);
    void sendData(QString recvdata);
    void DevattrChangedSignal();
    void AddNewDevSignal(QString devid);
    void RegisterDeviceSignal();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
//    void on_pushButton_3_clicked();
 void deleDeviceSlot();
    void UsernameSlot(QString userName);

    void slotContextMenu(QPoint pos);
    void OpenSetttingDlg();
    void OpenSetttingDlg1();
    void receiveData(QString recvdata);
    void receiveData1(QString recvdata);
    void finishedSlot(QNetworkReply *reply);
    void RegisterDevice();
};

#endif // DEVDLG_H
