/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include "halaman.h"

int main() {

    // Menampilkan welcome screen
    welcomeScreen();

    // Menampilkan menu utama (dashboard)
    dashboard(&recordArray);

    // Membersihkan semua data sebelum keluar dari program
    clearArray(&recordArray);

    return 0;
}

