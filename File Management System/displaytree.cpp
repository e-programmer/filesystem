#include "displaytree.h"
#include "ui_displaytree.h"
#include <QInputDialog>
#include <QMessageBox>

displayTree::displayTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayTree)
{
    ui->setupUi(this);
    QPixmap pix(":/rec/icons/free-tree-icon-1578-thumb.png");
     ui->pic->setPixmap(pix.scaled(400,400,Qt::KeepAspectRatio));
     QFont font1=ui->finaltext->font();
     font1.setPointSize(14);
     ui->finaltext->setFont(font1);
}

displayTree::~displayTree()
{
    delete ui;
}


void displayTree::on_label_windowIconTextChanged(const QString &iconText)
{
  //  iconText= ui->label->text();
//   for (int i=1;i<allTree.size();i++){
//       iconText.append(allTree[i]);
//   }
    ui->label->setText(iconText);
    QFont font= ui->label->font();
    font.setPointSize(10);
    ui->label->setFont(font);
    show();

}

void displayTree::printTree(Folder* pointerToFolder,int k){
 labeltext= ui->label->text();
    if(pointerToFolder==NULL){
   printDirectory(&FileSystem::getInstance()->system[0]);
   }
   else{
     printDirectory(pointerToFolder);
   }
   on_label_windowIconTextChanged(labeltext);

}

void displayTree::printDirectory(Folder *pointerToFolder,int k){

    for(int q=0;q<pointerToFolder->subFiles.size();++q){
        for(int u=0;u<k;++u){
            labeltext.append("\t");
        }
        labeltext.append(pointerToFolder->subFiles[q].fileName);
        labeltext.append("\n");
    }
    for(int i=0;i<pointerToFolder->subFolders.size();++i){
        for(int j=0;j<k;++j){
            labeltext.append("\t");
        }
        labeltext.append(pointerToFolder->subFolders[i].folderName);
        labeltext.append("\n");
        if(!FileSystem::getInstance()->isEmpty(&pointerToFolder->subFolders[i])){
                ++k;
                printDirectory(&(pointerToFolder->subFolders[i]),k);
                --k;
        }
    }

}

void displayTree::on_pushButton_clicked()
{
    QInputDialog inp;
    inp.setWindowTitle("File Management System");
    inp.setLabelText("Type name of file to paste the structure into (with .txt extension)");
    inp.setTextValue("Folder Name");
    int ok = inp.exec();
    QString fileName = inp.textValue();
    if (ok == QDialog::DialogCode::Accepted){
        if (!FileSystem::getInstance()->isFile(fileName)){ //if it is not with .txt extension
            QMessageBox::warning(this,"","Extension not found");
        }
        FileSystem::getInstance()->getFileSystem(fileName);
    }
}

void displayTree::on_pushButton_2_clicked()
{
//    QInputDialog inp;
//    inp.setWindowTitle("File Management System");
//    inp.setLabelText("Type name of file to paste the structure into (with .txt extension)");
//    inp.setTextValue("Folder Name");
//    int ok = inp.exec();
//    QString fileName = inp.textValue();
//    if (ok == QDialog::DialogCode::Accepted){
//        if (!FileSystem::getInstance()->isFile(fileName)){ //if it is not with .txt extension
//            QMessageBox::warning(this,"","Extension not found");
//        }
     // std::string str=fileName.toStdString();
        FileSystem::getInstance()->inputFileSystem(".txt","C");
        printTree();

}
