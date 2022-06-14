#include "filesystem.h"
#include "QDebug"
#include <QMessageBox>
#include "window3.h"
#include "displaytree.h"
#include <fstream>
#include <QInputDialog>

FileSystem *FileSystem::m_instance;

FileSystem *FileSystem::getInstance(const QString &root){

    if(m_instance == nullptr) {
        qDebug () << "object Fuckin created";
        if (root == "")
            m_instance = new FileSystem; // call with default constructor
        else
            m_instance = new FileSystem(root);
        return m_instance;
    }
    return m_instance;

}

FileSystem::FileSystem()
{

}
FileSystem::FileSystem(QString rootFolderName){

    Folder rootFolder = Folder(rootFolderName);
    system.push_back(rootFolder);
}


void FileSystem::createFile(Folder * pointerToParentFolder, QString fName){ //create a file method
    File newFile = File(fName);
    pointerToParentFolder->subFiles.push_back(newFile);

}

void FileSystem::initiateNavigation(){
  navigator = &system[0]; //navigator points to root folder
  tempPath = navigator;
  pathToCurrentFolder.push_back(tempPath);
  navigator = pathToCurrentFolder[pathToCurrentFolder.size() - 1];
}

//Check if Folder exists
bool FileSystem:: folderExists(const Folder * pointerToCurrentFolder, QString folderName) {
    qDebug() << __func__ ;
    for (int i = 0; i < pointerToCurrentFolder->subFolders.size(); ++i) {
               if (pointerToCurrentFolder->subFolders[i].folderName == folderName) {
                   return true;
               }
      }
     return false;
}

//check if file exists
bool FileSystem::fileExists(const Folder* pointerToCurrentFolder, QString fileName) {
        for (int i = 0; i < pointerToCurrentFolder->subFiles.size(); ++i) {
            if (pointerToCurrentFolder->subFiles[i].fileName == fileName) {
                return true;
            }
        }
        return false;
    }


//Check if either File or Folder exists
bool FileSystem::fileOrFolderExists(const Folder* pointerToCurrentFolder, QString name) {
    return (folderExists(pointerToCurrentFolder, name) || fileExists(pointerToCurrentFolder, name));
}


//Create Folder
void FileSystem::createFolder(Folder * pointerToParentFolder, QString fName) {
    Folder newFolder(fName);
    qDebug() << "size ===>> " + pointerToParentFolder->subFolders.size();
    pointerToParentFolder->subFolders.push_back(newFolder);
}

//navigate into a folder
void FileSystem::navigateInto(QString fname){
tempPath = navigator;
     for (int i = 0; i < navigator->subFolders.size(); ++i) {
         if (fname == navigator->subFolders[i].folderName) {
             navigator = &(navigator->subFolders[i]);
             pathToCurrentFolder.push_back(navigator);
             break;
          }
      }
}

QString FileSystem::printRoot(){
   return  pathToCurrentFolder[0]->folderName+":\\";

}




//Delete Folder

void FileSystem::deleteFolder(Folder* pointerToCurrentFolder,QString fName){
    for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){
        if(pointerToCurrentFolder->subFolders[i].folderName==fName){
            pointerToCurrentFolder->subFolders.erase(pointerToCurrentFolder->subFolders.begin()+i);
            break;
        }
    }
}


//Delete File
void FileSystem::deleteFile(Folder* pointerToCurrentFolder,QString fName){
     for(int i=0;i<pointerToCurrentFolder->subFiles.size();++i){
         if(pointerToCurrentFolder->subFiles[i].fileName==fName){
             pointerToCurrentFolder->subFiles.erase(pointerToCurrentFolder->subFiles.begin()+i);
             break;
         }
     }
}

//COPY FOLDER
Folder FileSystem::copyFolderFunction(Folder* pointerToCurrentFolder, QString fName){
    Folder f1=Folder(fName);
    Folder* pointerToFolderToCopy;
    for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){
        if(pointerToCurrentFolder->subFolders[i].folderName==fName){
                 pointerToFolderToCopy=&pointerToCurrentFolder->subFolders[i];
                 break;
            }
    }

    copyFolderRecursion(pointerToFolderToCopy,&f1);
    return f1;
}

