#ifndef WINDOW1_H
#define WINDOW1_H

#include <QDialog>

namespace Ui {
class window1;
}

class window1 : public QDialog
{
    Q_OBJECT

public:
    explicit window1(QWidget *parent = nullptr);
    ~window1();

private slots:
    void on_actionCreate_File_triggered();

private:
    Ui::window1 *ui;
};

#endif // WINDOW1_H
