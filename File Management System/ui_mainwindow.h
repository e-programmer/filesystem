/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *createAFolder;
    QLabel *createAFile;
    QPushButton *createAFolderBt;
    QPushButton *createAFileBt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(378, 239);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 281, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        createAFolder = new QLabel(widget);
        createAFolder->setObjectName(QString::fromUtf8("createAFolder"));

        gridLayout->addWidget(createAFolder, 0, 0, 1, 1);

        createAFile = new QLabel(widget);
        createAFile->setObjectName(QString::fromUtf8("createAFile"));

        gridLayout->addWidget(createAFile, 0, 1, 1, 1);

        createAFolderBt = new QPushButton(widget);
        createAFolderBt->setObjectName(QString::fromUtf8("createAFolderBt"));

        gridLayout->addWidget(createAFolderBt, 1, 0, 1, 1);

        createAFileBt = new QPushButton(widget);
        createAFileBt->setObjectName(QString::fromUtf8("createAFileBt"));

        gridLayout->addWidget(createAFileBt, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 378, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createAFolder->setText(QString());
        createAFile->setText(QString());
        createAFolderBt->setText(QCoreApplication::translate("MainWindow", "Create a Folder", nullptr));
        createAFileBt->setText(QCoreApplication::translate("MainWindow", "Create a File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
