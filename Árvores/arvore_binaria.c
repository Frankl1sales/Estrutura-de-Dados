#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore binária
typedef struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
} Arv;

// Interface
Arv* inicializa(void) {
    return NULL;
}

Arv* cria(char c, Arv* e, Arv* d) {
    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

int vazia(Arv* a) {
    return a == NULL;
}

void imprime_pre_ordem(Arv* a) {
    if (!vazia(a)) {
        printf("%c ", a->info);
        imprime_pre_ordem(a->esq);
        imprime_pre_ordem(a->dir);
    }
}

void imprime_ordem_simetrica(Arv* a) {
    if (!vazia(a)) {
        imprime_ordem_simetrica(a->esq);
        printf("%c ", a->info);
        imprime_ordem_simetrica(a->dir);
    }
}

void imprime_pos_ordem(Arv* a) {
    if (!vazia(a)) {
        imprime_pos_ordem(a->esq);
        imprime_pos_ordem(a->dir);
        printf("%c ", a->info);
    }
}

Arv* libera(Arv* a) {
    if (!vazia(a)) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

int busca(Arv* a, char c) {
    if (vazia(a)) return 0;
    return (a->info == c) || busca(a->esq, c) || busca(a->dir, c);
}

int altura(Arv* a) {
    if (vazia(a)) return -1;
    int he = altura(a->esq);
    int hd = altura(a->dir);
    return (he > hd ? he : hd) + 1;
}

// Função principal
int main(void) {
    Arv* a = cria('a',
        cria('b',
            inicializa(),
            cria('d', inicializa(), inicializa())
        ),
        cria('c',
            cria('e', inicializa(), inicializa()),
            cria('f', inicializa(), inicializa())
        )
    );

    // Acrescenta novos nós
    a->esq->esq = cria('x',
        cria('y', inicializa(), inicializa()),
        cria('z', inicializa(), inicializa())
    );

    // Libera parte da árvore
    a->dir->esq = libera(a->dir->esq);

    printf("Pré-ordem: ");
    imprime_pre_ordem(a);
    printf("\n");

    printf("Ordem simétrica: ");
    imprime_ordem_simetrica(a);
    printf("\n");

    printf("Pós-ordem: ");
    imprime_pos_ordem(a);
    printf("\n");

    printf("Altura da árvore: %d\n", altura(a));

    printf("Busca 'z': %s\n", busca(a, 'z') ? "Encontrado" : "Não encontrado");
    printf("Busca 'e': %s\n", busca(a, 'e') ? "Encontrado" : "Não encontrado");

    a = libera(a);

    return 0;
}