void FileSystem::copyFolderRecursion(Folder* pointerToFolderToCopy, Folder* FolderToCopyTo){
  for(int i=0;i<pointerToFolderToCopy->subFiles.size();++i){
       File newFile=File(pointerToFolderToCopy->subFiles[i].fileName);
       FolderToCopyTo->subFiles.push_back(newFile);
   }
 for(int i=0;i<pointerToFolderToCopy->subFolders.size();++i){
     Folder newFolder=Folder(pointerToFolderToCopy->subFolders[i].folderName);
     if(!isEmpty(&pointerToFolderToCopy->subFolders[i])){
         copyFolderRecursion(&pointerToFolderToCopy->subFolders[i],&newFolder);
     }
     FolderToCopyTo->subFolders.push_back(newFolder);
 }

}


//Check if a folder is Empty
bool FileSystem::isEmpty(Folder* pointerToCurrentFolder){
    return (pointerToCurrentFolder->subFolders.size()==0&&pointerToCurrentFolder->subFiles.size()==0);
}

//CHECK IF FILE OR FOLDER BY NAME
bool FileSystem::isFile(QString fileName){
    if(fileName.length()>4){
        std::string str=fileName.toStdString();  //convert qstring to string
        if(str.substr(fileName.length()-4)==".txt"){
           // fileName=QString::fromStdString(str); //convert back
            return true;

        }
        else{return false;}
    }
    else{return false;}
}

void FileSystem::getFileSystem(QString text,Folder* pointerToCurrentFolder){
    fstream myfile;
    std::string textFileName=text.toStdString();
    myfile.open(textFileName,ios_base::out);
    myfile.close();
    if(pointerToCurrentFolder==NULL){
      QString textFile=QString::fromStdString(textFileName);
      fileSystemMaker(textFile,&system[0]);
    }
    else{
        QString textFile=QString::fromStdString(textFileName);
        fileSystemMaker(textFile,pointerToCurrentFolder);
    }
}

void FileSystem::fileSystemMaker(QString text,Folder* pointerToCurrentFolder,int k){
    fstream myfile;
   std::string textFileName=text.toStdString();
    myfile.open(textFileName,ios_base::app);
    for(int i=0;i<pointerToCurrentFolder->subFiles.size();++i){
        QString filename="";
        for(int j=0;j<k;++j){
            filename+="*";
        }

        filename+=pointerToCurrentFolder->subFiles[i].fileName + ".txt";
        std::string file=filename.toStdString();
        myfile<<file+"\n";
    }
    myfile.close();
    for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){
        fstream myfile;
        myfile.open(textFileName,ios_base::app);
        QString foldername="";
        for(int j=0;j<k;++j){
            foldername+="*";
        }
        foldername+=pointerToCurrentFolder->subFolders[i].folderName;
        std::string folder=foldername.toStdString();
        myfile<<folder + "\n";
        if(!isEmpty(&pointerToCurrentFolder->subFolders[i])){
            myfile.close();
            QString textFile=QString::fromStdString(textFileName);
            fileSystemMaker(textFile,&(pointerToCurrentFolder->subFolders[i]),1+k);
        }
        else{myfile.close();}
    }

}

//helper functions for reading file system

int FileSystem::numberOfStars(string fileName){
    int k=0;
    while(fileName[k]=='*'){
        k++;
    }
    return k;
}

string FileSystem::fileNameWithoutStars(string fileName){
    QString fName=QString::fromStdString(fileName);
  if(isFile(fName)){
    for(int i=0;i<4;++i){
      fileName.pop_back();
  }
  return fileName.substr(numberOfStars(fileName),fileName.size());
  }
  else return fileName.substr(numberOfStars(fileName),fileName.size());
}

//INPUT FILESYSTEM FROM TEXT FILE

void FileSystem::inputFileSystem(string textFileName,string directoryName,Folder* pointerToCurrentFolder){

    vector<string> fileLines;
    fstream myfile;
  //open here
    myfile.open(textFileName,ios_base::in);
    string line;
    while(getline(myfile,line)){
        fileLines.push_back(line);
    }

    myfile.close();
    vector<Folder>pathVec;
    QString dirName=QString::fromStdString(directoryName);
    Folder newFolder=Folder(dirName);
    pathVec.push_back(newFolder);
    if(pointerToCurrentFolder==NULL){
      fileSystemInputter(pathVec,fileLines);
      Folder newRoot=pathVec[0];
      system.push_back(newRoot);
    }
    else{
        fileSystemInputter(pathVec,fileLines);
    }
}

