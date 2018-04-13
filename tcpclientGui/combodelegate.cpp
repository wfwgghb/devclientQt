#include "combodelegate.h"

#include <QComboBox>
#include <QDebug>


ComboDelegate::ComboDelegate(QObject *parent) : QItemDelegate(parent)
{//代理类
}

//首先创建要进行代理的窗体
QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   QStringList  texts;
   texts <<QString(QStringLiteral(""))<<QString(QStringLiteral("download"))<<QString(QStringLiteral("update"))<<QString(QStringLiteral("update/download"));

  QComboBox *editor = new QComboBox(parent);      //一个COMBOBOX的控件

  editor->addItems(texts);

  editor->installEventFilter(const_cast<ComboDelegate*>(this));    //调用这个函数安装事件过滤器，使这个对象可以捕获QDateTimeEdit对象的事件

  return editor;
}

//这个是初始化作用，初始化代理控件的数据
void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  //先用这个index返回这个model然后用这个model得到index对应的数据
  QString dateStr = index.model()->data(index, Qt::EditRole).toString();

  qDebug()<< "combobox data :"<<dateStr;

  QComboBox *edit = static_cast<QComboBox*>(editor);    //
  int  tindex = edit->findText(dateStr);
  edit->setCurrentIndex(tindex);

}

//将代理控件里面的数据更新到视图控件中
//void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox *edit = static_cast<QComboBox*>(editor);

  QString text = edit->currentText();
  //QString text =QString::number( edit->currentIndex(),10);

  model->setData(index, text, Qt::EditRole);
}

//代理中数据的改变放到model中
//void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  editor->setGeometry(option.rect);
}

