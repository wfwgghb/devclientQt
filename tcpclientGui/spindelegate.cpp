#include "spindelegate.h"

#include <QSpinBox>

spindelegate::spindelegate(QObject *parent) :
  QItemDelegate(parent)
{
}

QWidget *spindelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QSpinBox *editor = new QSpinBox(parent);
  editor->setRange(0, 30000);
  editor->installEventFilter(const_cast<QSpinBox*>(editor));
  return editor;
}

void spindelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  int value = index.model()->data(index).toInt();
  QSpinBox *box = static_cast<QSpinBox*>(editor);
  box->setValue(value);
}

void spindelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QSpinBox *box = static_cast<QSpinBox*>(editor);
  int value = box->value();

  model->setData(index, value);
}

void spindelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  editor->setGeometry(option.rect);
}
