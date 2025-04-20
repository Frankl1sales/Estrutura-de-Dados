#ifndef FILA_LISTA_H
#define FILA_LISTA_H

typedef struct no {
    float info;
    struct no* prox;
} No;

typedef struct fila_l {
    No* ini;
    No* fim;
} FilaL;

FilaL* cria_l(void);
void insere_l(FilaL* f, float v);
float retira_l(FilaL* f);
int vazia_l(FilaL* f);
void libera_l(FilaL* f);
void imprime_l(FilaL* f);

#endif
