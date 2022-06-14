#ifndef DISPLAYTREE_H
#define DISPLAYTREE_H

#include <QWidget>
#include "filesystem.h"


namespace Ui {
class displayTree;
}

class displayTree : public QWidget
{
    Q_OBJECT

public:
    explicit displayTree(QWidget *parent = nullptr);
    ~displayTree();
   // vector <QString> allTree;


public slots:
    void on_label_windowIconTextChanged(const QString &iconText);

public :
    void printDirectory(Folder *,int k=0);   //print dir
    void printTree( Folder* ptrToFolder=nullptr,int k=0);  //print tree
    QString labeltext;

public:
    Ui::displayTree *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DISPLAYTREE_H
