#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "folder.h"
#include <vector>
#include <iostream>
using namespace std;

class FileSystem
{
    FileSystem();
    FileSystem(QString);
    static FileSystem *m_instance;

public:
    static FileSystem *getInstance(const QString &root = nullptr);
    vector<Folder> system;
     Folder* navigator;
    Folder* tempPath = navigator;
    vector<Folder*> pathToCurrentFolder;
    vector<Folder> folderClipboard; //to store copied folders
    vector<File> fileClipboard;     //to store copied files
    vector<Folder*> copiedNavigatorofFolder; //to store the address of previous navigator in which we previously cut file/folder


    //methods
    void initiateNavigation();
    void createFile(Folder*,QString);
    bool folderExists(const Folder*,QString);
    void createFolder(Folder*,QString);
    void navigateInto(QString);
    bool fileExists(const Folder*, QString);
    bool fileOrFolderExists(const Folder*,QString);
    bool isEmpty(Folder*);
    bool isFile(QString);
    QString printRoot();
    void printCurrentPath(vector<Folder*>);
    void printCurrentDirectory(Folder*);       //print current dir
    void deleteFolder(Folder*,QString);
    void deleteFile(Folder*,QString);
    Folder copyFolderFunction(Folder*,QString);
    void copyFolderRecursion(Folder*,Folder*);
    void getFileSystem(QString,Folder* pointerToCurrentFolder=NULL);
    void fileSystemMaker(QString,Folder*,int k=0);
    int numberOfStars(string);
    string fileNameWithoutStars(string);
    void inputFileSystem(string,string,Folder* pointerToCurrentFolder=NULL);
    void fileSystemInputter(vector<Folder> &path,vector<string>,int stars=0,int index=0);
    void RenameFolder(QString,Folder*);
    void RenameFile(QString,Folder*);

   // Folder cutFolderFuction(Folder*,QString);
   // void cutFolderRecursion(Folder*,Folder*);
};

#endif // FILESYSTEM_H
