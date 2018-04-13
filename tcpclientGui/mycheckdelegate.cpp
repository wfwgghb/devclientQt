#include "mycheckdelegate.h"
#include <QTableView>
#include <QMouseEvent>
#include <QEvent>
#include <qdebug.h>
mycheckDelegate::mycheckDelegate(QTableView* tableView)
{
    int gridHint = tableView->style()->styleHint(QStyle::SH_Table_GridLineColor, new QStyleOptionViewItemV4());
    QColor gridColor = static_cast<QRgb>(gridHint);
    pen = QPen(gridColor,0,tableView->gridStyle());
    view = tableView;
}

void mycheckDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,const QModelIndex& index)const
{
    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
    qDebug()<<"checked:"<<checked;
    if((index.column() == 7)||(index.column() == 4))
    {

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
    }else
    {
        QStyledItemDelegate::paint(painter,option,index);
        return;
    }

}

bool mycheckDelegate::editorEvent(QEvent *event,
                                   QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option,
                                   const QModelIndex &index) {
    if((index.column() == 7)||(index.column() == 4))
    {
        if((event->type() == QEvent::MouseButtonRelease) ||
            (event->type() == QEvent::MouseButtonDblClick))
        {
            QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
            if(mouse_event->button() != Qt::LeftButton ||
               !CheckBoxRect(option).contains(mouse_event->pos()))
            {
                return false;
            }

            if(event->type() == QEvent::MouseButtonDblClick)
            {
                return true;
            }
        }
        else if(event->type() == QEvent::KeyPress)
        {
            if(static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space &&
               static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select)
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        return model->setData(index, !checked, Qt::EditRole);
    }
    return true;
}
