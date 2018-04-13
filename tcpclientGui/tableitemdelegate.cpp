#include "tableitemdelegate.h"

TableItemDelegate::TableItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 6)
   {
       //��ȡֵ
       bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
       //��ť�ķ��ѡ��
       QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
       checkBoxOption->state |= QStyle::State_Enabled;
       //����ֵ�ж��Ƿ�ѡ��
       if(checked)
       {
           checkBoxOption->state |= QStyle::State_On;
       }
       else
       {
           checkBoxOption->state |= QStyle::State_Off;
       }
       //����QCheckBox������״
       checkBoxOption->rect = CheckBoxRect(option);
       //����QCheckBox
       QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);

   }else if (index.column() == 1)  //����ǵ�2��'�豸Id'
    {
        //��õ�ǰ��ֵ
        QString patientId = index.model()->data(index, Qt::DisplayRole).toString();
        //��ȡ��������
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    //�����ı�
    QApplication::style()->drawItemText ( painter, myOption.rect , myOption.displayAlignment, QApplication::palette(), true,patientId );


    }else if(index.column() == 2)
    {

    }
    else
    {
        //�������Ĭ��ί��
        QStyledItemDelegate::paint(painter, option, index);
    }
}

//("���к�"));
//("�豸��"));
//"��������ֵ"));
//("��������ֵ"));
//("���»�����ʼֵ"));
//("����/����"));
//("ѡ��"));
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
