#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_about_clicked();
    void on_pushButton_clicked();
    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // LOGIN_H
