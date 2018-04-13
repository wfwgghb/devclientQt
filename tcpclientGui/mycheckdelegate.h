#ifndef MYCHECKDELEGATE_H
#define MYCHECKDELEGATE_H

#include<QStyledItemDelegate>
#include<QTableView>
#include<QPainter>
#include<QApplication>

class mycheckDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    mycheckDelegate(QTableView* tableView);
protected:
    void paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const;
    bool editorEvent(QEvent *event,
                                         QAbstractItemModel *model,
                                         const QStyleOptionViewItem &option,
                                         const QModelIndex &index) ;
private:
    QPen         pen;
    QTableView*  view;
};

static QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options)
{
    QStyleOptionButton check_box_style_option;
    QRect check_box_rect = QApplication::style()->subElementRect(
        QStyle::SE_CheckBoxIndicator,
        &check_box_style_option);

    QPoint check_box_point(view_item_style_options.rect.x() +
                           view_item_style_options.rect.width() / 2 -
                           check_box_rect.width() / 2,
                           view_item_style_options.rect.y() +
                           view_item_style_options.rect.height() / 2 -
                           check_box_rect.height() / 2);
    return QRect(check_box_point, check_box_rect.size());
}
#endif // MYCHECKDELEGATE_H
