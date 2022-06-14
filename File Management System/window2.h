#ifndef WINDOW2_H
#define WINDOW2_H


#include "filesystem.h"
#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>


namespace Ui {
class window2;
}

class window2 : public QMainWindow
{
    Q_OBJECT

public:
//    void setFileSystem(FileSystem &f){
//        fs = f;
//    }
//    FileSystem getFileSystem(){
//        return fs;
//    }
  //  window2();

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();


public slots:
    void  on_pushButton_clicked();

private:
    Ui::window2 *ui;
};

#endif // WINDOW2_H
