#include "checkdelegate.h"

#include <QDebug>
#include <QCheckBox>

checkdelegate::checkdelegate(QObject *parent) : QItemDelegate(parent)
{//代理类
}

//首先创建要进行代理的窗体
QWidget *checkdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

  QCheckBox *editor = new QCheckBox(parent);

  editor->installEventFilter(const_cast<checkdelegate*>(this));    //调用这个函数安装事件过滤器，使这个对象可以捕获QDateTimeEdit对象的事件

  return editor;
}

//这个是初始化作用，初始化代理控件的数据
void checkdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  //先用这个index返回这个model然后用这个model得到index对应的数据
  int value = index.model()->data(index, Qt::EditRole).toInt();

  qDebug()<< "checkbox data :"<<value;

  QCheckBox *edit = static_cast<QCheckBox*>(editor);    //

  if(value = 0)
  {
    edit->setCheckState(Qt::Unchecked);
  }else if(value = 2)
  {
     edit->setCheckState(Qt::Checked);
  }

}

//将代理控件里面的数据更新到视图控件中
//void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
void checkdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QCheckBox *edit = static_cast<QCheckBox*>(editor);

  int  val = edit->checkState();
  //QString text =QString::number( edit->currentIndex(),10);

  model->setData(index, val, Qt::EditRole);
}

//代理中数据的改变放到model中
//void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
void checkdelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  editor->setGeometry(option.rect);
}
