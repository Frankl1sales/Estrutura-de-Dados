#ifndef FILA_H
#define FILA_H

#define N 100

typedef struct fila {
    int ini, fim;
    float vet[N];
} Fila;

Fila* cria(void);
void insere(Fila* f, float v);
float retira(Fila* f);
int vazia(Fila* f);
void libera(Fila* f);
void imprime(Fila* f);

#endif
