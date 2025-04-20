#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

// Inicializa a lista (lista vazia)
Lista* inicializa(void) {
    return NULL;
}

// Insere novo elemento no início da lista
Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

// Imprime todos os elementos da lista
void imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

// Verifica se a lista está vazia
int vazia(Lista* l) {
    return (l == NULL);
}

// Busca um elemento na lista
Lista* busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        if (p->info == v)
            return p;
    return NULL;
}

// Retira um elemento da lista
Lista* retira(Lista* l, int v) {
    Lista* ant = NULL;  // ponteiro para elemento anterior
    Lista* p = l;

    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)  // elemento não encontrado
        return l;

    // retira elemento do início
    if (ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;

    free(p);
    return l;
}

// Função principal
int main(void) {
    Lista* l = inicializa();

    l = insere(l, 23);
    l = insere(l, 45);
    l = insere(l, 99);

    printf("Elementos da lista:\n");
    imprime(l);

    printf("\nBuscando o elemento 45:\n");
    Lista* b = busca(l, 45);
    if (b != NULL)
        printf("Elemento encontrado: %d\n", b->info);
    else
        printf("Elemento não encontrado.\n");

    printf("\nRemovendo o elemento 45:\n");
    l = retira(l, 45);
    imprime(l);

    printf("\nA lista está %s\n", vazia(l) ? "vazia" : "não vazia");

    return 0;
}
