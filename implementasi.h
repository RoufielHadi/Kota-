/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

/* ========================================================================
 * Nama File: implementasi.h
 * Deskripsi: Header file untuk operasi RecordArray dan linked list
 * Dibuat oleh: [Nama Anda]
 * Tanggal: [Tanggal Sekarang]
 * ======================================================================== */

#ifndef IMPLEMENTASI_H
#define IMPLEMENTASI_H

#include "array.h"
#include "linked.h"

/* ========================================================================
 * Struktur Data
 * ======================================================================== */

typedef struct {
    char kota[50];            // Nama kota
    List *linkedData;         // Pointer ke linked list
} Record;

typedef struct {
    Record records[MAXSIZE];  // Array berisi record
    int size;                 // Ukuran array
} RecordArray;

/* ========================================================================
 * PROTOTYPE FUNGSI
 * ======================================================================== */

/* Membuat RecordArray kosong */
/* I.S. Sembarang */
/* F.S. RecordArray dengan size 0 terbentuk */
void InitRecordArray(RecordArray *recArr);

/* Menambahkan record baru ke dalam RecordArray */
/* I.S. RecordArray mungkin kosong atau berisi data */
/* F.S. Record baru dengan nama kota ditambahkan ke dalam RecordArray */
void InsertRecord(RecordArray *recArr, char kota[]);

/* Menghapus record dari RecordArray berdasarkan indeks */
/* I.S. RecordArray tidak kosong, indeks valid */
/* F.S. Record pada indeks tersebut dihapus, data bergeser jika perlu */
void RemoveRecord(RecordArray *recArr, int idx);

/* Menampilkan semua record dalam RecordArray */
/* I.S. RecordArray mungkin kosong atau berisi data */
/* F.S. Semua record beserta linked list-nya ditampilkan di layar */
void DisplayRecords(RecordArray recArr);

/* Menampilkan data dalam linked list berdasarkan nama kota */
/* I.S. RecordArray tidak kosong, kota mungkin ada atau tidak */
/* F.S. Jika kota ditemukan, linked list ditampilkan; jika tidak, pesan kesalahan muncul */
void DisplayRecordByCity(RecordArray recArr, char kota[]);

/* Menghitung jumlah data dalam satu linked list record */
/* I.S. Record valid */
/* F.S. Mengembalikan jumlah elemen dalam linked list record */
int GetLinkedDataCount(Record rec);

/* Menghitung total jumlah record dan data dalam seluruh linked list */
/* I.S. RecordArray valid */
/* F.S. totalKota berisi jumlah record, totalNama berisi jumlah total elemen di semua linked list */
void GetTotalDataCount(RecordArray recArr, int *totalKota, int *totalNama);

/* ========================================================================
 * OPERASI LINKED LIST PADA RECORD
 * ======================================================================== */

/* Menambahkan data ke linked list dalam suatu record */
/* I.S. Record valid, nama belum tentu ada */
/* F.S. Nama ditambahkan ke dalam linked list record */
void InsertToLinkedList(Record *rec, char nama[]);

/* Menghapus elemen dari linked list dalam Record */
/* I.S. Record valid, linked list tidak kosong, nama elemen ada */
/* F.S. Elemen dengan nama tersebut dihapus dari linked list */
void RemoveFromLinkedList(Record *rec, char nama[]);

/* Menghapus seluruh elemen dari linked list dalam Record */
/* I.S. Record valid */
/* F.S. Linked list dalam Record dihapus seluruhnya */
void ClearLinkedList(Record *rec);

/* ========================================================================
 * FUNGSI TAMBAHAN
 * ======================================================================== */

/* Mengonversi array menjadi RecordArray dengan linked list kosong */
/* I.S. Array data valid, RecordArray valid */
/* F.S. Setiap elemen array dikonversi menjadi Record dalam RecordArray */
void TransformArrayToLinkedList(RecordArray *recArr, char data[][50], int size);

/* Menyimpan RecordArray ke dalam file */
/* I.S. RecordArray valid */
/* F.S. Data dalam RecordArray disimpan ke dalam file eksternal */
void SaveRecordsToFile(RecordArray recArr, const char *filename);

/* Memuat RecordArray dari file */
/* I.S. File dengan format yang benar tersedia */
/* F.S. RecordArray diisi dengan data dari file */
void LoadRecordsFromFile(RecordArray *recArr, const char *filename);

#endif /* IMPLEMENTASI_H */

