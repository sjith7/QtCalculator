#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {

class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void ConnectSignals();
    void UpdateTotal(QString oper);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool isPrevOper = false;
    double total = 0;
    int prevoper = -1;
    double current_num = 0;
    enum a { red, green , blue};
    enum a dd;

};
#endif // MAINWINDOW_H
