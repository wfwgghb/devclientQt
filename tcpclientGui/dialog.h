
//dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setData();
private:
    Ui::Dialog *ui;
    int flag;
signals:
    void  sendData(QString senddata);
private slots:
    void recvData(QString recvdata);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H


