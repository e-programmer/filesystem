#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <QString>
using namespace std;

class File     //declaration of class
{
public:
    File();
    File(QString);
    QString fileName;
};

#endif // FILE_H
