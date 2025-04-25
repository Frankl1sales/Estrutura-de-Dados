#ifndef PONTO_H
#define PONTO_H

typedef struct ponto {
    float x;
    float y;
} Ponto, *PPonto;

float distancia(Ponto *p, Ponto *q);
void captura(Ponto *p);
void imprime(Ponto *p);
float area(int n, Ponto* p);

#endif
