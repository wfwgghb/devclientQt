#ifndef PARAMODEL_H
#define PARAMODEL_H

#include <QAbstractTableModel>


/********************TableModel********************/
class ParaModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    ParaModel(QObject *parent = 0);
    ~ParaModel(void);
    void setHorizontalHeaderList(QStringList horizontalHeaderList);
    void setVerticalHeaderList(QStringList verticalHeaderList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::EditRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void setModalDatas(QList< QStringList > *rowlist);
    void refrushModel();
    bool setData(const QModelIndex &index,const QVariant &value, int role=Qt::EditRole);

signals:

    void updateCount(int count);

private:

    QStringList horizontal_header_list;
    QStringList vertical_header_list;
    QList< QStringList > *arr_row_list;

};
#endif // PARAMODEL_H
