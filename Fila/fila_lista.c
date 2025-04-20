#include <stdio.h>
#include <stdlib.h>
#include "fila_lista.h"

static No* ins_fim(No* fim, float v) {
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;
    return p;
}

static No* ret_ini(No* ini) {
    No* p = ini->prox;
    free(ini);
    return p;
}

FilaL* cria_l(void) {
    FilaL* f = (FilaL*) malloc(sizeof(FilaL));
    f->ini = f->fim = NULL;
    return f;
}

void insere_l(FilaL* f, float v) {
    f->fim = ins_fim(f->fim, v);
    if (f->ini == NULL)
        f->ini = f->fim;
}

float retira_l(FilaL* f) {
    if (vazia_l(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    float v = f->ini->info;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}

int vazia_l(FilaL* f) {
    return f->ini == NULL;
}

void libera_l(FilaL* f) {
    No* q = f->ini;
    while (q != NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void imprime_l(FilaL* f) {
    No* q;
    for (q = f->ini; q != NULL; q = q->prox)
        printf("%f\n", q->info);
}
