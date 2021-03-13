#include "towinterface.h"
#include "ui_towinterface.h"
#include "calculator.h"
#include "chatrobot.h"
#include "qtdialog.h"
#include "qtweather.h"
#include "qplayer.h"
Towinterface::Towinterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Towinterface)
{
    ui->setupUi(this);
}

Towinterface::~Towinterface()
{
    delete ui;
}

void Towinterface::on_pushButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}

void Towinterface::on_pushButton_2_clicked()
{
    calculator *cc = new calculator(this);
    cc->show();
   this->hide();
}

void Towinterface::on_pushButton_3_clicked()
{
    chatrobot *bb = new chatrobot(this);
    bb->show();
    this->hide();
}

void Towinterface::on_pushButton_4_clicked()
{
    QtDialog *dd = new QtDialog(this);
    dd->show();
    this->hide();
}

void Towinterface::on_pushButton_5_clicked()
{
    QtWeather *qq = new QtWeather(this);
    qq->show();
    this->hide();
}

void Towinterface::on_pushButton_6_clicked()
{
    QPlayer *mm = new QPlayer(this);
    mm->show();
    this->hide();
}
