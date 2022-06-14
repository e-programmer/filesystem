#include "window3.h"
#include "ui_window3.h"

#include <QPixmap>
#include "mainwindow.h"
#include "displaytree.h"
#include <QInputDialog>
#include <QMessageBox>

window3::window3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window3)
{
    ui->setupUi(this);
    QPixmap pic(":/rec/icons/Folder-Open-icon.png");
    ui->pathicon->setPixmap(pic.scaled(20,20,Qt::KeepAspectRatio));
}

window3::~window3()
{
    delete ui;
}

void window3::setPic(QListWidgetItem* item){ //for folder
ui->listWidget->addItem(item);

}
void window3::setPic1(QListWidgetItem* item){ //for file

    ui->listWidget->addItem(item);

}



void window3::on_label_windowIconTextChanged(const QString &iconText) //to display path of files/folders
{
   ui->label->setText(iconText);
}

//------------OPEN A FOLDER---------//

void window3::on_actionOpen_a_Folder_triggered() //open a folder icon is clicked
{
    window3 *w3=new window3;
    MainWindow* mw=new MainWindow;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of Folder to open");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    QString openfolderName = inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){
       if (FileSystem::getInstance()->folderExists(FileSystem::getInstance()->navigator,openfolderName)){ //if folder exists, navigate into it
        //navigation function
           FileSystem::getInstance()->navigateInto(openfolderName);
           mw->makeList(w3);
           printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
           w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
                          labeltext);
           w3->show();
           hide();
       }
      else{
           QMessageBox::warning(this,"","Folder does not exist");
           on_actionOpen_a_Folder_triggered();
       }
    }
    if (!ok){
        mw->makeList(w3);
    //    printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
        w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
             labeltext);

    }

}

//-------------GO BACK--------------//

void window3::on_actionback_triggered()
{
    MainWindow* mew=new MainWindow;
    window3* w3=new window3;
    w3->on_label_windowIconTextChanged(goBack());
    mew->makeList(w3);    //list of directories and files
    printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
    w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+labeltext);
    w3->show();
    hide();
}

QString window3::goBack(){
    if(FileSystem::getInstance()->pathToCurrentFolder.size()>1){
        FileSystem::getInstance()->pathToCurrentFolder.pop_back();
        FileSystem::getInstance()->navigator = FileSystem::getInstance()->pathToCurrentFolder[FileSystem::getInstance()->pathToCurrentFolder.size() - 1];
        //printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
       return FileSystem::getInstance()->printRoot()+labeltext;
    }
    else{
        window3* w3=new window3;
        QMessageBox::about(w3, "", "At Root Directory");
        return  FileSystem::getInstance()->printRoot();

    }


}

//--------PRINT CURRENT PATH-------//

void window3::printCurrentPath(const vector<Folder*> pathVec) { //path to current folder
     for (int i = 1; i < pathVec.size(); ++i) {
          labeltext.append(pathVec[i]->folderName + "\\");
   }
}

//------------CREATE FILE---------//

void window3::on_actionCreae_File_triggered()
{
    MainWindow *mw=new MainWindow;
    window3* w3=new window3;
   QInputDialog inp;
   inp.setWindowTitle("File Management System");
   inp.setLabelText("Type name of File");
   inp.setTextValue("File Name");
   int ok = inp.exec();
   QString newfileName = inp.textValue();
   if (ok == QDialog::DialogCode::Accepted){
       evaluateFile(w3,newfileName);
   }
   else{
       mw->makeList(w3);
       printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
       w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
                     labeltext);

  }
}

//------------CREATE FOLDER---------//

void window3::on_actionCreate_Folder_triggered()
{
    MainWindow *mw=new MainWindow;
    window3* w3=new window3;
   QInputDialog inp;
   inp.setWindowTitle("File Management System");
   inp.setLabelText("Type name of Folder");
   inp.setTextValue("Folder Name");
   int ok = inp.exec();
   QString newfolderName = inp.textValue();
   if (ok == QDialog::DialogCode::Accepted){
       evaluateFolder(w3,newfolderName);
   }
   else{
       mw->makeList(w3);
     // printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
       w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
          labeltext);
  }

}

