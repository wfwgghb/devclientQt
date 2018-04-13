#include "myitemdelegate.h"
#include <QDateTime>
#include <qdebug.h>
MyItemDelegate::MyItemDelegate(QObject * parent):QItemDelegate(parent)
{
    connect=QPixmap(":new/icon/connect.png");
    disconnect=QPixmap(":new/icon/disconnected.png");
    car = QPixmap(":new/icon/car.png");
    battary_full = QPixmap(":new/icon/battery_full_16.png");
    battary_empty = QPixmap(":new/icon/battery_empty_16.png");
}

void MyItemDelegate::paint(QPainter * painter,
                           const QStyleOptionViewItem & option,
                           const QModelIndex & index) const
{

    if(index.column()==4)
    {
        const QAbstractItemModel * model=index.model();
        QVariant var=model->data(index,Qt::DisplayRole);
        if(var.isNull())
        {var=false;
            //qDebug()<<"vatrint :";
        }
        QPixmap  star;
        int vatrint = var.toString().toInt();
        //qDebug()<<"vatrint :"<<var.toString();
        if(vatrint ==0)
        {

            disconnect.scaled(option.rect.width()/2,option.rect.height()/2,Qt::KeepAspectRatio);
            star=disconnect;
        }else
        {
            star=connect;
        }
        int width=star.width();
        int height=star.height();
        QRect rect=option.rect;
        int x=rect.x()+rect.width()/2-width/2;
        int y=rect.y()+rect.height()/2-height/2;

        painter->drawPixmap(x,y,star);
    }else if(index.column()==1)         //      有无车
    {
        const QAbstractItemModel * model=index.model();
        QVariant var=model->data(index,Qt::DisplayRole);
        if(var.isNull()) var=false;
        QPixmap  star;
        QString varstr = var.toString();
        qDebug()<<"vatrint :"<<varstr;
        if(varstr=="01")
        {
            QString text = QString(QStringLiteral("无车"));

            //获取项风格设置
            QStyleOptionViewItem myOption = option;
            myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
            //绘制文本
            drawDisplay(painter, myOption, myOption.rect, text);
            //如果当前有焦点，就绘制一个焦点矩形，否则什么都不做
            drawFocus(painter, myOption, myOption.rect);
        }else if(varstr == "02")
        {
            star=car;
            int width=star.width();
            int height=star.height();
            QRect rect=option.rect;
            int x=rect.x()+rect.width()/2-width/2;
            int y=rect.y()+rect.height()/2-height/2;

            painter->drawPixmap(x,y,star);
        }

    }else if(index.column()==3)     // 电量
    {
        const QAbstractItemModel * model=index.model();
        QVariant var=model->data(index,Qt::DisplayRole);
        if(var.isNull()) var=false;
        QPixmap  star;
        QString varstr = var.toString();
        qDebug()<<"varstr :"<<varstr;
        if(varstr=="01")
        {
            star=battary_empty;
        }else if(varstr=="02")
        {
            star=battary_full;
        }
        int width=star.width();
        int height=star.height();
        QRect rect=option.rect;
        int x=rect.x()+rect.width()/2-width/2;
        int y=rect.y()+rect.height()/2-height/2;

        painter->drawPixmap(x,y,star);
    }else if(index.column()==2)     //设备时间
    {
        const QAbstractItemModel * model=index.model();
        QVariant var=model->data(index,Qt::DisplayRole);
        if(var.isNull()) var=false;
        QString varstr = var.toString();
        bool ok;
        quint32 varint = varstr.toUInt(&ok,16);
        QString text = QDateTime::fromTime_t(varint).toString("yyyy-MM-dd hh:mm:ss");
        //获取项风格设置
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        //绘制文本
        drawDisplay(painter, myOption, myOption.rect, text);
        //如果当前有焦点，就绘制一个焦点矩形，否则什么都不做
        drawFocus(painter, myOption, myOption.rect);

    }else
    {
        QItemDelegate::paint(painter,option,index);
        return;
    }
}

//bool MyItemDelegate::editorEvent(QEvent * event,
//                                    QAbstractItemModel * model,
//                                    const QStyleOptionViewItem & /*option*/,
//                                    const QModelIndex & index)
//{
//       if(event->type()==QEvent::MouseButtonPress && index.column()==0)
//       {
//               QVariant var=model->data(index,Qt::CheckStateRole);
//               bool isFavourite=var.toBool();
//               if(var.isValid())
//                   isFavourite=isFavourite?false:true;
//               else
//                   isFavourite=true;
//               model->setData(index,isFavourite,Qt::CheckStateRole);
//               return true;//I have handled the event
//       }

//       return false;
//}
