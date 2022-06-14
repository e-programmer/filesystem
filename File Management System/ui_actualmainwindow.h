/********************************************************************************
** Form generated from reading UI file 'actualmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTUALMAINWINDOW_H
#define UI_ACTUALMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActualMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *mainWindowLabel;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ActualMainWindow)
    {
        if (ActualMainWindow->objectName().isEmpty())
            ActualMainWindow->setObjectName(QString::fromUtf8("ActualMainWindow"));
        ActualMainWindow->resize(360, 251);
        centralwidget = new QWidget(ActualMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainWindowLabel = new QLabel(centralwidget);
        mainWindowLabel->setObjectName(QString::fromUtf8("mainWindowLabel"));
        mainWindowLabel->setGeometry(QRect(220, 50, 131, 131));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 150, 111, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 181, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        ActualMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ActualMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 360, 21));
        ActualMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ActualMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ActualMainWindow->setStatusBar(statusbar);

        retranslateUi(ActualMainWindow);

        QMetaObject::connectSlotsByName(ActualMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ActualMainWindow)
    {
        ActualMainWindow->setWindowTitle(QCoreApplication::translate("ActualMainWindow", "MainWindow", nullptr));
        mainWindowLabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("ActualMainWindow", "Continue", nullptr));
        label->setText(QCoreApplication::translate("ActualMainWindow", "WELCOME  TO  FILE", nullptr));
        label_2->setText(QCoreApplication::translate("ActualMainWindow", "MANAGEMENT SYSTEM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActualMainWindow: public Ui_ActualMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTUALMAINWINDOW_H
