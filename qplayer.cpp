#include "qplayer.h"
#include "ui_qplayer.h"
#include <QDebug>
QPlayer::QPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QPlayer)
{
    ui->setupUi(this);
}

QPlayer::~QPlayer()
{
    delete ui;
}

void QPlayer::on_pushButton_clicked()
{
    //通过文本文件对话框添加播放文件
    QStringList movies = QFileDialog::getOpenFileNames(this,"选择视频","/mnt/hgfs");
    //把视频路径添加到列表中
    ui->listWidget->addItems(movies);
}

void QPlayer::on_pushButton_2_clicked()
{
    mprocess.kill();

    mprocess.waitForFinished();
}

void QPlayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //检测到进程在运行直接Kill
    if(mprocess.state() == QProcess::Running)
    {
        mprocess.kill();

        mprocess.waitForFinished();
    }
    //再次获取视频路径
    QString moviesName = item->text();

    QStringList arguments;
    arguments <<"-slave"<<"-quiet"<<"-wid"<<QString::number(ui->label->winId())<<moviesName;
    //启动进程
    mprocess.start("mplayer",arguments);
}

void QPlayer::play_next(int num)
{
    qDebug()<<QString::number(num);
}

void QPlayer::on_pushButton_3_clicked()
{
    this->parentWidget()->show();
    delete this;
}
