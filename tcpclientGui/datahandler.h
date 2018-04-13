#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = 0);

signals:

public slots:
    //void RecvData();
};

#endif // DATAHANDLER_H
