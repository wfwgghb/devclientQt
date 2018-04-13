#-------------------------------------------------
#
# Project created by QtCreator 2017-09-20T14:05:30
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpclientGui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    constant.cpp \
    utils.cpp \
    tcpconnection.cpp \
    sqlwork.cpp \
    devdlg.cpp \
    querydlg.cpp \
    paradlg.cpp \
    combodelegate.cpp \
    spindelegate.cpp \
    mycombobox.cpp \
    checkdelegate.cpp \
    mycheckdelegate.cpp \
    searchdlg.cpp \
    baseprotocol.cpp \
    datahandler.cpp \
    writelog.cpp \
    deviceinfomodel.cpp \
    sqlthread.cpp \
    myitemdelegate.cpp \
    loghandler.cpp \
    historydlg.cpp \
    paramodel.cpp \
    httpclient.cpp \
    dialog.cpp \
    devhttpclient.cpp \
    requestlastdatahandler.cpp \
    binfileread.cpp

HEADERS  += mainwindow.h \
    constant.h \
    utils.h \
    tcpconnection.h \
    sqlwork.h \
    devdlg.h \
    querydlg.h \
    paradlg.h \
    combodelegate.h \
    spindelegate.h \
    mycombobox.h \
    checkdelegate.h \
    mycheckdelegate.h \
    searchdlg.h \
    baseprotocol.h \
    datahandler.h \
    writelog.h \
    deviceinfomodel.h \
    sqlthread.h \
    myitemdelegate.h \
    loghandler.h \
    historydlg.h \
    paramodel.h \
    httpclient.h \
    dialog.h \
    devhttpclient.h \
    requestlastdatahandler.h \
    binfileread.h

FORMS    += mainwindow.ui \
    devdlg.ui \
    querydev.ui \
    paradlg.ui \
    searchdlg.ui \
    historydlg.ui \
    dialog.ui

RESOURCES += \
    src.qrc
