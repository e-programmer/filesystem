#include "window2.h"
#include "ui_window2.h"
#include <QDir>

#include "mainwindow.h"
using namespace std;


window2::window2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
    QPixmap pix(":/rec/icons/foldername.png");
    ui->mainwindowdisplay->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

}


window2::~window2()
{
    delete ui;
}


void window2::on_pushButton_clicked() //root folder name entered
{
    //FileSystem f;
    QString rootFolder = ui->lineEdit->text(); //get the text entered
     //sets the rootFolder name
    FileSystem::getInstance(rootFolder)->initiateNavigation();  //root folder becomes the navigator
//    setFileSystem(FileSystem::getInstance(root));
   // fs=&fileobj;

    MainWindow *mw=new MainWindow;
    mw->show();

    hide();
}


