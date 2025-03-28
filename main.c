/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "halaman.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Array dataArray; 
    Inisialisasi_Array(&dataArray); 

    welcomeScreen();
    dashboard(&dataArray);

    return 0;
}

