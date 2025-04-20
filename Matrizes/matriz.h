// matriz.h
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz {
    int lin;
    int col;
    float* v; // Vetor simples
} MatrizSimples;

MatrizSimples* criaSimples(int m, int n);
void liberaSimples(MatrizSimples* mat);
float acessaSimples(MatrizSimples* mat, int i, int j);
void atribuiSimples(MatrizSimples* mat, int i, int j, float v);

typedef struct matriz_ptr {
    int lin;
    int col;
    float** v; // Vetor de ponteiros
} MatrizPtr;

MatrizPtr* criaPtr(int m, int n);
void liberaPtr(MatrizPtr* mat);
float acessaPtr(MatrizPtr* mat, int i, int j);
void atribuiPtr(MatrizPtr* mat, int i, int j, float v);

#endif
