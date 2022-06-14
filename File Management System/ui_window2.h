/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window2
{
public:
    QWidget *centralwidget;
    QLabel *mainwindowdisplay;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *inputdialogbox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window2)
    {
        if (window2->objectName().isEmpty())
            window2->setObjectName(QString::fromUtf8("window2"));
        window2->resize(337, 239);
        centralwidget = new QWidget(window2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainwindowdisplay = new QLabel(centralwidget);
        mainwindowdisplay->setObjectName(QString::fromUtf8("mainwindowdisplay"));
        mainwindowdisplay->setGeometry(QRect(190, 50, 141, 141));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 191, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 142, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        inputdialogbox = new QLabel(layoutWidget);
        inputdialogbox->setObjectName(QString::fromUtf8("inputdialogbox"));

        verticalLayout->addWidget(inputdialogbox);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        window2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 337, 21));
        window2->setMenuBar(menubar);
        statusbar = new QStatusBar(window2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window2->setStatusBar(statusbar);

        retranslateUi(window2);

        QMetaObject::connectSlotsByName(window2);
    } // setupUi

    void retranslateUi(QMainWindow *window2)
    {
        window2->setWindowTitle(QCoreApplication::translate("window2", "MainWindow", nullptr));
        mainwindowdisplay->setText(QString());
        label->setText(QCoreApplication::translate("window2", " File Management System", nullptr));
        inputdialogbox->setText(QCoreApplication::translate("window2", "Enter the name of your ", nullptr));
        label_2->setText(QCoreApplication::translate("window2", "root folder:", nullptr));
        pushButton->setText(QCoreApplication::translate("window2", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window2: public Ui_window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