//--------------DELETE--------------//

void window3::on_actionDelete_triggered()
{
    window3* w3=new window3;
    MainWindow* mw=new MainWindow;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of Folder or file to delete");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    QString deletefname = inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){

 if (FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,deletefname))
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"","Are you sure you want to delete this file?",QMessageBox::Yes|QMessageBox::No);

    if (reply==QMessageBox::Yes){
        FileSystem::getInstance()->deleteFile(FileSystem::getInstance()->navigator,deletefname);
    }

    mw->makeList(w3);
     printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
    w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
        labeltext);
    w3->show();
    hide();
}

else if (FileSystem::getInstance()->folderExists(FileSystem::getInstance()->navigator,deletefname)){

    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"","Are you sure you want to delete this folder?",QMessageBox::Yes|QMessageBox::No);

    if (reply==QMessageBox::Yes) {
        FileSystem::getInstance()->deleteFolder(FileSystem::getInstance()->navigator,deletefname);
    }

    mw->makeList(w3);
     printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
    w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
        labeltext);

    w3->show();
    hide();
}

else{
   QMessageBox::warning(this,"","Folder or file does not exist");
}

}

}

//--------------COPY--------------//


void window3::on_actionCopy_triggered()
{
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of Folder or file to copy");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    QString copyName = inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){ //if user clicks on ok


  if(FileSystem::getInstance()->fileOrFolderExists(FileSystem::getInstance()->navigator,copyName)){

    if (FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,copyName)){ //if file exists
            FileSystem::getInstance()->fileClipboard.clear();
            FileSystem::getInstance()->folderClipboard.clear();
            File newFile=File(copyName);
            FileSystem::getInstance()->fileClipboard.push_back(newFile);
            QMessageBox::about(this,"","Copied!");
        }

   else { //if folder exists
            FileSystem::getInstance()->fileClipboard.clear();
            FileSystem::getInstance()->folderClipboard.clear();
            QMessageBox::about(this,"","Copied!");
            FileSystem::getInstance()->folderClipboard.push_back(FileSystem::getInstance()->copyFolderFunction(FileSystem::getInstance()->navigator,copyName));

        }
  }

  else {  //if both dont exist
      QMessageBox::warning(this,"","Folder or file does not exist");
   }
}

}

//------------PASTE--------------//

void window3::on_actionPaste_triggered()
{
    MainWindow* mw=new MainWindow;
    window3* w3=new window3;
    //if folder and file clipboard is empty
   if (FileSystem::getInstance()->folderClipboard.size()==0 &&FileSystem::getInstance()->fileClipboard.size()==0 ){
        QMessageBox::warning(this,"","Nothing to paste");
    }
    //if a folder with that name already exists
   else if (FileSystem::getInstance()->folderClipboard.size()>0&&FileSystem::getInstance()->folderExists(FileSystem::getInstance()->navigator,FileSystem::getInstance()->folderClipboard[0].folderName)){
            QMessageBox::warning(this,"","A folder with that name already exists");
    }
    //if a file with that name already exists
   else if (FileSystem::getInstance()->fileClipboard.size()>0&&FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,FileSystem::getInstance()->fileClipboard[0].fileName)){
            QMessageBox::warning(this,"","A file with that name already exists");
    }
   else{
        for(int i=0;i<FileSystem::getInstance()->fileClipboard.size();++i){
            FileSystem::getInstance()->navigator->subFiles.push_back(FileSystem::getInstance()->fileClipboard[i]);
        }
        for(int i=0;i<FileSystem::getInstance()->folderClipboard.size();++i){
            FileSystem::getInstance()->navigator->subFolders.push_back(FileSystem::getInstance()->folderClipboard[i]);
        }
        QMessageBox::about(this,"","Pasted!");

        mw->makeList(w3);
        printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
        w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
             labeltext);
        w3->show();
        hide();
    }

}

