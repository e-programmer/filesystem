#ifndef FOLDER_H
#define FOLDER_H

#include "file.h"
#include <vector>
#include <QString>



class Folder
{
public:
    Folder();
    QString folderName;
    vector<Folder> subFolders; //vector of type Folder
    vector<File> subFiles;  //vector of type File
    Folder(QString);

};

#endif // FOLDER_H
