#include "paramodel.h"
#include "qdebug.h"
/********************TableModel********************/
ParaModel::ParaModel(QObject *parent)
    : QAbstractTableModel(parent), arr_row_list(NULL)
{

}

ParaModel::~ParaModel(void)
{
    arr_row_list = NULL;
}

void ParaModel::setHorizontalHeaderList(QStringList horizontalHeaderList)
{
    horizontal_header_list = horizontalHeaderList;
}

void ParaModel::setVerticalHeaderList(QStringList verticalHeaderList)
{
    vertical_header_list = verticalHeaderList;
}

int ParaModel::rowCount(const QModelIndex &parent) const
{
    if(vertical_header_list.size() > 0)
        return vertical_header_list.size();

    if(NULL == arr_row_list)
        return 0;
    else
        return arr_row_list->size();
}

int ParaModel::columnCount(const QModelIndex &parent) const
{
    if(horizontal_header_list.size() > 0)
        return horizontal_header_list.size();

    if(NULL == arr_row_list)
        return 0;
    else if(arr_row_list->size() < 1)
        return 0;
    else
        return arr_row_list->at(0).size();
}

QVariant ParaModel::data(const QModelIndex &index, int role ) const
{
    if (!index.isValid())
        return QVariant();

    if(NULL == arr_row_list)
        return QVariant();

    if(arr_row_list->size() < 1)
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        if(index.row() >= arr_row_list->size())
            return QVariant();
        if(index.column() >= arr_row_list->at(0).size())
            return QVariant();
        //qDebug()<<"arr_row_list->at(index.row()).at(index.column()):"<<arr_row_list->at(index.row()).at(index.column());
        return arr_row_list->at(index.row()).at(index.column());

    }
    return QVariant();
}

bool ParaModel::setData(const QModelIndex &index,const QVariant &value, int role)
{
    if (index.isValid()
               && index.row() != index.column()
               && role == Qt::EditRole) {

        QStringList data_list = arr_row_list->at(index.row());
        data_list.replace(index.column(),value.toString());
        arr_row_list->replace(index.row(),data_list);
        for(int i = 0; i < arr_row_list->size(); i++)
        {
            qDebug()<<"PARAMODEL SETDATA :"<<arr_row_list->at(i);
        }
           emit dataChanged(index, index);
           return true;
       }
       return false;
}

QVariant ParaModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal) // 水平表头
        {
            if(horizontal_header_list.size() > section)
                return horizontal_header_list[section];
            else
                return QVariant();
        }
        else
        {
            if(vertical_header_list.size() > section)
                return vertical_header_list[section]; // 垂直表头
            else
                return QVariant();
        }
    }

    return QVariant();
}

Qt::ItemFlags ParaModel::flags(const QModelIndex &index) const
{
//    if (!index.isValid())
//        return Qt::NoItemFlags;

//    Qt::ItemFlags flag = QAbstractItemModel::flags(index);

//    flag|=Qt::ItemIsEditable; // 设置单元格可编辑,此处注释,单元格无法被编辑
//    return flag;

    if (!index.isValid())
    return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void ParaModel::setModalDatas(QList< QStringList > *rowlist)
{
    arr_row_list = rowlist;
    //qDebug()<<"arr list :"<<*arr_row_list;
}

void ParaModel::refrushModel()
{
    beginResetModel();
    endResetModel();

    emit updateCount(this->rowCount(QModelIndex()));
}
