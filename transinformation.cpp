#include "transinformation.h"
#include "ui_transinformation.h"
#include "towinterface.h"
transinformation::transinformation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::transinformation)
{
    ui->setupUi(this);
}

transinformation::~transinformation()
{
    delete ui;
}


void transinformation::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString psd = ui->lineEdit_2 ->text();
    if(user == "123456" && psd == "123456")
    {
        Towinterface *ww=new Towinterface(this);
        ww->show();

        this->hide();
    }
}

void transinformation::on_pushButton_2_clicked()
{
    QApplication *app;
    app->quit();
}
