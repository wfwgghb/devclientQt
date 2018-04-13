#include "tableitemdelegate.h"

TableItemDelegate::TableItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 6)
   {
       //获取值
       bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
       //按钮的风格选项
       QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
       checkBoxOption->state |= QStyle::State_Enabled;
       //根据值判断是否选中
       if(checked)
       {
           checkBoxOption->state |= QStyle::State_On;
       }
       else
       {
           checkBoxOption->state |= QStyle::State_Off;
       }
       //返回QCheckBox几何形状
       checkBoxOption->rect = CheckBoxRect(option);
       //绘制QCheckBox
       QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);

   }else if (index.column() == 1)  //如果是第2列'设备Id'
    {
        //获得当前项值
        QString patientId = index.model()->data(index, Qt::DisplayRole).toString();
        //获取项风格设置
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    //绘制文本
    QApplication::style()->drawItemText ( painter, myOption.rect , myOption.displayAlignment, QApplication::palette(), true,patientId );


    }else if(index.column() == 2)
    {

    }
    else
    {
        //否则调用默认委托
        QStyledItemDelegate::paint(painter, option, index);
    }
}

//("序列号"));
//("设备号"));
//"上门限阈值"));
//("下门限阈值"));
//("更新环境初始值"));
//("更新/下载"));
//("选中"));
bool TableItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (index.column() == 1) {
        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            QRect btnRect = option.rect;
            btnRect.setWidth(40);
            if (btnRect.contains(ev->pos())) {
                QMessageBox::about(nullptr, "title", QString("row:%1, col:%2").arg(index.row() + 1).arg(index.column() + 1));
                return true;
            }
        }
    }
    if (index.column() == 1) {
        if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            QRect btnRect = option.rect;
            btnRect.setWidth(40);
            if (btnRect.contains(ev->pos())) {
                QMessageBox::about(nullptr, "title", QString("row:%1, col:%2").arg(index.row() + 1).arg(index.column() + 1));
                return true;
            }
        }
    }
    return false;
}
