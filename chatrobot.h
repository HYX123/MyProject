#ifndef CHATROBOT_H
#define CHATROBOT_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QString>
#include <QByteArray>   //数组
namespace Ui {
class chatrobot;
}

class chatrobot : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatrobot(QWidget *parent = nullptr);
    ~chatrobot();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    //创建一个接收服务器返回数据
    void Read_data(QNetworkReply *app);

private:
    Ui::chatrobot *ui;
    //创建管理类对象
    QNetworkAccessManager man;
};

#endif // CHATROBOT_H
