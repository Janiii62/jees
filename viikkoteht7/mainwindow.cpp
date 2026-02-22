#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    counter(0),
    state(1)
{

    ui->setupUi(this);

    ui->lineEdit->setText("0");

    connect(ui->countButton, &QPushButton::clicked,
            this, &MainWindow::countClickHandler);

    connect(ui->resetButton, &QPushButton::clicked,
            this, &MainWindow::resetClickHandler);

// tehään laskimen osio tähän perää
// yhdistetään napit toimimaan klikatessa
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);

// muodostetaan mitä tapahtuu eri napeista
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

// yhdistetään clear ja enter napit
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countClickHandler()
{
    counter++;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::resetClickHandler()
{
    counter = 0;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString digit = button->text();

    if(state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString op = button->text();
    if(op == "+") operand = 1;
    else if(op == "-") operand = 2;
    else if(op == "*") operand = 3;
    else if(op == "/") operand = 4;

    state = 2;
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();

    if(name == "clear")
    {
        state = 1;
        number1 = "";
        number2 = "";
        operand = 0;
        result = 0;
        resetLineEdits();
    }
    else if(name == "enter")
    {
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        if(operand == 1) result = n1 + n2;
        else if(operand == 2) result = n1 - n2;
        else if(operand == 3) result = n1 * n2;
        else if(operand == 4) {
            if(n2 != 0) result = n1 / n2;
            else {
                ui->result->setText("Error: /0");
                return;
            }
        }

        ui->result->setText(QString::number(result));
    }
}

void MainWindow::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}
