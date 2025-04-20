#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* cria(void);
void push(Pilha* p, float v);
float pop(Pilha* p);
int vazia(Pilha* p);
void libera(Pilha* p);
void imprime(Pilha* p);

#endif