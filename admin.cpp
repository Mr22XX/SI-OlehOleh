#include "admin.h"
#include "ui_admin.h"
#include "login.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QPixmap pix1("D:/rayhan/Documents/SiOlehOleh/image/logo.png");
    ui->label_2->setPixmap(pix1);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_logout_clicked()
{
    this->hide();
    QMessageBox::information(this, "Si Oleh Oleh", "Terima Kasih");
    MainWindow *login = new MainWindow();
    login->show();
}


void MainWindow2::on_tambahkan_clicked()
{
    QString nama = ui->namaBarang->text();
    QString harga = ui->hargaBarang->text();
    QString stok = ui->stokBarang->text();

    if(nama.isEmpty() || harga.isEmpty() || stok.isEmpty()){
        QMessageBox::warning(this, "Si Oleh Oleh", "Data tidak boleh kosong");
        return;
    }

    Item newItem = {nama, harga, stok};
    dataArray.append(newItem);
    ui->namaBarang->clear();
    ui->hargaBarang->clear();
    ui->stokBarang->clear();

    // Menampilkan data setelah ditambahkan
    displayData();

}

void MainWindow2::displayData()
{
        // Menghapus semua baris sebelum menambahkan data baru
        ui->tableWidget->setRowCount(0);

        // Menambahkan baris baru ke tabel
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        for (int i = 0; i < dataArray.size(); ++i) {
            const Item &item = dataArray.at(i);
            // Menambahkan baris baru ke tabel
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            // Menetapkan nilai ke setiap sel dalam tabel


            QTableWidgetItem *namaItem = new QTableWidgetItem(item.nama);
            ui->tableWidget->setItem(i, 0, namaItem);

            QTableWidgetItem *hargaItem = new QTableWidgetItem(item.harga);
            ui->tableWidget->setItem(i, 1, hargaItem);

            QTableWidgetItem *stokItem = new QTableWidgetItem(item.stok);
            ui->tableWidget->setItem(i, 2, stokItem);

    }

}

void MainWindow2::on_edit_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Peringatan", "Pilih sebuah baris untuk diedit.");
        return;
    }

    // Mendapatkan data dari baris yang dipilih
    QString nama = ui->tableWidget->item(currentRow, 0)->text();
    QString harga = ui->tableWidget->item(currentRow, 1)->text();
    QString stok = ui->tableWidget->item(currentRow, 2)->text();

    // Menetapkan nilai kolom ke widget input
    ui->namaBarang->setText(nama);
    ui->hargaBarang->setText(harga);
    ui->stokBarang->setText(stok);
}


void MainWindow2::on_simpan_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Peringatan", "Pilih sebuah baris untuk diedit.");
        return;
    }

    // Mendapatkan data yang diedit dari widget input
    QString nama = ui->namaBarang->text();
    QString harga = ui->hargaBarang->text();
    QString stok = ui->stokBarang->text();

    // Memeriksa apakah semua input telah diisi
    if (nama.isEmpty() || harga.isEmpty() || stok.isEmpty()) {
        QMessageBox::warning(this, "Peringatan", "Mohon lengkapi semua kolom.");
        return;
    }

    // Memperbarui data di dataArray
    Item &editedItem = dataArray[currentRow];
    editedItem.nama = nama;
    editedItem.harga = harga;
    editedItem.stok = stok;

    // Memperbarui nilai di QTableWidget
    ui->tableWidget->item(currentRow, 0)->setText(nama);
    ui->tableWidget->item(currentRow, 1)->setText(harga);
    ui->tableWidget->item(currentRow, 2)->setText(stok);

    // Membersihkan widget input setelah penyimpanan
    ui->namaBarang->clear();
    ui->hargaBarang->clear();
    ui->stokBarang->clear();
}


void MainWindow2::on_hapus_clicked()
{
    // Memeriksa apakah ada baris yang dipilih
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Peringatan", "Pilih sebuah baris untuk dihapus.");
        return;
    }

    // Konfirmasi pengguna sebelum menghapus data
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Konfirmasi", "Anda yakin ingin menghapus data ini?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Menghapus data dari dataArray
    dataArray.removeAt(currentRow);

    // Menghapus baris dari QTableWidget
    ui->tableWidget->removeRow(currentRow);

    QMessageBox::information(this, "Info", "Data berhasil dihapus.");
}


void MainWindow2::on_urutkan_clicked()
{
    // Memanggil fungsi untuk mengurutkan dataArray menggunakan selection sort
    selectionSortData();

    // Menampilkan kembali data yang sudah diurutkan
    displayData();
}

void MainWindow2::selectionSortData()
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

