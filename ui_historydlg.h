/********************************************************************************
** Form generated from reading UI file 'historydlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDLG_H
#define UI_HISTORYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Historydlg
{
public:
    QDialogButtonBox *buttonBox;
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
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *Historydlg)
    {
        if (Historydlg->objectName().isEmpty())
            Historydlg->setObjectName(QStringLiteral("Historydlg"));
        Historydlg->resize(895, 561);
        buttonBox = new QDialogButtonBox(Historydlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(650, 500, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Historydlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 160, 801, 311));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 751, 241));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(710, 270, 51, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(646, 270, 51, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(559, 270, 71, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(480, 270, 71, 20));
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

        groupBox_2 = new QGroupBox(Historydlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 20, 441, 131));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 54, 12));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 54, 12));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 60, 231, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        dateTimeEdit = new QDateTimeEdit(formLayoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateTimeEdit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        dateTimeEdit_2 = new QDateTimeEdit(formLayoutWidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dateTimeEdit_2);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 80, 75, 23));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 20, 69, 22));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(260, 20, 69, 22));

        retranslateUi(Historydlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), Historydlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Historydlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(Historydlg);
    } // setupUi

    void retranslateUi(QDialog *Historydlg)
    {
        Historydlg->setWindowTitle(QApplication::translate("Historydlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Historydlg", "\345\216\206\345\217\262\346\225\260\346\215\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Historydlg", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Historydlg", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton_4->setText(QApplication::translate("Historydlg", "\350\275\254\345\210\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("Historydlg", "\351\241\265", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Historydlg", "\347\255\233\351\200\211\346\235\241\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("Historydlg", "\346\263\212\344\275\215\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Historydlg", "\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Historydlg", "\345\274\200\345\247\213\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Historydlg", "\347\273\223\346\235\237\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Historydlg", "\347\241\256\350\256\244", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Historydlg", "001010", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Historydlg: public Ui_Historydlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDLG_H
