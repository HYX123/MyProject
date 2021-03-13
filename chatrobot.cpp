#include "chatrobot.h"
#include "ui_chatrobot.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QMainWindow>
chatrobot::chatrobot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatrobot)
{
    ui->setupUi(this);
    connect(&man,&QNetworkAccessManager::finished,this,&chatrobot::Read_data);
}

chatrobot::~chatrobot()
{
    delete ui;
}

void chatrobot::on_pushButton_clicked()
{
     this->parentWidget()->show();
      delete this;
}

void chatrobot::on_pushButton_2_clicked()
{
    //qurl解析构造编码
    QString str = "http://api.qingyunke.com/api.php?key=free&appid=0&msg=";
    QUrl url(str+ui->lineEdit->text());  //将单行输入框内容输入到url
    //创建请求
    QNetworkRequest request(url);
    //发送
    man.get(request);
}

void chatrobot::Read_data(QNetworkReply *app)
{
    QByteArray array = app->readAll();
    ui->textEdit->setText(QString(array));

    //判断是否为json数据
    QJsonParseError error;

    //对JSON数据进行解析
    QJsonDocument doc = QJsonDocument::fromJson(array,&error);

    if(error.error != QJsonParseError::NoError)
    {
        qDebug()<<"data error";
        return;
    }
    QJsonObject obj = doc.object();
    QString name_obj = obj.value("content").toString();

    ui->label->setText(name_obj);
}
