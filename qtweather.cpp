#include "qtweather.h"
#include "ui_qtweather.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QMainWindow>
QtWeather::QtWeather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtWeather)
{
    ui->setupUi(this);
    connect(&man,&QNetworkAccessManager::finished,this,&QtWeather::Read_data);
}

QtWeather::~QtWeather()
{
    delete ui;
}

void QtWeather::on_pushButton_clicked()
{
    this->parentWidget()->show();
    delete this;
}

void QtWeather::on_pushButton_2_clicked()
{
    //qurl解析构造编码
    QString str = "http://api.qingyunke.com/api.php?key=free&appid=0&msg=天气";
    QUrl url(str+ui->lineEdit->text());  //将单行输入框内容输入到url
    //创建请求
    QNetworkRequest request(url);
    //发送
    man.get(request);
}
void QtWeather::Read_data(QNetworkReply *app)
{
    QByteArray array = app->readAll();
   // ui->textEdit->setText(QString(array));

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
    QStringList list = name_obj.split("，");
    QString cloud = list[0]; //天气情况
    QString day = list[1];   //白天温度
    QString night = list[2]; //夜晚温度
    QString wind = list[3];  //风向
    QString wind_power=list[4];  //风力
    QString date = list[0];
    date.remove(13,16);
    cloud.remove(0,14);
    //qDebug()<<cloud_a;
    ui->label_12->setText(date);
    ui->label_6->setText(cloud);
    ui->label_8->setText(day);
    ui->label_9->setText(night);
    ui->label_10->setText(wind);
    ui->label_11->setText(wind_power);
}
