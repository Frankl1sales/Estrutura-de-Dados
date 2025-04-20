#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

void captura(Ponto *p) {
    printf("Digite as coordenadas x e y do ponto: ");
    scanf("%f %f", &p->x, &p->y);
}

void imprime(Ponto *p) {
    printf("Ponto: (%.2f, %.2f)\n", p->x, p->y);
}

float distancia(Ponto *p, Ponto *q) {
    return sqrt(pow(p->x - q->x, 2) + pow(p->y - q->y, 2));
}

float area(int n, Ponto* p) {
    int i, j;
    float a = 0;
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        a += (p[j].x - p[i].x) * (p[i].y + p[j].y) / 2.0;
    }
    return fabs(a);
}
