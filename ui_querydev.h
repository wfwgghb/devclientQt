/********************************************************************************
** Form generated from reading UI file 'querydev.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYDEV_H
#define UI_QUERYDEV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryDLg
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QDateEdit *dateEdit_3;
    QLabel *label_17;
    QDateEdit *dateEdit_4;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QGroupBox *groupBox;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_5;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QDateEdit *dateEdit;
    QLabel *label_11;
    QDateEdit *dateEdit_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_15;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_4;
    QTableView *tableView_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_6;
    QLabel *label_14;

    void setupUi(QDialog *QueryDLg)
    {
        if (QueryDLg->objectName().isEmpty())
            QueryDLg->setObjectName(QStringLiteral("QueryDLg"));
        QueryDLg->resize(677, 548);
        buttonBox = new QDialogButtonBox(QueryDLg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(460, 500, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(QueryDLg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(36, 19, 601, 481));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setContextMenuPolicy(Qt::NoContextMenu);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 10, 541, 121));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 54, 12));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 54, 12));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 70, 75, 23));
        horizontalLayoutWidget_6 = new QWidget(groupBox_2);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(30, 60, 220, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(horizontalLayoutWidget_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_6->addWidget(label_16);

        dateEdit_3 = new QDateEdit(horizontalLayoutWidget_6);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));

        horizontalLayout_6->addWidget(dateEdit_3);

        label_17 = new QLabel(horizontalLayoutWidget_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_6->addWidget(label_17);

        dateEdit_4 = new QDateEdit(horizontalLayoutWidget_6);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));

        horizontalLayout_6->addWidget(dateEdit_4);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 20, 54, 12));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(90, 20, 69, 22));
        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(260, 20, 69, 22));
        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(420, 20, 69, 22));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-10, 140, 611, 311));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 20, 551, 241));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(514, 270, 51, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 270, 51, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(363, 270, 71, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 270, 71, 20));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 270, 140, 25));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icon/spam-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 541, 121));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(23, 20, 61, 20));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 20, 113, 20));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(450, 90, 75, 23));
        horizontalLayoutWidget_3 = new QWidget(groupBox_3);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(220, 60, 160, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        comboBox = new QComboBox(horizontalLayoutWidget_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        horizontalLayoutWidget_4 = new QWidget(groupBox_3);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(220, 10, 220, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        dateEdit = new QDateEdit(horizontalLayoutWidget_4);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout_4->addWidget(dateEdit);

        label_11 = new QLabel(horizontalLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        dateEdit_2 = new QDateEdit(horizontalLayoutWidget_4);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        horizontalLayout_4->addWidget(dateEdit_2);

        horizontalLayoutWidget_5 = new QWidget(groupBox_3);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(20, 60, 160, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(horizontalLayoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_5->addWidget(label_15);

        comboBox_2 = new QComboBox(horizontalLayoutWidget_5);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_5->addWidget(comboBox_2);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(-10, 140, 611, 311));
        tableView_2 = new QTableView(groupBox_4);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(30, 20, 551, 241));
        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(514, 270, 51, 23));
        pushButton_7 = new QPushButton(groupBox_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(450, 270, 51, 23));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(363, 270, 71, 20));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 270, 71, 20));
        horizontalLayoutWidget_2 = new QWidget(groupBox_4);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 270, 140, 25));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        lineEdit_6 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_2->addWidget(lineEdit_6);

        label_14 = new QLabel(horizontalLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_2->addWidget(label_14);

        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icon/logviewer.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon1, QString());

        retranslateUi(QueryDLg);
        QObject::connect(buttonBox, SIGNAL(accepted()), QueryDLg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QueryDLg, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QueryDLg);
    } // setupUi

    void retranslateUi(QDialog *QueryDLg)
    {
        QueryDLg->setWindowTitle(QApplication::translate("QueryDLg", "Dialog", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("QueryDLg", "\346\263\212\344\275\215\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("QueryDLg", "\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QueryDLg", "\347\241\256\350\256\244", Q_NULLPTR));
        label_16->setText(QApplication::translate("QueryDLg", "\344\273\216", Q_NULLPTR));
        label_17->setText(QApplication::translate("QueryDLg", "\345\210\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("QueryDLg", "\345\201\234\350\275\246\345\234\272\357\274\232", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("QueryDLg", "01010", Q_NULLPTR)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("QueryDLg", "0001", Q_NULLPTR)
        );
        groupBox->setTitle(QString());
        pushButton_2->setText(QApplication::translate("QueryDLg", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("QueryDLg", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton_4->setText(QApplication::translate("QueryDLg", "\350\275\254\345\210\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("QueryDLg", "\351\241\265", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QueryDLg", "\350\255\246\345\221\212\346\227\245\345\277\227", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_8->setText(QApplication::translate("QueryDLg", "\346\223\215\344\275\234\344\272\272\357\274\232", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("QueryDLg", "\346\220\234\347\264\242", Q_NULLPTR));
        label_9->setText(QApplication::translate("QueryDLg", "\344\270\232\345\212\241\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QueryDLg", "\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR)
         << QApplication::translate("QueryDLg", "\345\261\236\346\200\247\351\205\215\347\275\256", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("QueryDLg", "\344\273\216", Q_NULLPTR));
        label_11->setText(QApplication::translate("QueryDLg", "\345\210\260", Q_NULLPTR));
        label_15->setText(QApplication::translate("QueryDLg", "\346\223\215\344\275\234\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("QueryDLg", "\346\267\273\345\212\240", Q_NULLPTR)
         << QApplication::translate("QueryDLg", "\345\210\240\351\231\244", Q_NULLPTR)
         << QApplication::translate("QueryDLg", "\344\277\256\346\224\271", Q_NULLPTR)
        );
        groupBox_4->setTitle(QString());
        pushButton_6->setText(QApplication::translate("QueryDLg", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("QueryDLg", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_12->setText(QString());
        label_13->setText(QString());
        pushButton_8->setText(QApplication::translate("QueryDLg", "\350\275\254\345\210\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("QueryDLg", "\351\241\265", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QueryDLg", "\346\223\215\344\275\234\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QueryDLg: public Ui_QueryDLg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYDEV_H
