#ifndef ACTUALMAINWINDOW_H
#define ACTUALMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ActualMainWindow;
}

class ActualMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ActualMainWindow(QWidget *parent = nullptr);
    ~ActualMainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ActualMainWindow *ui;
};

#endif // ACTUALMAINWINDOW_H
