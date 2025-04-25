#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NPAL 64       /* Tamanho máximo de cada palavra */
#define NTAB 127      /* Tamanho da tabela hash */

/* Estrutura para armazenar palavras e contagem */
typedef struct palavra {
    char pal[NPAL];   /* Palavra */
    int n;            /* Número de ocorrências */
    struct palavra* prox; /* Para tratamento de colisões */
} Palavra;

typedef Palavra* Hash[NTAB]; /* Tipo tabela hash */

/* ------------------ */
/* FUNÇÕES AUXILIARES */
/* ------------------ */

/* Inicializa tabela hash */
void inicializa(Hash tab) {
    for (int i = 0; i < NTAB; i++) {
        tab[i] = NULL;
    }
}

/* Função de hash para strings */
int hash(char* s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        total += s[i];
    }
    return total % NTAB;
}

/* Função de hash secundária para endereçamento aberto */
int hash2(char* s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        total += s[i] * (i+1);
    }
    return (NTAB - 2) - (total % (NTAB - 2));
}

/* ------------------ */
/* TRATAMENTO DE COLISÕES: LISTAS ENCADEADAS */
/* ------------------ */

/* Busca palavra na tabela (listas encadeadas) */
Palavra* busca_lista(Hash tab, char* s) {
    int h = hash(s);
    Palavra* p;
    for (p = tab[h]; p != NULL; p = p->prox) {
        if (strcmp(p->pal, s) == 0) {
            return p;
        }
    }
    return NULL;
}

/* Insere ou atualiza palavra (listas encadeadas) */
Palavra* insere_lista(Hash tab, char* s) {
    int h = hash(s);
    Palavra* ant = NULL;
    Palavra* p = tab[h];
    
    while (p != NULL && strcmp(p->pal, s) != 0) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) { /* Nova palavra */
        p = malloc(sizeof(Palavra));
        strcpy(p->pal, s);
        p->n = 0;
        p->prox = NULL;
        
        if (ant == NULL) {
            tab[h] = p; /* Primeiro da lista */
        } else {
            ant->prox = p; /* Insere no final */
        }
    }
    p->n++; /* Incrementa contagem */
    return p;
}

/* ------------------ */
/* TRATAMENTO DE COLISÕES: ENDEREÇAMENTO ABERTO */
/* ------------------ */

/* Busca palavra na tabela (endereçamento aberto) */
Palavra* busca_aberto(Hash tab, char* s) {
    int h = hash(s);
    int h2 = hash2(s);
    int tentativas = 0;
    
    while (tab[h] != NULL && tentativas < NTAB) {
        if (strcmp(tab[h]->pal, s) == 0) {
            return tab[h];
        }
        h = (h + h2) % NTAB;
        tentativas++;
    }
    return NULL;
}

/* Insere palavra na tabela (endereçamento aberto) */
Palavra* insere_aberto(Hash tab, char* s) {
    int h = hash(s);
    int h2 = hash2(s);
    int tentativas = 0;
    
    /* Procura posição vazia ou palavra existente */
    while (tentativas < NTAB) {
        if (tab[h] == NULL) { /* Posição vazia */
            tab[h] = malloc(sizeof(Palavra));
            strcpy(tab[h]->pal, s);
            tab[h]->n = 1;
            tab[h]->prox = NULL;
            return tab[h];
        } else if (strcmp(tab[h]->pal, s) == 0) { /* Palavra existe */
            tab[h]->n++;
            return tab[h];
        }
        h = (h + h2) % NTAB;
        tentativas++;
    }
    
    fprintf(stderr, "Tabela hash cheia!\n");
    return NULL;
}

/* ------------------ */
/* FUNÇÕES PARA CONTAGEM DE PALAVRAS */
/* ------------------ */

/* Lê próxima palavra do arquivo */
int le_palavra(FILE* fp, char* s) {
    int i = 0;
    int c;
    
    /* Pula caracteres não-letras */
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) break;
    }
    
    if (c == EOF) return 0;
    
    s[i++] = tolower(c); /* Primeira letra */
    
    /* Lê resto da palavra */
    while (i < NPAL-1 && (c = fgetc(fp)) != EOF && isalpha(c)) {
        s[i++] = tolower(c);
    }
    s[i] = '\0';
    return 1;
}

/* Conta ocorrências de palavras no arquivo */
void conta_ocorrencias(FILE* fp, Hash tab) {
    char s[NPAL];
    while (le_palavra(fp, s)) {
        insere_lista(tab, s); /* Usando listas encadeadas */
        // insere_aberto(tab, s); /* Alternativa com endereçamento aberto */
    }
}

/* Função de comparação para qsort */
int compara_ocorrencias(const void* a, const void* b) {
    Palavra** pa = (Palavra**)a;
    Palavra** pb = (Palavra**)b;
    
    if ((*pa)->n > (*pb)->n) return -1;
    else if ((*pa)->n < (*pb)->n) return 1;
    else return strcmp((*pa)->pal, (*pb)->pal);
}

/* Imprime resultados ordenados */
void imprime_resultados(Hash tab) {
    /* Conta palavras distintas */
    int n = 0;
    for (int i = 0; i < NTAB; i++) {
        for (Palavra* p = tab[i]; p != NULL; p = p->prox) {
            n++;
        }
    }
    
    /* Cria vetor de ponteiros */
    Palavra** vetor = malloc(n * sizeof(Palavra*));
    int j = 0;
    for (int i = 0; i < NTAB; i++) {
        for (Palavra* p = tab[i]; p != NULL; p = p->prox) {
            vetor[j++] = p;
        }
    }
    
    /* Ordena vetor */
    qsort(vetor, n, sizeof(Palavra*), compara_ocorrencias);
    
    /* Imprime resultados */
    for (int i = 0; i < n; i++) {
        printf("%s = %d\n", vetor[i]->pal, vetor[i]->n);
    }
    
    free(vetor);
}

/* ------------------ */
/* PROGRAMA PRINCIPAL */
/* ------------------ */

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }
    
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    
    Hash tabela;
    inicializa(tabela);
    
    conta_ocorrencias(fp, tabela);
    fclose(fp);
    
    imprime_resultados(tabela);
    
    /* Libera memória (exercício: implementar) */
    /*
    printf("\nLiberando memória...\n");
    for (int i = 0; i < NTAB; i++) {
        Palavra* p = tabela[i];
        while (p != NULL) {
            Palavra* temp = p;
            p = p->prox;
            free(temp);
        }
    }
    printf("Memória liberada com sucesso.\n");
    */
    return 0;
}