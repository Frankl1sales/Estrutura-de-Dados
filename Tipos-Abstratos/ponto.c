#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

/* Definição da estrutura interna do tipo Ponto */
struct ponto {
    float x;
    float y;
};

Ponto* cria(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void libera(Ponto* p) {
    free(p);
}

void acessa(Ponto* p, float* x, float* y) {
    if (p != NULL) {
        *x = p->x;
        *y = p->y;
    }
}

void atribui(Ponto* p, float x, float y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
}

float distancia(Ponto* p1, Ponto* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}
