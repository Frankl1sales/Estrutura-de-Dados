#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct aluno {
    char nome[81];
    int mat;
    char end[121];
    char tel[21];
} Aluno;

typedef Aluno* PAluno;

PAluno tab[MAX];

void inicializa(void) {
    for (int i = 0; i < MAX; i++) {
        tab[i] = NULL;
    }
}

void preenche(int i) {
    if (tab[i] == NULL)
        tab[i] = (PAluno) malloc(sizeof(Aluno));

    printf("Entre com o nome: ");
    scanf(" %80[^\n]", tab[i]->nome);

    printf("Entre com a matricula: ");
    scanf("%d", &tab[i]->mat);

    printf("Entre com o endereco: ");
    scanf(" %120[^\n]", tab[i]->end);

    printf("Entre com o telefone: ");
    scanf(" %20[^\n]", tab[i]->tel);
}

void imprime(int i) {
    if (tab[i] != NULL) {
        printf("Nome: %s\n", tab[i]->nome);
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Endereco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

void removeAluno(int i) {
    if (tab[i] != NULL) {
        free(tab[i]);
        tab[i] = NULL;
    }
}
