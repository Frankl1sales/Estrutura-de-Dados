#include <stdio.h>
#include <stdlib.h>

/* --- ESTRATÉGIA 1: MATRIZ COMO VETOR SIMPLES --- */

typedef struct {
    int lin;
    int col;
    float *v;
} MatrizVetor;

MatrizVetor* criaVetor(int m, int n) {
    MatrizVetor* mat = (MatrizVetor*) malloc(sizeof(MatrizVetor));
    mat->lin = m;
    mat->col = n;
    mat->v = (float*) calloc(m * n, sizeof(float));
    return mat;
}

void liberaVetor(MatrizVetor* mat) {
    free(mat->v);
    free(mat);
}

float acessaVetor(MatrizVetor* mat, int i, int j) {
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Acesso inválido!\n");
        exit(1);
    }
    return mat->v[i * mat->col + j];
}

void atribuiVetor(MatrizVetor* mat, int i, int j, float val) {
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
    mat->v[i * mat->col + j] = val;
}


/* --- ESTRATÉGIA 2: MATRIZ COMO VETOR DE PONTEIROS --- */

typedef struct {
    int lin;
    int col;
    float **v;
} MatrizPonteiros;

MatrizPonteiros* criaPonteiros(int m, int n) {
    int i;
    MatrizPonteiros* mat = (MatrizPonteiros*) malloc(sizeof(MatrizPonteiros));
    mat->lin = m;
    mat->col = n;
    mat->v = (float**) malloc(m * sizeof(float*));
    for (i = 0; i < m; i++) {
        mat->v[i] = (float*) calloc(n, sizeof(float));
    }
    return mat;
}

void liberaPonteiros(MatrizPonteiros* mat) {
    for (int i = 0; i < mat->lin; i++)
        free(mat->v[i]);
    free(mat->v);
    free(mat);
}

float acessaPonteiros(MatrizPonteiros* mat, int i, int j) {
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Acesso inválido!\n");
        exit(1);
    }
    return mat->v[i][j];
}

void atribuiPonteiros(MatrizPonteiros* mat, int i, int j, float val) {
    if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
    mat->v[i][j] = val;
}


/* --- EXEMPLO DE USO --- */

int main() {
    int i, j;
    MatrizVetor* m1 = criaVetor(3, 3);
    MatrizPonteiros* m2 = criaPonteiros(3, 3);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            atribuiVetor(m1, i, j, i + j);
            atribuiPonteiros(m2, i, j, i * j);
        }

    printf("Matriz (vetor simples):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%.1f ", acessaVetor(m1, i, j));
        printf("\n");
    }

    printf("\nMatriz (vetor de ponteiros):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%.1f ", acessaPonteiros(m2, i, j));
        printf("\n");
    }

    liberaVetor(m1);
    liberaPonteiros(m2);

    return 0;
}
