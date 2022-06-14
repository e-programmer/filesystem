#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include "filesystem"



MainWindow::MainWindow(QWidget *parent) :  //constructor
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  QPixmap pix(":/rec/icons/add.png");
  ui->createAFolder->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
  QPixmap pix1(":/rec/icons/add-file.png");
  ui->createAFile->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


//QListWidgetItem * MainWindow::itemPtr;

//QListWidgetItem* MainWindow::getItem(const QListWidgetItem &item){
//    if (itemPtr==nullptr){
//       itemPtr=new QListWidgetItem;
//    }
//    else{
//        return itemPtr;
//    }
//}


void MainWindow::on_createAFolderBt_clicked() //create a folder command
{
     window3* w3=new window3;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of Folder");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    QString newfolderName = inp.textValue();

    if (ok == QDialog::DialogCode::Accepted){
       w3->evaluateFolder(w3,newfolderName);
       w3->show();
       hide();
        } //if ends here

}


void MainWindow::on_createAFileBt_clicked()
{
     window3* w3=new window3;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of File");
    inp.setTextValue("File Name");
    int ok = inp.exec();
    QString newfileName = inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){
       w3->evaluateFile(w3,newfileName);
       w3->show();
       hide();
    }


}

void MainWindow::makeList(window3* w3){

    for (int i=0;i<FileSystem::getInstance()->navigator->subFolders.size();i++ ){
        QListWidgetItem* itemPtr=new QListWidgetItem(QIcon(":/rec/icons/dlf.pt-folder-png-213538.png"),
                                         FileSystem::getInstance()->navigator->subFolders[i].folderName);

        w3->setPic(itemPtr);
    }

    for (int i=0;i<FileSystem::getInstance()->navigator->subFiles.size();i++ ){
        QListWidgetItem* itemPtr=new QListWidgetItem(QIcon(":/rec/icons/fileiconwindows.png"),
                                         FileSystem::getInstance()->navigator->subFiles[i].fileName);

        w3->setPic1(itemPtr);
    }
}

