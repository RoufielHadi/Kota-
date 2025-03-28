/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "array.h"
#include <stdlib.h>
#include <stdbool.h>  // Pastikan boolean tersedia jika tidak ada di "boolean.h"

/* *** Konstruktor *** */
void Inisialisasi_Array(Array *arr) {
    arr->size = 0;
}

/* *** Operator *** */
void Tambah_Kota(Array *arr, char *namaKota, address listPenduduk) {
    if (arr->size < MAX_KOTA) {
        strncpy(arr->data[arr->size].namaKota, namaKota, MAXSIZE - 1);
        arr->data[arr->size].namaKota[MAXSIZE - 1] = '\0';  // Pastikan string berakhir null
        arr->data[arr->size].p = listPenduduk;
        arr->size++;
    } else {
        printf("Array penuh, tidak bisa menambahkan kota baru.\n");
    }
}

void Hapus_Kota(Array *arr, int index) {
    if (index >= 0 && index < arr->size) {
        for (int i = index; i < arr->size - 1; i++) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->size--;
    } else {
        printf("Indeks tidak valid.\n");
    }
}

void Cari_Kota(Array *arr, char *namaKota, int *index) {
    *index = -1;
    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].namaKota, namaKota) == 0) {
            *index = i;
            return;
        }
    }
}

void Tampilkan_Kota(Array arr) {
    if (arr.size == 0) {
        printf("Array kosong.\n");
    } else {
        for (int i = 0; i < arr.size; i++) {
            printf("Kota: %s\n", arr.data[i].namaKota);
        }
    }
}

void Ubah_Nama_Kota(Array *arr, int index, char *namaBaru) {
    if (index >= 0 && index < arr->size) {
        strncpy(arr->data[index].namaKota, namaBaru, MAXSIZE - 1);
        arr->data[index].namaKota[MAXSIZE - 1] = '\0';
    } else {
        printf("Indeks tidak valid.\n");
    }
}

void Urutkan_Kota(Array *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = i + 1; j < arr->size; j++) {
            if (strcmp(arr->data[i].namaKota, arr->data[j].namaKota) > 0) {
                kota temp = arr->data[i];
                arr->data[i] = arr->data[j];
                arr->data[j] = temp;
            }
        }
    }
}

void Hapus_Semua_Kota(Array *arr) {
    arr->size = 0;
}

void Simpan_Ke_File(Array arr, char *namaFile) {
    FILE *file = fopen(namaFile, "w");
    if (file) {
        for (int i = 0; i < arr.size; i++) {
            fprintf(file, "%s\n", arr.data[i].namaKota);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk ditulis.\n");
    }
}

void Muat_Dari_File(Array *arr, char *namaFile) {
    FILE *file = fopen(namaFile, "r");
    if (file) {
        arr->size = 0;
        while (arr->size < MAX_KOTA && fgets(arr->data[arr->size].namaKota, MAXSIZE, file)) {
            char *newline = strchr(arr->data[arr->size].namaKota, '\n');
            if (newline) {
                *newline = '\0';  // Hapus newline dari fgets
            }
            arr->data[arr->size].p = NULL;  // Inisialisasi pointer penduduk ke NULL
            arr->size++;
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk dibaca.\n");
    }
}

