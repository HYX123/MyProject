#include "qtdialog.h"
#include "ui_qtdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>
#include <QString>
#include <QInputDialog>
QtDialog::QtDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtDialog)
{
    ui->setupUi(this);
}

QtDialog::~QtDialog()
{
    delete ui;
}

void QtDialog::on_boxBt_clicked()
{
    //调用信息对话框类，对话框warning,question,information
   int set = QMessageBox::warning(this,"wrong","are you sure to exit?",QMessageBox::Yes,QMessageBox::No);
    if(set==QMessageBox::Yes)
    {
       qDebug()<<set;
    }
}

void QtDialog::on_fileBt_clicked()
{
    //调用文本对话框类,返回打开文件路径
    QString file = QFileDialog::getOpenFileName(this,"choose file","/home/gec");
    qDebug()<<file;

    ui->lineEdit->setText(file);
}

void QtDialog::on_colorBt_clicked()
{
    QColor color = QColorDialog::getColor();
    QString rgb = QString("background-color:%1").arg(color.name());
    qDebug()<<rgb;
    ui->textEdit->setStyleSheet(rgb);
}

void QtDialog::on_fontBt_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
}

void QtDialog::on_inpuBt_clicked()
{
    QString text = QInputDialog::getText(this,"Insert in you want","Insert please",QLineEdit::Password);
     qDebug()<<text;
     ui->textEdit->setText(text);
}

void QtDialog::on_selfBt_clicked()
{
    QDialog dialog;
    dialog.setWindowTitle("selfdialog2.0");
    dialog.resize(200,100);

    QPushButton yesbt("Yes",&dialog);
    yesbt.setGeometry(0,40,100,40);
    QPushButton nobt("Yes",&dialog);
    nobt.setGeometry(100,40,100,40);


    connect(&yesbt,&QPushButton::clicked,&dialog,&QDialog::accept);
    connect(&nobt,&QPushButton::clicked,&dialog,&QDialog::reject);
     int ret = dialog.exec();
     if(ret == QDialog::Accepted)
     {
         qDebug()<<"YES  YES";
     }
     if(ret == QDialog::Rejected)
     {
         qDebug()<<"NO  NO";
     }
}

void QtDialog::on_pushButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}
