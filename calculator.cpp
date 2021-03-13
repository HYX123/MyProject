#include "calculator.h"
#include "ui_calculator.h"
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
calculator::calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);

    this->vbox = new QVBoxLayout(ui->centralwidget);
    this->lineEdit = new QLineEdit();
    this->lineEdit->setMinimumHeight(60);
    this->lineEdit->setAlignment(Qt::AlignRight);
    this->vbox->addWidget(lineEdit);
    this->grid = new QGridLayout();
    this->button = new QPushButton[16];
    QString sty = "789/456*123-=0.+";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            button[i*4+j].setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            grid->addWidget(button+i*4+j,i,j);
           button[i*4+j].setText(sty.at(i*4+j));
            connect(button+i*4+j,&QPushButton::clicked,this,&calculator::back);

        }
    }
    this->vbox->addLayout(grid);
    this->buttons = new QPushButton("返回");
    this->vbox->addWidget(buttons);
    connect(buttons,&QPushButton::clicked,this,&calculator::backbutton);
}

calculator::~calculator()
{


    delete []this->button;
    delete grid;
    delete lineEdit;
    delete vbox;
    delete buttons;
    delete ui;

}

void calculator::back()
{
    QPushButton *bt = static_cast<QPushButton *>(sender());
    QString ch = bt->text();
    if(QString("0123456789.").indexOf(ch)>=0)
    {
        InputNum(ch);
    }
   else if(QString("+-*/").indexOf(ch)>=0)
    {
        InputTYpe(ch);
    }
    else
    {
        Output();
    }
}

void calculator::backbutton()
{
    this->parentWidget()->show();
    delete this;
}

void calculator::InputNum(QString ch)
{
    if(calc==0)
    {
        firstnum.append(ch);
        lineEdit->setText(firstnum);
    }
    else
    {
        secondnum.append(ch);
        lineEdit->setText(secondnum);
    }
}

void calculator::InputTYpe(QString ch)
{
    switch(ch.at(0).toLatin1())
    {
        case '+': calc=1;break;
        case '-': calc=2;break;
        case '*': calc=3;break;
        case '/': calc=4;break;
        default:break;
    }
}

void calculator::Output()
{
    QString str;
    switch(calc)
    {
        case 1: str=QString(firstnum+"+"+secondnum+"="+QString::number(firstnum.toDouble()+secondnum.toDouble()));
                break;
    case 2: str=QString(firstnum+"-"+secondnum+"="+QString::number(firstnum.toDouble()-secondnum.toDouble()));
            break;
    case 3: str=QString(firstnum+"*"+secondnum+"="+QString::number(firstnum.toDouble()*secondnum.toDouble()));
            break;
    case 4: str=QString(firstnum+"/"+secondnum+"="+QString::number(firstnum.toDouble()/secondnum.toDouble()));
            break;
    default:break;
    }
    calc=0;
    lineEdit->setText(str);
    firstnum.clear();
    secondnum.clear();
}


