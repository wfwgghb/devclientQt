/********************************************************************************
** Form generated from reading UI file 'searchdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDLG_H
#define UI_SEARCHDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDlg
{
public:
    QGroupBox *groupBox_7;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SearchDlg)
    {
        if (SearchDlg->objectName().isEmpty())
            SearchDlg->setObjectName(QStringLiteral("SearchDlg"));
        SearchDlg->resize(382, 238);
        groupBox_7 = new QGroupBox(SearchDlg);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(80, 30, 221, 151));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 71, 20));
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 71, 20));
        lineEdit = new QLineEdit(groupBox_7);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 20, 113, 20));
        lineEdit_2 = new QLineEdit(groupBox_7);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 50, 113, 20));
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 71, 20));
        lineEdit_3 = new QLineEdit(groupBox_7);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 80, 113, 20));
        label_12 = new QLabel(groupBox_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 110, 71, 20));
        lineEdit_8 = new QLineEdit(groupBox_7);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(80, 110, 113, 20));
        label_13 = new QLabel(groupBox_7);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(200, 20, 21, 20));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(200, 50, 21, 20));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(200, 80, 21, 20));
        pushButton = new QPushButton(SearchDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 200, 75, 23));
        pushButton_2 = new QPushButton(SearchDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 200, 75, 23));

        retranslateUi(SearchDlg);

        QMetaObject::connectSlotsByName(SearchDlg);
    } // setupUi

    void retranslateUi(QDialog *SearchDlg)
    {
        SearchDlg->setWindowTitle(QApplication::translate("SearchDlg", "Dialog", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("SearchDlg", "\350\256\276\345\244\207\345\256\232\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("SearchDlg", "\345\220\210\344\275\234\344\274\231\344\274\264ID\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("SearchDlg", "\351\241\271\347\233\256ID\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("SearchDlg", "\345\214\272\345\237\237\345\217\267\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("SearchDlg", "\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("SearchDlg", "*", Q_NULLPTR));
        label_14->setText(QApplication::translate("SearchDlg", "*", Q_NULLPTR));
        label_15->setText(QApplication::translate("SearchDlg", "*", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SearchDlg", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SearchDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchDlg: public Ui_SearchDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDLG_H
