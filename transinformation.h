#ifndef TRANSINFORMATION_H
#define TRANSINFORMATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class transinformation; }
QT_END_NAMESPACE

class transinformation : public QMainWindow
{
    Q_OBJECT

public:
    transinformation(QWidget *parent = nullptr);
    ~transinformation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::transinformation *ui;
};
#endif // TRANSINFORMATION_H
