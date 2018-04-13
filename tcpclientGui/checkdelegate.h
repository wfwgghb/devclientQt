#ifndef CHECKDELEGATE_H
#define CHECKDELEGATE_H


#include <QItemDelegate>

class checkdelegate : public QItemDelegate
{
  Q_OBJECT
public:
  explicit checkdelegate(QObject *parent = 0);

signals:

public slots:


  // QAbstractItemDelegate interface
public:   //这里同datedelegate.h里面的意思
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
#endif // CHECKDELEGATE_H