void window3::evaluateFile(window3* w3,QString newfileName){  //for new file

    MainWindow* mw=new MainWindow;
    if (FileSystem::getInstance()->fileOrFolderExists(FileSystem::getInstance()->navigator,newfileName)){
        if (FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,newfileName)) {
            QMessageBox::warning(this,"","File with this name already exists");
        }
        else QMessageBox::warning(this,"","A folder with this name already exists");

    } //inner if ends

 else{
        FileSystem::getInstance()->createFile(FileSystem::getInstance()->navigator,newfileName); //creates the file
        w3->show();
        hide();
     }
  mw->makeList(w3);
   printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
   w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
                            labeltext);

}

void window3::evaluateFolder(window3* w3,QString newfolderName){  //for new folder
    MainWindow* mw=new MainWindow;
    if (FileSystem::getInstance()->fileOrFolderExists(FileSystem::getInstance()->navigator,newfolderName)){
        if (FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,newfolderName)) {
            QMessageBox::warning(this,"","File with this name already exists");
        }
        else QMessageBox::warning(this,"","A folder with this name already exists");

    }

    else{
    FileSystem::getInstance()->createFolder(FileSystem::getInstance()->navigator,newfolderName); //creates the file
    w3->show();
    hide();
        }
    mw->makeList(w3);
     printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
    w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
                         labeltext);

}
//-----VIEW TREE----//
void window3::on_actionviewTree_triggered()
{
    QMessageBox::StandardButton reply;
   reply= QMessageBox::question(this,"","Are you sure you want to quit and view the tree?",QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes){
        displayTree* dt=new displayTree;
         dt->printTree();
         hide();
    }
}

//--RENAME ----//
void window3::on_actionRename_file_folder_triggered()
{
  MainWindow* mw=new MainWindow;
  window3 * w3=new window3;
    QString fileorfoldername;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Enter name for File or folder to rename: ");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    fileorfoldername=inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){
        if (FileSystem::getInstance()->fileOrFolderExists(FileSystem::getInstance()->navigator,fileorfoldername)){
           // QMessageBox::warning(this,"","File or Folder does not exist");
            if (FileSystem::getInstance()->fileExists(FileSystem::getInstance()->navigator,fileorfoldername)){
            FileSystem::getInstance()->RenameFile(fileorfoldername,FileSystem::getInstance()->navigator);
            }
            else {

            FileSystem::getInstance()->RenameFolder(fileorfoldername,FileSystem::getInstance()->navigator);

            }
            mw->makeList(w3);
             printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);
            w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+
                                 labeltext);
            w3->show();
            hide();
        }

        else{
             QMessageBox::warning(this,"","File or Folder does not exist");
          //  printCurrentPath(FileSystem::getInstance()->pathToCurrentFolder);

        }
    }


}

//--SEARCH FUNCTION---//

