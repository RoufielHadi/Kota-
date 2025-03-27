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

#include "boolean.h"

#define MAXSIZE 100 // Ukuran maksimum array

/* *** Type Data *** */
typedef int infotype;
typedef struct {
    infotype elements[MAXSIZE]; // Elemen array
    int size;                   // Jumlah elemen dalam array
} StaticArray;

/* *** PROTOTYPE *** */

void CreateArray(StaticArray *arr);
/* *** Konstruktor *** */
/* Membuat array kosong */
/* I.S. sembarang */
/* F.S. Terbentuk array dengan size = 0 */

boolean IsArrayEmpty(StaticArray arr);
/* *** Selektor *** */
/* Mengembalikan true jika array kosong */
/* I.S. Array terdefinisi */
/* F.S. Mengembalikan true jika size = 0 */

boolean IsArrayFull(StaticArray arr);
/* Mengembalikan true jika array penuh */
/* I.S. Array terdefinisi */
/* F.S. Mengembalikan true jika size = MAXSIZE */

void InsertLast(StaticArray *arr, infotype nilai);
/* *** Operator *** */
/* Menambahkan elemen di akhir array */
/* I.S. Array tidak penuh */
/* F.S. Elemen nilai ditambahkan di posisi terakhir array */

void InsertAt(StaticArray *arr, infotype nilai, int idx);
/* Menambahkan elemen di indeks tertentu */
/* I.S. Array tidak penuh, indeks valid */
/* F.S. Elemen nilai disisipkan pada indeks idx, elemen setelah idx bergeser */

void DeleteAt(StaticArray *arr, int idx);
/* Menghapus elemen di indeks tertentu */
/* I.S. Array tidak kosong, indeks valid */
/* F.S. Elemen pada indeks idx dihapus, elemen setelah idx bergeser */

infotype GetAt(StaticArray arr, int idx);
/* Mengambil elemen pada indeks tertentu */
/* I.S. Array tidak kosong, indeks valid */
/* F.S. Mengembalikan elemen pada indeks idx */

int SearchElement(StaticArray arr, infotype nilai);
/* *** Pencarian *** */
/* Mencari indeks elemen tertentu */
/* I.S. Array tidak kosong */
/* F.S. Mengembalikan indeks elemen nilai jika ditemukan, -1 jika tidak */

void PrintArray(StaticArray arr);
/* *** Tampilan *** */
/* Menampilkan isi array ke layar */
/* I.S. Array terdefinisi */
/* F.S. Isi array ditampilkan dengan format [elemen1, elemen2, ...] */

#endif
