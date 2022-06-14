#include "actualmainwindow.h"
#include "ui_actualmainwindow.h"
#include "window2.h"

#include <QPixmap>
#include <QIcon>

ActualMainWindow::ActualMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ActualMainWindow)
{
    ui->setupUi(this);
   QPixmap pix(":/rec/icons/MainWindowIcon.png");
    ui->mainWindowLabel->setPixmap(pix.scaled(125,125,Qt::KeepAspectRatio));
}


ActualMainWindow::~ActualMainWindow()
{
    delete ui;
}

void ActualMainWindow::on_pushButton_clicked() //continue to next window
{
    window2 * w2=new window2;
    w2->show(); //show the second window
    hide(); //hide the actual main window
}
