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

/* Função de acesso genérico */
void* acessa(void* v, int i, int tam) {
    char* t = (char*)v;
    t += tam * i;
    return (void*)t;
}

/* Função de troca genérica */
void troca(void* a, void* b, int tam) {
    char* v1 = (char*)a;
    char* v2 = (char*)b;
    
    for (int i = 0; i < tam; i++) {
        char temp = v1[i];
        v1[i] = v2[i];
        v2[i] = temp;
    }
}

/* Funções de comparação */
int compara_int(const void* a, const void* b) {
    int* p1 = (int*)a;
    int* p2 = (int*)b;
    return (*p1 > *p2) ? 1 : 0;
}

int compara_float(const void* a, const void* b) {
    float* p1 = (float*)a;
    float* p2 = (float*)b;
    if (*p1 < *p2) return -1;
    else if (*p1 > *p2) return 1;
    else return 0;
}

int compara_aluno(const void* a, const void* b) {
    Aluno* p1 = (Aluno*)a;
    Aluno* p2 = (Aluno*)b;
    return strcmp(p1->nome, p2->nome);
}

int compara_aluno_ptr(const void* a, const void* b) {
    Aluno** p1 = (Aluno**)a;
    Aluno** p2 = (Aluno**)b;
    return strcmp((*p1)->nome, (*p2)->nome);
}

/* Ordenação Bolha Genérica */
void bolha_gen(int n, void* v, int tam, int(*cmp)(void*, void*)) {
    for (int i = n-1; i > 0; i--) {
        int fez_troca = 0;
        for (int j = 0; j < i; j++) {
            void* p1 = acessa(v, j, tam);
            void* p2 = acessa(v, j+1, tam);
            if (cmp(p1, p2)) {
                troca(p1, p2, tam);
                fez_troca = 1;
            }
        }
        if (!fez_troca) return;
    }
}

/* QuickSort para inteiros */
void rapida(int n, int* v) {
    if (n <= 1) return;
    
    int x = v[0];
    int a = 1;
    int b = n-1;
    
    do {
        while (a < n && v[a] <= x) a++;
        while (v[b] > x) b--;
        
        if (a < b) {
            int temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a++; b--;
        }
    } while (a <= b);
    
    v[0] = v[b];
    v[b] = x;
    
    rapida(b, v);
    rapida(n-a, &v[a]);
}

/* Exemplos de uso */
void exemplo_inteiros() {
    int v[] = {25, 48, 37, 12, 57, 86, 33, 92};
    int n = sizeof(v)/sizeof(int);
    
    rapida(n, v);
    
    printf("Inteiros ordenados: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

void exemplo_reais() {
    float v[] = {25.6, 48.3, 37.7, 12.1, 57.4, 86.6, 33.3, 92.8};
    int n = sizeof(v)/sizeof(float);
    
    qsort(v, n, sizeof(float), compara_float);
    
    printf("Reais ordenados: ");
    for (int i = 0; i < n; i++) printf("%.1f ", v[i]);
    printf("\n");
}

void exemplo_alunos() {
    Aluno alunos[] = {
        {"João", "123", 'A', "joao@email.com"},
        {"Maria", "456", 'B', "maria@email.com"},
        {"Ana", "789", 'A', "ana@email.com"},
        {"Carlos", "101", 'B', "carlos@email.com"}
    };
    int n = sizeof(alunos)/sizeof(Aluno);
    
    qsort(alunos, n, sizeof(Aluno), compara_aluno);
    
    printf("Alunos ordenados: ");
    for (int i = 0; i < n; i++) printf("%s ", alunos[i].nome);
    printf("\n");
}

int main() {
    exemplo_inteiros();
    exemplo_reais();
    exemplo_alunos();
    return 0;
}