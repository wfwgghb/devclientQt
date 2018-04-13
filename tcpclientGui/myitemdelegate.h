#ifndef MYITEMDELEGATE_H
#define MYITEMDELEGATE_H
#include <QPixmap>
#include <qitemdelegate.h>
#include <qpainter.h>
class MyItemDelegate:public QItemDelegate
{
public:
    MyItemDelegate(QObject * parent=0);
    virtual ~ MyItemDelegate(){}

    void paint(QPainter * painter,
        const QStyleOptionViewItem & option,
        const QModelIndex & index) const;
    //bool editorEvent(QEvent * event,QAbstractItemModel * model,const QStyleOptionViewItem & option,  const QModelIndex & index);
private:
    QPixmap connect;
    QPixmap disconnect;
    QPixmap car   ;
    QPixmap battary_full;
    QPixmap battary_empty;
};

#endif // MYITEMDELEGATE_H
