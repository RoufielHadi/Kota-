/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "array.h"
#include "linked.h"
#include <stdio.h>
#include <string.h>

/* *** Fungsi Entry (Tambah Data) *** */
void Implementasi_Tambah_Kota(Array *arr, const char *namaKota, address listPenduduk) {
    Tambah_Kota(arr, (char *)namaKota, listPenduduk);
}

void Implementasi_Tambah_Penduduk(Array *arr, const char *namaKota, const char *namaPenduduk) {
    int index;
    Cari_Kota(arr, (char *)namaKota, &index);
    if (index != -1) {
        address newNode;
        Create_Node(&newNode);
        Isi_Node(&newNode, (char *)namaPenduduk);
        Ins_Akhir(&(arr->data[index].p), newNode);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}

/* *** Fungsi Delete (Hapus Data) *** */
void Implementasi_Hapus_Kota(Array *arr, const char *namaKota) {
    int index;
    Cari_Kota(arr, (char *)namaKota, &index);
    if (index != -1) {
        while (arr->data[index].p != NULL) {
            char tempNama[MAXSIZE];
            Del_Awal(&(arr->data[index].p), tempNama);
        }
        Hapus_Kota(arr, index);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}

void Implementasi_Hapus_Penduduk(Array *arr, const char *namaKota, const char *namaPenduduk) {
    int index;
    Cari_Kota(arr, (char *)namaKota, &index);
    if (index != -1 && arr->data[index].p != NULL) {
        address prev = NULL, curr = arr->data[index].p;
        while (curr != NULL && strcmp(curr->namaPenduduk, namaPenduduk) != 0) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            char tempNama[MAXSIZE];
            if (prev == NULL) {
                Del_Awal(&(arr->data[index].p), tempNama);
            } else {
                Del_After(&prev, tempNama);
            }
        } else {
            printf("Penduduk tidak ditemukan.\n");
        }
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}

/* *** Fungsi Tampilkan Data *** */
void Implementasi_Tampilkan_Semua(const Array *arr) {
    if (arr->size == 0) {
        printf("Array kosong.\n");
    } else {
        for (int i = 0; i < arr->size; i++) {
            printf("Kota: %s\nPenduduk:\n", arr->data[i].namaKota);
            Tampil_List(arr->data[i].p);
        }
    }
}

void Implementasi_Tampilkan_Kota(const Array *arr, const char *namaKota) {
    int index;
    Cari_Kota(arr, (char *)namaKota, &index);
    if (index != -1) {
        printf("Kota: %s\nPenduduk:\n", arr->data[index].namaKota);
        Tampil_List(arr->data[index].p);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}

/* *** Fungsi Tambahan *** */
int Implementasi_Hitung_Penduduk_Kota(const Array *arr, const char *namaKota) {
    int index;
    Cari_Kota(arr, (char *)namaKota, &index);
    if (index != -1) {
        return NbElmt(arr->data[index].p);
    }
    return 0;
}

int Implementasi_Hitung_Total_Kota(const Array *arr) {
    return arr->size;
}

int Implementasi_Hitung_Total_Penduduk(const Array *arr) {
    int total = 0;
    for (int i = 0; i < arr->size; i++) {
        total += NbElmt(arr->data[i].p);
    }
    return total;
}