void window3::searchFunction(Folder* pointerToCurrentFolder,QString fName, vector<Folder*> &pathvec,vector<Folder*> &pathChange){
        vector< vector < Folder* > > compositionOfPaths;
          int k=0;
      if(FileSystem::getInstance()->isFile(fName)){
          std::string fname=fName.toStdString();
          string actualName=fname.substr(0,fname.size()-4);
          QString actualname=QString::fromStdString(actualName);
          searchFileFunction(pointerToCurrentFolder,actualname,pathvec,compositionOfPaths,k);
      }
      else{
          searcherMethod(pointerToCurrentFolder,fName,pathvec,compositionOfPaths,k);
       }
          if(compositionOfPaths.size()==0){
              QMessageBox::about(this,"","Not Found");
              return;
          }
          int input;
          int validSize=compositionOfPaths.size();
          bool continueLoop=true;
          while(continueLoop){
              QInputDialog inp;
              inp.setWindowTitle("File Management System");
              inp.setLabelText("Enter the index to go to that path : ");
              inp.setIntValue(0);
               inp.exec();

              input=inp.intValue();

              continueLoop=searchInputValidator(input,validSize);

              if(continueLoop){
                  QMessageBox::warning(this,"","Invalid Input");
                    continue;
                  }

            else{

                    if(compositionOfPaths.size()>0){
                        MainWindow* mw=new MainWindow;
                        window3* w3=new window3;
                    pathChange=compositionOfPaths[input];
                    FileSystem::getInstance()->navigator=pathChange[pathChange.size() - 1];
                    w3->on_label_windowIconTextChanged(FileSystem::getInstance()->printRoot()+ labeltext);
                    mw->makeList(w3);
                    w3->show();
                    hide();
                    }
                    else{
                        QMessageBox::about(this,"","Not Found");
                        break;
                    }

            }

          }

   }
   bool window3:: searchInputValidator(int in, int vSize){
       for(int i=0;i<vSize;++i){
           if(in==i){
               return false;
           }

       }
       return true;
   }


   void window3::searchFileFunction(Folder* pointerToCurrentFolder,QString fName, vector<Folder*> &pathvec, vector<vector<Folder* > > &compositionOfPaths,int &index){
    for(int i=0;i<pointerToCurrentFolder->subFiles.size();++i){
        if(pointerToCurrentFolder->subFiles[i].fileName==fName){
            printCurrentPath(pathvec);
            string ind=to_string(index);
            QString inde=QString::fromStdString(ind);
             QMessageBox::information(this,"",inde+") " + fName+".txt"+"\t"+FileSystem::getInstance()->printRoot()+labeltext);
            compositionOfPaths.push_back(pathvec);
            index++;
        }}
        for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){

            if(!FileSystem::getInstance()->isEmpty(&pointerToCurrentFolder->subFolders[i])){
               pathvec.push_back(&pointerToCurrentFolder->subFolders[i]);
               searcherMethod(&pointerToCurrentFolder->subFolders[i],fName,pathvec,compositionOfPaths,index);
               pathvec.pop_back();
            }
        }
   }

   void window3::searcherMethod(Folder* pointerToCurrentFolder,QString fName, vector<Folder*> &pathvec, vector<vector<Folder* > > &compositionOfPaths,int &index){
       for(int i=0;i<pointerToCurrentFolder->subFiles.size();++i){
        if(pointerToCurrentFolder->subFiles[i].fileName==fName){
            printCurrentPath(pathvec);
            string ind=to_string(index);
            QString inde=QString::fromStdString(ind);
             QMessageBox::information(this,"",inde+") " + fName+".txt"+"\t"+FileSystem::getInstance()->printRoot()+labeltext);
            compositionOfPaths.push_back(pathvec);
            index++;
        }}
        for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){
            if(pointerToCurrentFolder->subFolders[i].folderName==fName){
                printCurrentPath(pathvec);
                string ind=to_string(index);
                QString inde=QString::fromStdString(ind);
                 QMessageBox::information(this,"",inde+") " + fName+"\t"+FileSystem::getInstance()->printRoot()+labeltext);
                compositionOfPaths.push_back(pathvec);
                index++;

            }
            if(!FileSystem::getInstance()->isEmpty(&pointerToCurrentFolder->subFolders[i])){
               pathvec.push_back(&pointerToCurrentFolder->subFolders[i]);
               searcherMethod(&pointerToCurrentFolder->subFolders[i],fName,pathvec,compositionOfPaths,index);
               pathvec.pop_back();
            }
        }
       }


void window3::on_actionSearch_File_Folder_triggered()
{
    QString tempinput;
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Enter name to search : ");
    inp.setTextValue("Folder Name");
    inp.exec();
    tempinput=inp.textValue();
    vector<Folder*> tempPath;
    tempPath.push_back(&FileSystem::getInstance()->system[0]);
    searchFunction(&FileSystem::getInstance()->system[0], tempinput, tempPath, FileSystem::getInstance()->pathToCurrentFolder);

}
