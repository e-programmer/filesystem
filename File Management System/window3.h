#ifndef WINDOW3_H
#define WINDOW3_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <vector>
#include "filesystem.h"


namespace Ui {
class window3;
}

class window3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit window3(QWidget *parent = nullptr);
    ~window3();
     QString labeltext="";


public slots:
   // void on_foldername_windowIconTextChanged(const QString);
     void setPic(QListWidgetItem*);
     void setPic1(QListWidgetItem*);
     void on_label_windowIconTextChanged(const QString &iconText);
     void evaluateFile(window3*,QString);
     void evaluateFolder(window3*,QString);
     void printCurrentPath(const vector<Folder*>);
     void searchFunction(Folder*,QString,vector <Folder*> &,vector <Folder*> &);
     bool searchInputValidator(int,int);
     void searchFileFunction(Folder*,QString,vector<Folder*> &,vector<vector<Folder* > > &,int &);
     void searcherMethod(Folder*,QString,vector<Folder*> &,vector<vector<Folder* > > &,int&);
     QString goBack();


private slots:
     void on_actionOpen_a_Folder_triggered();

     void on_actionback_triggered();

     void on_actionCreae_File_triggered();

     void on_actionCreate_Folder_triggered();

     void on_actionDelete_triggered();

     void on_actionCopy_triggered();

     void on_actionPaste_triggered();

     void on_actionviewTree_triggered();

     void on_actionRename_file_folder_triggered();

     void on_actionCut_Folder_File_triggered();

     void on_actionSearch_File_Folder_triggered();

private:
    Ui::window3 *ui;
};

#endif // WINDOW3_H
