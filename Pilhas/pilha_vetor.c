#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 50

struct pilha {
    int n;
    float vet[MAX];
};

Pilha* cria(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void push(Pilha* p, float v) {
    if (p->n == MAX) {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pop(Pilha* p) {
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->n--;
    return p->vet[p->n];
}

int vazia(Pilha* p) {
    return (p->n == 0);
}

void libera(Pilha* p) {
    free(p);
}

void imprime(Pilha* p) {
    for (int i = p->n - 1; i >= 0; i--)
        printf("%f\n", p->vet[i]);
}
