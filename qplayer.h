#ifndef QPLAYER_H
#define QPLAYER_H

#include <QMainWindow>
#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QListWidget>
namespace Ui {
class QPlayer;
}

class QPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QPlayer(QWidget *parent = nullptr);
    ~QPlayer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void play_next(int num);

    void on_pushButton_3_clicked();

private:
    Ui::QPlayer *ui;
    QProcess mprocess;
};

#endif // QPLAYER_H
