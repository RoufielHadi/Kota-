/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"

#define MAXSIZE 100 // Ukuran maksimum array nama penduduk

typedef char nama[MAXSIZE];
typedef struct tElmtList *address;
typedef struct tElmtList {
    nama namaPenduduk;
    address next;
} ElmtList;

boolean isEmpty(address q);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node(address *q);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : q (parameter Output)

void Isi_Node(address *q, nama nilai);
// Tujuan : Mengisi node yang sudah dipesan dengan nilai yang dikirimkan
// Periksa keberadaan q, Nilai diisi jika q tidak NULL
// *q->next diisi NULL
// Parameter : q (parameter Input-Output); nilai (parameter Input)

void Tampil_List(address q);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : q (parameter input)

void Ins_Awal(address *q, address PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : q (input-output)
//             PNew (input)

void Ins_Akhir(address *q, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : q mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

address Search(address q, nama nilai);
/* Mencari apakah ada elemen list dengan Info(q) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan NULL */
/* Menggunakan variabel bertipe boolean */

void InsertAfter(address *qBef, address PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) setelah node tertentu(qBef) */
/* IS : qBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah qBef */
/* Asumsi : qBef adalah posisi insert */

void Del_Awal(address *q, nama *X);
/* IS : q TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/*      dan alamat elemen pertama didealokasi */

void Del_Akhir(address *q, nama *X);
/* IS : q TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/*      dan alamat elemen terakhir didealokasi */

void Del_After(address *qBef, nama *X);
/* IS : qBef TIDAK Kosong (hasil search posisi node sebelum yang dihapus) */
/* FS : Menghapus Node setelah qBef */
/*      nilai info node yang dihapus disimpan pada X */
/*      dan alamat elemen setelah qBef didealokasi */

void DeAlokasi(address *q);
/* IS : q terdefinisi */
/* FS : q dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address q ke sistem */

int NbElmt(address q);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursive Mode

#endif

