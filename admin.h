#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QList>


namespace Ui {
class MainWindow2;
}

struct Item {
    QString nama;
    QString harga;
    QString stok;
};

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_logout_clicked();
    void displayData();
    void on_tambahkan_clicked();
    void on_edit_clicked();
    void selectionSortData();
    void on_simpan_clicked();
    void on_hapus_clicked();
    void on_urutkan_clicked();

private:
    Ui::MainWindow2 *ui;
    QList<Item> dataArray;

};

#endif // ADMIN_H