void FileSystem::fileSystemInputter(vector<Folder> &path,vector<string> allLines,int stars,int index){
    if(index<allLines.size()){
          if(index<allLines.size()-1){
              QString str=QString::fromStdString(allLines[index]);
                 if(isFile(str)){
                     QString str=QString::fromStdString(fileNameWithoutStars(allLines[index]));
                     File newFile=File(str);
                     path[path.size()-1].subFiles.push_back(newFile);
                     index++;
                      int i=0;
                            while(i< stars-numberOfStars(allLines[index])){
                             path[path.size()-2].subFolders.push_back(path[path.size()-1]);
                             path.pop_back();
                             ++i;
                            }

                        fileSystemInputter(path,allLines,numberOfStars(allLines[index]),index);
                    }
                    else{
                        //if is folder
                     QString str=QString::fromStdString(fileNameWithoutStars(allLines[index]));

                        Folder newFolder=Folder(str);
                        path.push_back(newFolder);
                        index++;
                            if(numberOfStars(allLines[index])==(stars+1)){
                                fileSystemInputter(path,allLines,stars+1,index);
                            }
                            else{
                               int i=0;
                               while(i< stars-numberOfStars(allLines[index])+1){
                                path[path.size()-2].subFolders.push_back(path[path.size()-1]);
                                path.pop_back();
                                ++i;
                               }

                            fileSystemInputter(path,allLines,numberOfStars(allLines[index]),index);
                            }

                        }
        }

             else{
              QString str=QString::fromStdString(allLines[index]);
                 if(isFile(str)){
                     QString str=QString::fromStdString(fileNameWithoutStars(allLines[index]));
                     File newFile=File(str);
                     path[path.size()-1].subFiles.push_back(newFile);
                     while(path.size()!=1){
                         path[path.size()-2].subFolders.push_back(path[path.size()-1]);
                         path.pop_back();
                     }
                    index++;
                    fileSystemInputter(path,allLines,stars,index);

              }else{
                     QString str=QString::fromStdString(fileNameWithoutStars(allLines[index]));
                         Folder newFolder=Folder(str);
                        path.push_back(newFolder);
                        while(path.size()!=1){
                            path[path.size()-2].subFolders.push_back(path[path.size()-1]);
                            path.pop_back();
                        }
                        index++;
                        fileSystemInputter(path,allLines,stars,index);
                     }
        }

       }

       else{
          return;
       }
   }

//------- RENAME --------//

void FileSystem::RenameFolder(QString n,Folder* nav){

    for (int i = 0; i < nav->subFolders.size(); i++){
        if (nav->subFolders[i].folderName == n) {
            QString newname;
            QInputDialog inp;
            inp.setWindowTitle("File Management System");
            inp.setLabelText("Enter new name for Folder: ");
            inp.setTextValue("Folder Name");
            int ok = inp.exec();
            newname=inp.textValue();
            if (ok == QDialog::DialogCode::Accepted){
                    window3* w3=new window3;
                if (fileOrFolderExists(nav,newname)){
                    if (fileExists(nav,newname)){
                    QMessageBox::warning(w3,"","File with this name already exists");
                    }
                    else {
                        QMessageBox::warning(w3,"","Folder with this name exists already");
                    }
                    break;
                }
                else{
                    nav->subFolders[i].folderName = newname;
                    break;
                }

        }

        }

    }
}
void FileSystem::RenameFile(QString fileToRename, Folder* ptrToCurrentFolder){
    for (int i = 0; i < ptrToCurrentFolder->subFiles.size(); i++){
        if (ptrToCurrentFolder->subFiles[i].fileName==fileToRename){
            QString newname;
            QInputDialog inp;
            inp.setWindowTitle("File Management System");
            inp.setLabelText("Enter new name for File: ");
           inp.setTextValue("File Name");
           int ok = inp.exec();
            newname=inp.textValue();
            if (ok == QDialog::DialogCode::Accepted){
                window3* w3=new window3;
                if (fileOrFolderExists(ptrToCurrentFolder,newname)){
                    if (fileExists(ptrToCurrentFolder,newname)){
                    QMessageBox::warning(w3,"","File with this name already exists");

                    }
                    else {
                        QMessageBox::warning(w3,"","Folder with this name exists already");

                    }
                    break;
                }

                else{
                    ptrToCurrentFolder->subFiles[i].fileName = newname;
                    break;
                }
            }
}

    }
}







//Print Curret Directory
//void FileSystem::printCurrentDirectory(Folder* pointerToCurrentFolder){
//    for(int i=0;i<pointerToCurrentFolder->subFiles.size();++i){
//        cout<<pointerToCurrentFolder->subFiles[i].fileName<<endl;
//    }
//    for(int i=0;i<pointerToCurrentFolder->subFolders.size();++i){
//        cout<<pointerToCurrentFolder->subFolders[i].folderName<<endl;
//    }
//}
