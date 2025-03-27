/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "halaman.h"

StaticArray dataArray; // Inisialisasi array dipindahkan ke halaman.c

void InitArray(StaticArray *arr) {
    arr->size = 0;
}

/* Fungsi untuk membersihkan layar */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Menampilkan welcome screen */
void welcomeScreen() {
    clearScreen();
    puts("*************************************************************");
    puts("*                    SELAMAT DATANG DI                     *");
    puts("*     PROGRAM MONITORING DAN MANAJEMEN LINKED LIST         *");
    puts("*************************************************************");
    puts("\nTekan Enter untuk melanjutkan...");
    getchar();
}

/* Menampilkan dashboard utama */
void dashboard(RecordArray *recArr) {
    int choice;
    do {
        clearScreen();
        puts("************************** MENU UTAMA **************************");
        puts("1. Tambah Data");
        puts("2. Hapus Data");
        puts("3. Lihat Data");
        puts("4. Keluar");
        printf("Pilihan: ");
        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                tambahData(recArr);
                break;
            case 2:
                hapusData(recArr);
                break;
            case 3:
                lihatData(*recArr);
                break;
            case 4:
                puts("Terima kasih telah menggunakan program ini!");
                break;
            default:
                puts("Pilihan tidak valid! Silakan coba lagi.");
                break;
        }
    } while (choice != 4);
}

/* Fungsi untuk menambahkan data */
void tambahData(RecordArray *recArr) {
    clearScreen();
    puts("************************** TAMBAH DATA **************************");
    puts("1. Tambah Kota");
    puts("2. Tambah Nama Orang ke Kota");
    printf("Pilihan: ");
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("Input tidak valid! Masukkan angka: ");
        while (getchar() != '\n');
    }
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        AddRecord(recArr, kota);
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;

        int found = 0;
        for (int i = 0; i < recArr->size; i++) {
            if (strcmp(recArr->records[i].kota, kota) == 0) {
                printf("Masukkan nama orang: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                AddToLinkedList(&recArr->records[i], nama);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Kota tidak ditemukan!\n");
        }
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* Fungsi untuk menghapus data */
void hapusData(RecordArray *recArr) {
    clearScreen();
    puts("************************** HAPUS DATA **************************");
    puts("1. Hapus Kota");
    puts("2. Hapus Nama Orang dari Kota");
    printf("Pilihan: ");
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("Input tidak valid! Masukkan angka: ");
        while (getchar() != '\n');
    }
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;

        int idx = -1;
        for (int i = 0; i < recArr->size; i++) {
            if (strcmp(recArr->records[i].kota, kota) == 0) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            DeleteRecord(recArr, idx);
        } else {
            printf("Kota tidak ditemukan!\n");
        }
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;

        int found = 0;
        for (int i = 0; i < recArr->size; i++) {
            if (strcmp(recArr->records[i].kota, kota) == 0) {
                printf("Masukkan nama orang: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                DeleteFromLinkedList(&recArr->records[i], nama);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Kota tidak ditemukan!\n");
        }
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* Fungsi untuk melihat data */
void lihatData(RecordArray recArr) {
    clearScreen();
    PrintAllRecords(recArr);
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

