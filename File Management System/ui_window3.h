/********************************************************************************
** Form generated from reading UI file 'window3.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW3_H
#define UI_WINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window3
{
public:
    QAction *actionOpen_a_Folder;
    QAction *actionCreae_File;
    QAction *actionCreate_Folder;
    QAction *actionDelete;
    QAction *actionback;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionviewTree;
    QAction *actionRename_file_folder;
    QAction *actionCut_Folder_File;
    QAction *actionSearch_File_Folder;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *pathicon;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *window3)
    {
        if (window3->objectName().isEmpty())
            window3->setObjectName(QString::fromUtf8("window3"));
        window3->resize(508, 349);
        actionOpen_a_Folder = new QAction(window3);
        actionOpen_a_Folder->setObjectName(QString::fromUtf8("actionOpen_a_Folder"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/icons/Folder-Open-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_a_Folder->setIcon(icon);
        actionCreae_File = new QAction(window3);
        actionCreae_File->setObjectName(QString::fromUtf8("actionCreae_File"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/icons/unnamed.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreae_File->setIcon(icon1);
        actionCreate_Folder = new QAction(window3);
        actionCreate_Folder->setObjectName(QString::fromUtf8("actionCreate_Folder"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/icons/clipart684867.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_Folder->setIcon(icon2);
        actionDelete = new QAction(window3);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/icons/cancel-512-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        actionback = new QAction(window3);
        actionback->setObjectName(QString::fromUtf8("actionback"));
        actionback->setCheckable(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/icons/back-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionback->setIcon(icon4);
        actionCopy = new QAction(window3);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/icons/copy_icon-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(window3);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/icons/clipart1146204.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionviewTree = new QAction(window3);
        actionviewTree->setObjectName(QString::fromUtf8("actionviewTree"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rec/icons/free-tree-icon-1578-thumb.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionviewTree->setIcon(icon7);
        actionRename_file_folder = new QAction(window3);
        actionRename_file_folder->setObjectName(QString::fromUtf8("actionRename_file_folder"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rec/icons/renamefile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRename_file_folder->setIcon(icon8);
        actionCut_Folder_File = new QAction(window3);
        actionCut_Folder_File->setObjectName(QString::fromUtf8("actionCut_Folder_File"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/rec/icons/cut.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut_Folder_File->setIcon(icon9);
        actionSearch_File_Folder = new QAction(window3);
        actionSearch_File_Folder->setObjectName(QString::fromUtf8("actionSearch_File_Folder"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/rec/icons/mm-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch_File_Folder->setIcon(icon10);
        centralwidget = new QWidget(window3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 0, 461, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        label->setFont(font);
        pathicon = new QLabel(centralwidget);
        pathicon->setObjectName(QString::fromUtf8("pathicon"));
        pathicon->setGeometry(QRect(10, 0, 21, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 31, 481, 241));
        window3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 508, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew = new QMenu(menubar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        window3->setMenuBar(menubar);
        statusbar = new QStatusBar(window3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window3->setStatusBar(statusbar);
        toolBar = new QToolBar(window3);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        window3->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuNew->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen_a_Folder);
        menuFile->addAction(actionCopy);
        menuFile->addAction(actionPaste);
        menuFile->addAction(actionSearch_File_Folder);
        menuNew->addAction(actionCreae_File);
        menuNew->addAction(actionCreate_Folder);
        menuEdit->addAction(actionRename_file_folder);
        menuEdit->addAction(actionDelete);
        toolBar->addAction(actionback);
        toolBar->addAction(actionCreae_File);
        toolBar->addAction(actionCreate_Folder);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionOpen_a_Folder);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionRename_file_folder);
        toolBar->addAction(actionSearch_File_Folder);
        toolBar->addAction(actionviewTree);

        retranslateUi(window3);

        QMetaObject::connectSlotsByName(window3);
    } // setupUi

    void retranslateUi(QMainWindow *window3)
    {
        window3->setWindowTitle(QCoreApplication::translate("window3", "MainWindow", nullptr));
        actionOpen_a_Folder->setText(QCoreApplication::translate("window3", "Open a Folder", nullptr));
        actionCreae_File->setText(QCoreApplication::translate("window3", "New File", nullptr));
        actionCreate_Folder->setText(QCoreApplication::translate("window3", "New Folder", nullptr));
        actionDelete->setText(QCoreApplication::translate("window3", "Delete File/Folder", nullptr));
        actionback->setText(QCoreApplication::translate("window3", "back", nullptr));
        actionCopy->setText(QCoreApplication::translate("window3", "Copy File/Folder", nullptr));
        actionPaste->setText(QCoreApplication::translate("window3", "Paste", nullptr));
        actionviewTree->setText(QCoreApplication::translate("window3", "ViewTree", nullptr));
#if QT_CONFIG(tooltip)
        actionviewTree->setToolTip(QCoreApplication::translate("window3", "View Tree", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRename_file_folder->setText(QCoreApplication::translate("window3", "Rename file/folder", nullptr));
        actionCut_Folder_File->setText(QCoreApplication::translate("window3", "Cut Folder/File", nullptr));
        actionSearch_File_Folder->setText(QCoreApplication::translate("window3", "Search File/Folder", nullptr));
        label->setText(QString());
        pathicon->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("window3", "File", nullptr));
        menuNew->setTitle(QCoreApplication::translate("window3", "New", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("window3", "Edit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("window3", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window3: public Ui_window3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW3_H
