#include "checkdelegate.h"

#include <QDebug>
#include <QCheckBox>

checkdelegate::checkdelegate(QObject *parent) : QItemDelegate(parent)
{//������
}

//���ȴ���Ҫ���д���Ĵ���
QWidget *checkdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

  QCheckBox *editor = new QCheckBox(parent);

  editor->installEventFilter(const_cast<checkdelegate*>(this));    //�������������װ�¼���������ʹ���������Բ���QDateTimeEdit������¼�

  return editor;
}

//����ǳ�ʼ�����ã���ʼ������ؼ�������
void checkdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  //�������index�������modelȻ�������model�õ�index��Ӧ������
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

//������ؼ���������ݸ��µ���ͼ�ؼ���
//void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
void checkdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QCheckBox *edit = static_cast<QCheckBox*>(editor);

  int  val = edit->checkState();
  //QString text =QString::number( edit->currentIndex(),10);

  model->setData(index, val, Qt::EditRole);
}

//���������ݵĸı�ŵ�model��
//void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
void checkdelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  editor->setGeometry(option.rect);
}
