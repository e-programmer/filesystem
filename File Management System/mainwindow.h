#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "window2.h"
#include <QListWidgetItem>

#include "window3.h"

#include <QMainWindow>
#include <QTextStream>
#include <QInputDialog>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

//private:
   // FileSystem f;


// static QListWidgetItem* itemPtr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
 //  void on_actionOpen_Folder_triggered();

    void on_createAFolderBt_clicked();
    void on_createAFileBt_clicked();
    void makeList(window3*);

//   static QListWidgetItem* getItem(const QListWidgetItem &item);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
