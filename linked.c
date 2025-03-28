/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "linked.h"
#include <stdlib.h>

boolean isEmpty(address q) {
    return (q == NULL);
}

void Create_Node(address *q) {
    *q = (address)malloc(sizeof(ElmtList));
    if (*q != NULL) {
        (*q)->next = NULL;
    }
}

void Isi_Node(address *q, nama nilai) {
    if (*q != NULL) {
        strcpy((*q)->namaPenduduk, nilai);
        (*q)->next = NULL;
    }
}

void Tampil_List(address q) {
    while (q != NULL) {
        printf("%s -> ", q->namaPenduduk);
        q = q->next;
    }
    printf("NULL\n");
}

void Ins_Awal(address *q, address PNew) {
    if (PNew != NULL) {
        PNew->next = *q;
        *q = PNew;
    }
}

void Ins_Akhir(address *q, address PNew) {
    if (*q == NULL) {
        *q = PNew;
    } else {
        address temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

address Search(address q, nama nilai) {
    while (q != NULL) {
        if (strcmp(q->namaPenduduk, nilai) == 0) {
            return q;
        }
        q = q->next;
    }
    return NULL;
}

void InsertAfter(address *qBef, address PNew) {
    if (*qBef != NULL && PNew != NULL) {
        PNew->next = (*qBef)->next;
        (*qBef)->next = PNew;
    }
}

void Del_Awal(address *q, nama *X) {
    if (*q != NULL) {
        address temp = *q;
        strcpy(*X, temp->namaPenduduk);
        *q = temp->next;
        free(temp);
    }
}

void Del_Akhir(address *q, nama *X) {
    if (*q != NULL) {
        address temp = *q, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        strcpy(*X, temp->namaPenduduk);
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *q = NULL;
        }
        free(temp);
    }
}

void Del_After(address *qBef, nama *X) {
    if (*qBef != NULL && (*qBef)->next != NULL) {
        address temp = (*qBef)->next;
        strcpy(*X, temp->namaPenduduk);
        (*qBef)->next = temp->next;
        free(temp);
    }
}

void DeAlokasi(address *q) {
    free(*q);
    *q = NULL;
}

int NbElmt(address q) {
    if (q == NULL) return 0;
    return 1 + NbElmt(q->next);
}

