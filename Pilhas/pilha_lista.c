#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    float info;
    struct no* prox;
} No;

struct pilha {
    No* prim;
};

Pilha* cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

static No* ins_ini(No* l, float v) {
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = l;
    return p;
}

static No* ret_ini(No* l) {
    No* p = l->prox;
    free(l);
    return p;
}

void push(Pilha* p, float v) {
    p->prim = ins_ini(p->prim, v);
}

float pop(Pilha* p) {
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    float v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

int vazia(Pilha* p) {
    return (p->prim == NULL);
}

void libera(Pilha* p) {
    No* q = p->prim;
    while (q != NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void imprime(Pilha* p) {
    No* q;
    for (q = p->prim; q != NULL; q = q->prox)
        printf("%f\n", q->info);
}
