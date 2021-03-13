#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>

namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = nullptr);
    ~calculator();

private slots:
    void back();
    void backbutton();


private:
    Ui::calculator *ui;
    QLineEdit *lineEdit;
    QVBoxLayout *vbox;
    QGridLayout *grid;
    QPushButton *button;
    QPushButton *buttons;

    QString firstnum;
    QString secondnum;

    void InputNum(QString ch);
    void InputTYpe(QString ch);
    void Output();

    int calc=0;
};

#endif // CALCULATOR_H
