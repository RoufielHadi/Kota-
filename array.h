/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"
#include "linked.h"  // Tambahkan agar `address` dikenali

#define MAX_KOTA 50  // Maksimal jumlah kota dalam array
#define MAXSIZE 100  // Ukuran maksimum array nama

/* *** Type Data *** */
typedef char nama[MAXSIZE];

typedef struct {
    nama namaKota;  // Elemen dalam array untuk menunjuk nama kota
    address p;      // Elemen dalam array untuk menunjuk nama orang yang tinggal di kota tersebut
} kota;

/* Mendefinisikan Type Data Array Kota */
typedef struct {
    kota data[MAX_KOTA]; // Array untuk menyimpan kota
    int size;            // Jumlah kota yang ada dalam array
} Array;

/* *** PROTOTYPE *** */
void Inisialisasi_Array(Array *arr);
/* Tujuan  : Menginisialisasi array agar siap digunakan */
/* IS      : Array belum terisi */
/* FS      : Array memiliki size = 0, siap digunakan */

void Tambah_Kota(Array *arr, char *namaKota, address listPenduduk);
/* Tujuan  : Menambahkan kota ke dalam array beserta daftar penduduknya */
/* IS      : Array mungkin kosong atau berisi beberapa kota */
/* FS      : Kota baru ditambahkan ke dalam array jika belum penuh */

void Hapus_Kota(Array *arr, int index);
/* Tujuan  : Menghapus kota dari array berdasarkan indeks */
/* IS      : Array tidak kosong */
/* FS      : Kota di indeks tertentu dihapus, elemen setelahnya digeser ke kiri */

void Cari_Kota(Array *arr, char *namaKota, int *index);
/* Tujuan  : Mencari kota dalam array berdasarkan nama */
/* IS      : Array tidak kosong */
/* FS      : Jika ditemukan, index diisi dengan posisi kota dalam array, jika tidak -1 */

void Tampilkan_Kota(Array arr);
/* Tujuan  : Menampilkan daftar kota beserta penduduknya */
/* IS      : Array mungkin kosong atau berisi beberapa kota */
/* FS      : Seluruh data kota ditampilkan ke layar */

void Ubah_Nama_Kota(Array *arr, int index, char *namaBaru);
/* Tujuan  : Mengubah nama kota yang ada dalam array */
/* IS      : Array tidak kosong, index valid */
/* FS      : Nama kota pada indeks tertentu diperbarui */

void Urutkan_Kota(Array *arr);
/* Tujuan  : Mengurutkan daftar kota berdasarkan abjad */
/* IS      : Array tidak kosong */
/* FS      : Kota dalam array tersusun secara alfabetis */

void Hapus_Semua_Kota(Array *arr);
/* Tujuan  : Menghapus seluruh kota dari array */
/* IS      : Array berisi beberapa kota */
/* FS      : Array menjadi kosong dengan size = 0 */

void Simpan_Ke_File(Array arr, char *namaFile);
/* Tujuan  : Menyimpan data kota ke dalam file */
/* IS      : Array berisi beberapa kota */
/* FS      : Data kota tersimpan dalam file dengan format tertentu */

void Muat_Dari_File(Array *arr, char *namaFile);
/* Tujuan  : Memuat data kota dari file ke dalam array */
/* IS      : File data kota tersedia */
/* FS      : Array terisi dengan data yang diambil dari file */

#endif

