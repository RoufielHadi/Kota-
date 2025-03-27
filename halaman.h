/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef HALAMAN_H
#define HALAMAN_H

#include "implementasi.h"

StaticArray dataArray; // Inisialisasi array dipindahkan ke halaman.c

void InitArray(StaticArray *arr) {
    arr->size = 0;
}

/* Fungsi untuk menampilkan welcome screen */
void welcomeScreen();

/* Fungsi untuk menampilkan menu utama */
void dashboard(RecordArray *recArr);

/* Fungsi untuk menambahkan data (kota atau nama orang) */
void tambahData(RecordArray *recArr);

/* Fungsi untuk menghapus data (kota atau nama orang) */
void hapusData(RecordArray *recArr);

/* Fungsi untuk melihat data */
void lihatData(RecordArray recArr);

#endif

