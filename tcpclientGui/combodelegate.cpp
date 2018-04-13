#include "combodelegate.h"

#include <QComboBox>
#include <QDebug>


ComboDelegate::ComboDelegate(QObject *parent) : QItemDelegate(parent)
{//������
}

//���ȴ���Ҫ���д���Ĵ���
QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   QStringList  texts;
   texts <<QString(QStringLiteral(""))<<QString(QStringLiteral("download"))<<QString(QStringLiteral("update"))<<QString(QStringLiteral("update/download"));

  QComboBox *editor = new QComboBox(parent);      //һ��COMBOBOX�Ŀؼ�

  editor->addItems(texts);

  editor->installEventFilter(const_cast<ComboDelegate*>(this));    //�������������װ�¼���������ʹ���������Բ���QDateTimeEdit������¼�

  return editor;
}

//����ǳ�ʼ�����ã���ʼ������ؼ�������
void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  //�������index�������modelȻ�������model�õ�index��Ӧ������
  QString dateStr = index.model()->data(index, Qt::EditRole).toString();

  qDebug()<< "combobox data :"<<dateStr;

  QComboBox *edit = static_cast<QComboBox*>(editor);    //
  int  tindex = edit->findText(dateStr);
  edit->setCurrentIndex(tindex);

}

//������ؼ���������ݸ��µ���ͼ�ؼ���
//void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox *edit = static_cast<QComboBox*>(editor);

  QString text = edit->currentText();
  //QString text =QString::number( edit->currentIndex(),10);

  model->setData(index, text, Qt::EditRole);
}

//���������ݵĸı�ŵ�model��
//void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
void ComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  editor->setGeometry(option.rect);
}

