#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectSignals();
}

void MainWindow::ConnectSignals()
{
    connect(ui->btn1, &QPushButton::clicked, this, [&]() {  UpdateTotal("1");});
    connect(ui->btn2, &QPushButton::clicked, this, [&]() {  UpdateTotal("2");});
    connect(ui->btn3, &QPushButton::clicked, this, [&]() { UpdateTotal("3");});
    connect(ui->btn4, &QPushButton::clicked, this, [&]() {  UpdateTotal("4");});
    connect(ui->btn5, &QPushButton::clicked, this, [&]() { UpdateTotal("5");});
    connect(ui->btn6, &QPushButton::clicked, this, [&]() {  UpdateTotal("6");});
    connect(ui->btn7, &QPushButton::clicked, this, [&]() {  UpdateTotal("7");});
    connect(ui->btn8, &QPushButton::clicked, this, [&]() {  UpdateTotal("8");});
    connect(ui->btn9, &QPushButton::clicked, this, [&]() {  UpdateTotal("9");});
    connect(ui->btn0, &QPushButton::clicked, this, [&]() {  UpdateTotal("0");});
    connect(ui->btn_Plus, &QPushButton::clicked, this, [&]() { UpdateTotal("+");});
    connect(ui->btn_minus, &QPushButton::clicked, this, [&]() { UpdateTotal("-");});
    connect(ui->btn_multiply, &QPushButton::clicked, this, [&]() { UpdateTotal("*");});
    connect(ui->btn_divide, &QPushButton::clicked, this, [&]() { UpdateTotal("/");});
    connect(ui->btn_equal, &QPushButton::clicked, this, [&]() { UpdateTotal("=");});
    connect(ui->btn_clear, &QPushButton::clicked, this, [&]() { UpdateTotal("CE");});
}

void MainWindow::UpdateTotal(QString oper)
{

    bool ok = false;
    oper.toInt(&ok);
    if(!ok)
    {
        qWarning() << "";
        qWarning() << "prevoper : " << prevoper;
        qWarning() << "current_num : " << current_num;
        qWarning() << "total : " << total;
        switch (prevoper){
        case 0:
            total += current_num;
            break;
        case 1:
            total -= current_num;
            break;
        case 2:
            if(total == 0)
                total=current_num;
            else
                total *= current_num;
            break;
        case 3:
            if(current_num == 0)
            {
                ui->lblscreen->setText("Err");
                break;
            }
            total /= current_num;
            break;

        case 5: //ce
            ui->lblscreen->setText("");
            total = 0;
            prevoper = -1;
            isPrevOper = false;
        default:
            total = current_num;
        }

        if(oper == "=")
        {
            ui->lblscreen->setText(QString::number(total));
            isPrevOper = false;
        }

        else if(oper == "CE")
        {
            ui->lblscreen->setText("");
            total = 0;
            prevoper = -1;
        }
        else {
            isPrevOper = true;
            if(oper == "+") prevoper = 0;
            if(oper == "-") prevoper = 1;
            if(oper == "*") prevoper = 2;
            if(oper == "/") prevoper = 3;
        }


        current_num = 0;
        qWarning() << "current_num : " << current_num;
        qWarning() << "total : " << total;
        qWarning() << "";
    }
    else
    {
        current_num = current_num *10 + oper.toInt();
        ui->lblscreen->setText(QString::number(current_num));
        qWarning() << "current num : " << current_num;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
