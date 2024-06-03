#include "login.h"
#include "./ui_login.h"
#include <QPixmap>
#include "about.h"
#include "admin.h"
#include "user.h"
#include <QMessageBox>
#include <QApplication>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("D:/rayhan/Documents/SiOlehOleh/image/logo.png");
    ui->label_2->setPixmap(pix1);
    QPixmap pix2("D:/rayhan/Documents/SiOlehOleh/image/logo_login.png");
    ui->label_6->setPixmap(pix2);
    ui->password->setEchoMode(QLineEdit::Password);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_about_clicked()
{
    this->hide();
    About *about = new About();
    about->show();

}


void MainWindow::on_pushButton_clicked()
{
    QString UserName = ui->username->text();
    QString Password = ui->password->text();
    if(UserName.isEmpty() || Password.isEmpty()){
        QMessageBox::critical(this, "Error", "Username dan Password harus diisi!");
        return;
    }
    if(UserName == "admin" && Password == "1234"){
        QMessageBox::information(this, "Si Oleh Oleh", "Login Success");
        this->hide();
        MainWindow2 *admin = new MainWindow2();
        admin->show();
    }
    else if (UserName == "davi" && Password == "daviganteng"){
        QMessageBox::information(this, "Si Oleh Oleh", "Login Success");
        this->hide();
        MainWindow3 *user = new MainWindow3();
        user->show();
    }
    else{
         QMessageBox::critical(this, "Error", "Username atau Password salah!");
    }
}


void MainWindow::on_Exit_clicked()
{
    qApp->exit();
}

