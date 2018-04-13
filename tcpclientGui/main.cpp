
#include "mainwindow.h"
#include "writelog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    // 安装消息处理程序
    //qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
