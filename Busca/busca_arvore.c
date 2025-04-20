#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura Aluno para exemplos */
typedef struct {
    char nome[81];
    char mat[8];
    char turma;
    char email[41];
} Aluno;

/* ------------------ */
/* BUSCA BINÁRICA GENÉRICA */
/* ------------------ */

/* Função de comparação para inteiros */
int comp_int(const void* a, const void* b) {
    int* p1 = (int*)a;
    int* p2 = (int*)b;
    if (*p1 < *p2) return -1;
    else if (*p1 > *p2) return 1;
    else return 0;
}

/* Função de comparação para Aluno* por nome */
int comp_aluno_nome(const void* a, const void* b) {
    char* nome = (char*)a;
    Aluno** aluno = (Aluno**)b;
    return strcmp(nome, (*aluno)->nome);
}

void exemplo_busca_int() {
    int v[] = {12, 25, 33, 37, 48, 57, 86, 92};
    int n = sizeof(v)/sizeof(int);
    int chave = 57;
    
    int* resultado = (int*)bsearch(&chave, v, n, sizeof(int), comp_int);
    
    if (resultado) {
        printf("Busca por %d: encontrado no índice %ld\n", chave, resultado - v);
    } else {
        printf("Busca por %d: não encontrado\n", chave);
    }
}

void exemplo_busca_aluno() {
    Aluno alunos[] = {
        {"Ana", "123", 'A', "ana@email.com"},
        {"Carlos", "456", 'B', "carlos@email.com"},
        {"João", "789", 'A', "joao@email.com"},
        {"Maria", "101", 'B', "maria@email.com"}
    };
    int n = sizeof(alunos)/sizeof(Aluno);
    
    // Criar vetor de ponteiros para alunos
    Aluno* ptr_alunos[n];
    for (int i = 0; i < n; i++) {
        ptr_alunos[i] = &alunos[i];
    }
    
    char* nome_busca = "Maria";
    Aluno** resultado = (Aluno**)bsearch(
        nome_busca, ptr_alunos, n, sizeof(Aluno*), comp_aluno_nome);
    
    if (resultado) {
        printf("Busca por '%s': encontrada\n", nome_busca);
    } else {
        printf("Busca por '%s': não encontrada\n", nome_busca);
    }
}

/* ------------------ */
/* ÁRVORE BINÁRIA DE BUSCA */
/* ------------------ */

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

/* Cria árvore vazia */
Arv* arv_cria() {
    return NULL;
}

/* Insere elemento na árvore */
Arv* arv_insere(Arv* a, int v) {
    if (a == NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info) {
        a->esq = arv_insere(a->esq, v);
    }
    else {
        a->dir = arv_insere(a->dir, v);
    }
    return a;
}

/* Busca elemento na árvore */
Arv* arv_busca(Arv* r, int v) {
    if (r == NULL) return NULL;
    else if (r->info > v) return arv_busca(r->esq, v);
    else if (r->info < v) return arv_busca(r->dir, v);
    else return r;
}

/* Remove elemento da árvore */
Arv* arv_retira(Arv* r, int v) {
    if (r == NULL) return NULL;
    else if (r->info > v) r->esq = arv_retira(r->esq, v);
    else if (r->info < v) r->dir = arv_retira(r->dir, v);
    else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        else {
            Arv* f = r->esq;
            while (f->dir != NULL) f = f->dir;
            r->info = f->info;
            f->info = v;
            r->esq = arv_retira(r->esq, v);
        }
    }
    return r;
}

/* Imprime árvore em ordem */
void arv_imprime(Arv* a) {
    if (a != NULL) {
        arv_imprime(a->esq);
        printf("%d ", a->info);
        arv_imprime(a->dir);
    }
}

/* Calcula altura da árvore */
int arv_altura(Arv* a) {
    if (a == NULL) return -1;
    else {
        int he = arv_altura(a->esq);
        int hd = arv_altura(a->dir);
        return (he > hd) ? he + 1 : hd + 1;
    }
}

/* Balanceamento de árvore (simplificado) */
Arv* arv_balanceia(Arv* a) {
    if (a == NULL) return NULL;
    
    // Implementação simplificada - na prática seria mais complexo
    // Aqui apenas re-inserimos os elementos em ordem
    int n = 0;
    // Contar elementos (implementação omitida)
    
    // Criar vetor ordenado (implementação omitida)
    
    // Reconstruir árvore balanceada (implementação omitida)
    
    return a;
}

void exemplo_arvore() {
    Arv* a = arv_cria();
    a = arv_insere(a, 6);
    a = arv_insere(a, 2);
    a = arv_insere(a, 8);
    a = arv_insere(a, 1);
    a = arv_insere(a, 4);
    a = arv_insere(a, 3);
    
    printf("Árvore em ordem: ");
    arv_imprime(a);
    printf("\n");
    
    printf("Altura da árvore: %d\n", arv_altura(a));
    
    a = arv_retira(a, 6);
    printf("Após remoção do 6: ");
    arv_imprime(a);
    printf("\n");
    
    a = arv_balanceia(a);
    printf("Árvore balanceada: ");
    arv_imprime(a);
    printf("\n");
}

/* ------------------ */
/* PROGRAMA PRINCIPAL */
/* ------------------ */

int main() {
    printf("=== BUSCA BINÁRICA ===\n");
    exemplo_busca_int();
    exemplo_busca_aluno();
    
    printf("\n=== ÁRVORE BINÁRIA DE BUSCA ===\n");
    exemplo_arvore();
    
    return 0;
}