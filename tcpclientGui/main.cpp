
#include "mainwindow.h"
#include "writelog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    // ��װ��Ϣ�������
    //qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
