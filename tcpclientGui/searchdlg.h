#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SearchDlg;
}

class SearchDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDlg(QWidget *parent = 0);
    ~SearchDlg();
    void getSearchInfo();
private:
    Ui::SearchDlg *ui;
signals:
    void filterSignal(QString sql);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SEARCHDLG_H
