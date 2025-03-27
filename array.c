/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "array.h"
#include <stdio.h>

/* *** Konstruktor *** */
void CreateArray(StaticArray *arr) {
    arr->size = 0;
}

/* *** Selektor *** */
boolean IsArrayEmpty(StaticArray arr) {
    return arr.size == 0;
}

boolean IsArrayFull(StaticArray arr) {
    return arr.size == MAXSIZE;
}

/* *** Operator *** */
void InsertLast(StaticArray *arr, infotype nilai) {
    if (!IsArrayFull(*arr)) {
        arr->elements[arr->size] = nilai;
        arr->size++;
    }
}

void InsertAt(StaticArray *arr, infotype nilai, int idx) {
    if (!IsArrayFull(*arr) && idx >= 0 && idx <= arr->size) {
        for (int i = arr->size; i > idx; i--) {
            arr->elements[i] = arr->elements[i - 1];
        }
        arr->elements[idx] = nilai;
        arr->size++;
    }
}

void DeleteAt(StaticArray *arr, int idx) {
    if (!IsArrayEmpty(*arr) && idx >= 0 && idx < arr->size) {
        for (int i = idx; i < arr->size - 1; i++) {
            arr->elements[i] = arr->elements[i + 1];
        }
        arr->size--;
    }
}

infotype GetAt(StaticArray arr, int idx) {
    if (idx >= 0 && idx < arr.size) {
        return arr.elements[idx];
    }
    return -1; // Indikasi kesalahan
}

/* *** Pencarian *** */
int SearchElement(StaticArray arr, infotype nilai) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.elements[i] == nilai) {
            return i;
        }
    }
    return -1;
}

/* *** Tampilan *** */
void PrintArray(StaticArray arr) {
    printf("[");
    for (int i = 0; i < arr.size; i++) {
        printf("%d", arr.elements[i]);
        if (i < arr.size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
