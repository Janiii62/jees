#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

// ekan tehtävän osat
    int counter;
    void countClickHandler();
    void resetClickHandler();

// toisen tehtävän osat
    QString number1, number2;
    int state;       // 1 = number1, 2 = number2
    float result;
    short operand;   // 1=+, 2=-, 3=*, 4=/

    void numberClickHandler();
    void addSubMulDivClickHandler();
    void clearAndEnterClickHandler();
    void resetLineEdits();
};

#endif // MAINWINDOW_H
