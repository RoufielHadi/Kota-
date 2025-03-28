/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef IMPLEMENTASI_H
#define IMPLEMENTASI_H

#include "array.h"
#include "linked.h"

/* *** PROTOTYPE *** */

/* *** Fungsi Entry (Tambah Data) *** */
void Implementasi_Tambah_Kota(Array *arr, const char *namaKota, address listPenduduk);
/* Tujuan  : Menambahkan kota baru ke dalam array jika belum penuh */
/* IS      : Array mungkin kosong atau berisi beberapa kota */
/* FS      : Kota baru ditambahkan ke dalam array */

void Implementasi_Tambah_Penduduk(Array *arr, const char *namaKota, const char *namaPenduduk);
/* Tujuan  : Menambahkan penduduk ke dalam linked list dari kota tertentu */
/* IS      : Kota sudah ada dalam array */
/* FS      : Penduduk baru ditambahkan ke dalam linked list kota yang sesuai */

/* *** Fungsi Delete (Hapus Data) *** */
void Implementasi_Hapus_Kota(Array *arr, const char *namaKota);
/* Tujuan  : Menghapus kota beserta seluruh penduduknya */
/* IS      : Kota sudah ada dalam array */
/* FS      : Kota dan seluruh penduduknya dihapus dari array */

void Implementasi_Hapus_Penduduk(Array *arr, const char *namaKota, const char *namaPenduduk);
/* Tujuan  : Menghapus penduduk dari linked list dalam kota tertentu */
/* IS      : Kota dan penduduk yang ingin dihapus sudah ada dalam array */
/* FS      : Penduduk tertentu dihapus dari linked list kota yang sesuai */

/* *** Fungsi Tampilkan Data *** */
void Implementasi_Tampilkan_Semua(const Array *arr);
/* Tujuan  : Menampilkan seluruh kota beserta daftar penduduknya */
/* IS      : Array mungkin kosong atau berisi beberapa kota */
/* FS      : Semua data kota dan penduduk ditampilkan */

void Implementasi_Tampilkan_Kota(const Array *arr, const char *namaKota);
/* Tujuan  : Menampilkan penduduk dari kota tertentu */
/* IS      : Kota yang dicari sudah ada dalam array */
/* FS      : Daftar penduduk dari kota yang dicari ditampilkan */

/* *** Fungsi Tambahan *** */
int Implementasi_Hitung_Penduduk_Kota(const Array *arr, const char *namaKota);
/* Tujuan  : Menghitung jumlah penduduk di satu kota */
/* IS      : Kota sudah ada dalam array */
/* FS      : Jumlah penduduk dalam kota dikembalikan sebagai output */

int Implementasi_Hitung_Total_Kota(const Array *arr);
/* Tujuan  : Menghitung total jumlah kota dalam array */
/* IS      : Array mungkin kosong atau berisi beberapa kota */
/* FS      : Jumlah kota dalam array dikembalikan sebagai output */

int Implementasi_Hitung_Total_Penduduk(const Array *arr);
/* Tujuan  : Menghitung total seluruh penduduk dari semua kota */
/* IS      : Array mungkin kosong atau berisi beberapa kota dengan penduduknya */
/* FS      : Jumlah seluruh penduduk dalam semua kota dikembalikan sebagai output */

#endif

