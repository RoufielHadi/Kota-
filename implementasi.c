/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

// implementasi.c - Implementation File

#include "implementasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitRecordArray(RecordArray *recArr) {
    recArr->size = 0;
}

void InsertRecord(RecordArray *recArr, char kota[]) {
    if (recArr->size >= MAXSIZE) {
        printf("Error: RecordArray penuh!\n");
        return;
    }
    strcpy(recArr->records[recArr->size].kota, kota);
    recArr->records[recArr->size].linkedData = (List *)malloc(sizeof(List));
    CreateList(recArr->records[recArr->size].linkedData);
    recArr->size++;
}

void RemoveRecord(RecordArray *recArr, int idx) {
    if (idx < 0 || idx >= recArr->size) {
        printf("Error: Indeks tidak valid!\n");
        return;
    }
    if (recArr->records[idx].linkedData != NULL) {
        ClearLinkedList(&recArr->records[idx]);
        free(recArr->records[idx].linkedData);
    }
    for (int i = idx; i < recArr->size - 1; i++) {
        recArr->records[i] = recArr->records[i + 1];
    }
    recArr->size--;
}

void DisplayRecords(RecordArray recArr) {
    for (int i = 0; i < recArr.size; i++) {
        printf("%s:\n", recArr.records[i].kota);
        PrintList(*recArr.records[i].linkedData);
    }
}

void DisplayRecordByCity(RecordArray recArr, char kota[]) {
    for (int i = 0; i < recArr.size; i++) {
        if (strcmp(recArr.records[i].kota, kota) == 0) {
            PrintList(*recArr.records[i].linkedData);
            return;
        }
    }
    printf("Kota tidak ditemukan.\n");
}

int GetLinkedDataCount(Record rec) {
    return ListLength(*rec.linkedData);
}

void GetTotalDataCount(RecordArray recArr, int *totalKota, int *totalNama) {
    *totalKota = recArr.size;
    *totalNama = 0;
    for (int i = 0; i < recArr.size; i++) {
        *totalNama += GetLinkedDataCount(recArr.records[i]);
    }
}

void InsertToLinkedList(Record *rec, char nama[]) {
    InsertLast(rec->linkedData, nama);
}

void RemoveFromLinkedList(Record *rec, char nama[]) {
    DeleteByKey(rec->linkedData, nama);
}

void ClearLinkedList(Record *rec) {
    ClearList(rec->linkedData);
}

void TransformArrayToLinkedList(RecordArray *recArr, char data[][50], int size) {
    for (int i = 0; i < size; i++) {
        InsertRecord(recArr, data[i]);
    }
}

void SaveRecordsToFile(RecordArray recArr, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Tidak bisa membuka file untuk menyimpan!\n");
        return;
    }
    fprintf(file, "%d\n", recArr.size);
    for (int i = 0; i < recArr.size; i++) {
        fprintf(file, "%s\n", recArr.records[i].kota);
        SaveListToFile(*recArr.records[i].linkedData, file);
    }
    fclose(file);
}

void LoadRecordsFromFile(RecordArray *recArr, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Tidak bisa membuka file untuk membaca!\n");
        return;
    }
    fscanf(file, "%d\n", &recArr->size);
    for (int i = 0; i < recArr->size; i++) {
        fscanf(file, "%s\n", recArr->records[i].kota);
        recArr->records[i].linkedData = (List *)malloc(sizeof(List));
        CreateList(recArr->records[i].linkedData);
        LoadListFromFile(recArr->records[i].linkedData, file);
    }
    fclose(file);
}

