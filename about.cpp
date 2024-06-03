#include "about.h"
#include "ui_about.h"
#include "login.h"

About::About(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_back_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

