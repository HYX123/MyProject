#ifndef QTDIALOG_H
#define QTDIALOG_H

#include <QMainWindow>
#include <QMainWindow>
#include <QFontDialog>
#include  <QColorDialog>

namespace Ui {
class QtDialog;
}

class QtDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtDialog(QWidget *parent = nullptr);
    ~QtDialog();

private slots:
    void on_boxBt_clicked();

    void on_fileBt_clicked();

    void on_colorBt_clicked();

    void on_fontBt_clicked();

    void on_inpuBt_clicked();

    void on_selfBt_clicked();

    void on_pushButton_clicked();

private:
    Ui::QtDialog *ui;
};

#endif // QTDIALOG_H
