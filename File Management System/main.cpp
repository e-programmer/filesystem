#include "actualmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //object of qapplication

    ActualMainWindow w;     //object of class i.e will be a window
    w.show();                   //show window

    return a.exec();            //finally execute our application
}
