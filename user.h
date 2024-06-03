#ifndef USER_H
#define USER_H

#include <QMainWindow>

namespace Ui {
class MainWindow3;
}

struct Barang {
    QString nama;
    QString harga;
    QString stok;
};

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private slots:
    void on_logout_clicked();
    void displayData();

    void on_tambahkan_clicked();
    void selectionSortData();
    void on_urutkan_clicked();

private:
    Ui::MainWindow3 *ui;
    QList<Barang> dataArray;
};

#endif // USER_H
