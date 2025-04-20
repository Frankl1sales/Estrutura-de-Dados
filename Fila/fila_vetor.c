// Implementacao de fila usando vetor
#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct fila {
    int ini, fim;
    float vet[N];
} Fila;

int incr(int i) {
    return (i + 1) % N;
}

Fila* cria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = 0;
    return f;
}

void insere(Fila* f, float v) {
    if (incr(f->fim) == f->ini) {
        printf("Capacidade da fila estourou.\n");
        exit(1);
    }
    f->vet[f->fim] = v;
    f->fim = incr(f->fim);
}

float retira(Fila* f);
int vazia(Fila* f);

float retira(Fila* f) {
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    float v = f->vet[f->ini];
    f->ini = incr(f->ini);
    return v;
}

int vazia(Fila* f) {
    return (f->ini == f->fim);
}

void libera(Fila* f) {
    free(f);
}

void imprime(Fila* f) {
    for (int i = f->ini; i != f->fim; i = incr(i))
        printf("%f\n", f->vet[i]);
}
