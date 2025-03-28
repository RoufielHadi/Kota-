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

/* *** PROTOTYPE *** */

/* *** Fungsi Tampilan Awal *** */
void welcomeScreen();
/* Tujuan  : Menampilkan layar selamat datang */
/* IS      : Layar kosong atau berisi tampilan sebelumnya */
/* FS      : Menampilkan pesan selamat datang dan menunggu input user */

/* *** Fungsi Menu Utama *** */
void dashboard(Array *arr);
/* Tujuan  : Menampilkan menu utama */
/* IS      : Program berjalan */
/* FS      : User dapat memilih opsi yang tersedia dalam menu utama */

/* *** Fungsi Tambah Data *** */
void tambahData(Array *arr);
/* Tujuan  : Menampilkan menu tambah data */
/* IS      : Array mungkin kosong atau berisi beberapa kota dan penduduk */
/* FS      : User dapat memilih untuk menambah kota atau menambah penduduk */

/* *** Fungsi Edit Data *** */
void editData(Array *arr);
/* Tujuan  : Menampilkan menu edit data */
/* IS      : Array mungkin kosong atau berisi beberapa kota dan penduduk */
/* FS      : User dapat mengedit nama kota atau penduduk */

/* *** Fungsi Hapus Data *** */
void hapusData(Array *arr);
/* Tujuan  : Menampilkan menu hapus data */
/* IS      : Array mungkin kosong atau berisi beberapa kota dan penduduk */
/* FS      : User dapat memilih untuk menghapus kota atau penduduk */

/* *** Fungsi Tampilkan Data *** */
void tampilkanData(Array *arr);
/* Tujuan  : Menampilkan menu tampilkan data */
/* IS      : Array mungkin kosong atau berisi beberapa kota dan penduduk */
/* FS      : User dapat memilih untuk melihat semua data atau data kota tertentu */

#endif
