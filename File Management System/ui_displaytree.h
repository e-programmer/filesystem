/********************************************************************************
** Form generated from reading UI file 'displaytree.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYTREE_H
#define UI_DISPLAYTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayTree
{
public:
    QLabel *label;
    QLabel *pic;
    QLabel *finaltext;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *displayTree)
    {
        if (displayTree->objectName().isEmpty())
            displayTree->setObjectName(QString::fromUtf8("displayTree"));
        displayTree->resize(965, 515);
        displayTree->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(displayTree);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 461, 421));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pic = new QLabel(displayTree);
        pic->setObjectName(QString::fromUtf8("pic"));
        pic->setGeometry(QRect(480, 40, 471, 421));
        finaltext = new QLabel(displayTree);
        finaltext->setObjectName(QString::fromUtf8("finaltext"));
        finaltext->setGeometry(QRect(280, 0, 511, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setBold(false);
        font.setWeight(50);
        finaltext->setFont(font);
        pushButton = new QPushButton(displayTree);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 490, 471, 23));
        pushButton_2 = new QPushButton(displayTree);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 490, 461, 21));

        retranslateUi(displayTree);

        QMetaObject::connectSlotsByName(displayTree);
    } // setupUi

    void retranslateUi(QWidget *displayTree)
    {
        displayTree->setWindowTitle(QCoreApplication::translate("displayTree", "Form", nullptr));
        label->setText(QString());
        pic->setText(QString());
        finaltext->setText(QCoreApplication::translate("displayTree", "FINAL TREE STRUCTURE", nullptr));
        pushButton->setText(QCoreApplication::translate("displayTree", "Paste this tree in a file in your system", nullptr));
        pushButton_2->setText(QCoreApplication::translate("displayTree", "Read tree from file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displayTree: public Ui_displayTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYTREE_H
