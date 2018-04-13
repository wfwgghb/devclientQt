#ifndef SPINDELEGATE_H
#define SPINDELEGATE_H

#include <QItemDelegate>

class spindelegate : public QItemDelegate
{
  Q_OBJECT
public:
  explicit spindelegate(QObject *parent = 0);

signals:

public slots:


  // QAbstractItemDelegate interface
public:
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // SPINDELEGATE_H
