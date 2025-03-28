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

/* *** Fungsi untuk membersihkan layar *** */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* *** Fungsi Tampilan Awal *** */
void welcomeScreen() {
    clearScreen();
    puts("*************************************************************");
    puts("*                    SELAMAT DATANG DI                     *");
    puts("*     PROGRAM MONITORING DAN MANAJEMEN LINKED LIST         *");
    puts("*************************************************************");
    puts("\nTekan Enter untuk melanjutkan...");
    getchar();
}

/* *** Fungsi Menu Utama *** */
void dashboard(Array *arr) {
    int choice;
    do {
        clearScreen();
        puts("************************** MENU UTAMA **************************");
        puts("1. Tambah Data");
        puts("2. Edit Data");
        puts("3. Hapus Data");
        puts("4. Tampilkan Data");
        puts("5. Keluar");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                tambahData(arr);
                break;
            case 2:
                editData(arr);
                break;
            case 3:
                hapusData(arr);
                break;
            case 4:
                tampilkanData(arr);
                break;
            case 5:
                puts("Terima kasih telah menggunakan program ini!");
                break;
            default:
                puts("Pilihan tidak valid! Silakan coba lagi.");
                break;
        }
    } while (choice != 5);
}

/* *** Fungsi Tambah Data *** */
void tambahData(Array *arr) {
    clearScreen();
    puts("************************** TAMBAH DATA **************************");
    puts("1. Tambah Kota");
    puts("2. Tambah Penduduk");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Tambah_Kota(arr, kota, NULL);
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        printf("Masukkan nama penduduk: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;
        Implementasi_Tambah_Penduduk(arr, kota, nama);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Edit Data *** */
void editData(Array *arr) {
    clearScreen();
    puts("************************** EDIT DATA **************************");
    puts("Program Dalam Pengembangan");

    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Hapus Data *** */
void hapusData(Array *arr) {
    clearScreen();
    puts("************************** HAPUS DATA **************************");
    puts("1. Hapus Kota");
    puts("2. Hapus Penduduk");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Hapus_Kota(arr, kota);
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        printf("Masukkan nama penduduk: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;
        Implementasi_Hapus_Penduduk(arr, kota, nama);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Tampilkan Data *** */
void tampilkanData(Array *arr) {
    clearScreen();
    puts("************************** TAMPILKAN DATA **************************");
    puts("1. Tampilkan Semua Data");
    puts("2. Tampilkan Data Kota Tertentu");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        Implementasi_Tampilkan_Semua(arr);
    } else if (choice == 2) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Tampilkan_Kota(arr, kota);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

