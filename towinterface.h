#ifndef TOWINTERFACE_H
#define TOWINTERFACE_H

#include <QMainWindow>

namespace Ui {
class Towinterface;
}

class Towinterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Towinterface(QWidget *parent = nullptr);
    ~Towinterface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Towinterface *ui;
};

#endif // TOWINTERFACE_H
