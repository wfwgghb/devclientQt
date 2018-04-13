/********************************************************************************
** Form generated from reading UI file 'devdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVDLG_H
#define UI_DEVDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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

class Ui_DevDlg
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QTableView *tableView;
    QPushButton *pushButton_6;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_6;
    QLabel *label_14;
    QPushButton *pushButton_7;
    QLabel *label_13;
    QLabel *label_12;

    void setupUi(QDialog *DevDlg)
    {
        if (DevDlg->objectName().isEmpty())
            DevDlg->setObjectName(QStringLiteral("DevDlg"));
        DevDlg->resize(922, 399);
        groupBox = new QGroupBox(DevDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 261, 201));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 30, 181, 118));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_2);

        comboBox_3 = new QComboBox(formLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_3);

        comboBox_4 = new QComboBox(formLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 160, 75, 23));
        groupBox_2 = new QGroupBox(DevDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(310, 30, 591, 291));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 551, 221));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(514, 250, 51, 23));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 250, 140, 25));
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

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(450, 250, 51, 23));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(267, 250, 71, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(360, 250, 71, 20));

        retranslateUi(DevDlg);

        QMetaObject::connectSlotsByName(DevDlg);
    } // setupUi

    void retranslateUi(QDialog *DevDlg)
    {
        DevDlg->setWindowTitle(QApplication::translate("DevDlg", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DevDlg", "\350\256\276\345\244\207\345\256\232\344\275\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("DevDlg", "\346\263\212\344\275\215\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("DevDlg", "\350\256\276\345\244\207\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("DevDlg", "\350\256\276\345\244\207ID\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("DevDlg", "\345\201\234\350\275\246\345\234\272\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DevDlg", "\346\220\234\347\264\242", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DevDlg", "\350\256\276\345\244\207\345\261\236\346\200\247", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("DevDlg", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("DevDlg", "\350\275\254\345\210\260", Q_NULLPTR));
        label_14->setText(QApplication::translate("DevDlg", "\351\241\265", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("DevDlg", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        label_13->setText(QString());
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DevDlg: public Ui_DevDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVDLG_H
