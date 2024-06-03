#include "user.h"
#include "ui_user.h"
#include <QMessageBox>
#include "login.h"
#include <QPixmap>
#include <QMessageBox>


MainWindow3::MainWindow3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    QMessageBox::warning(this, "Si Oleh Oleh", "Isi data dengan benar karena tidak dapat diubah kecuali meminta admin.");
    QPixmap pix1("D:/rayhan/Documents/SiOlehOleh/image/logo.png");
    ui->label_21->setPixmap(pix1);
}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_logout_clicked()
{
    this->hide();
    QMessageBox::information(this, "Si Oleh Oleh", "Terima Kasih");
    MainWindow *login = new MainWindow();
    login->show();
}

void MainWindow3::displayData()
{
    // Menghapus semua baris sebelum menambahkan data baru
    ui->tableWidget_2->setRowCount(0);

    // Menambahkan baris baru ke tabel
    ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());

    for (int i = 0; i < dataArray.size(); ++i) {
        const Barang &item = dataArray.at(i);
        // Menambahkan baris baru ke tabel
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());

        // Menetapkan nilai ke setiap sel dalam tabel


        QTableWidgetItem *namaItem = new QTableWidgetItem(item.nama);
        ui->tableWidget_2->setItem(i, 0, namaItem);

        QTableWidgetItem *hargaItem = new QTableWidgetItem(item.harga);
        ui->tableWidget_2->setItem(i, 1, hargaItem);

        QTableWidgetItem *stokItem = new QTableWidgetItem(item.stok);
        ui->tableWidget_2->setItem(i, 2, stokItem);

    }

}

void MainWindow3::on_tambahkan_clicked()
{
    QString nama = ui->namaBarang->text();
    QString harga = ui->hargaBarang->text();
    QString stok = ui->stokBarang->text();

    if(nama.isEmpty() || harga.isEmpty() || stok.isEmpty()){
        QMessageBox::warning(this, "Si Oleh Oleh", "Data tidak boleh kosong");
        return;
    }

    Barang newItem = {nama, harga, stok};
    dataArray.append(newItem);
    ui->namaBarang->clear();
    ui->hargaBarang->clear();
    ui->stokBarang->clear();

    // Menampilkan data setelah ditambahkan
    displayData();
}


void MainWindow3::on_urutkan_clicked()
{
    selectionSortData();

    // Menampilkan kembali data yang sudah diurutkan
    displayData();
}

void MainWindow3::selectionSortData()
{
    int n = dataArray.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            // Membandingkan nama barang untuk pengurutan
            if (dataArray[j].nama < dataArray[minIndex].nama) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Menukar elemen jika ditemukan yang lebih kecil
            qSwap(dataArray[i], dataArray[minIndex]);
        }
    }
}


