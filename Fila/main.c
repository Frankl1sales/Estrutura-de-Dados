#include <stdio.h>
#include "fila.h"
#include "fila_lista.h"

int main(void) {
    printf("Fila com vetor circular:\n");
    Fila* f = cria();
    insere(f, 20.0);
    insere(f, 20.8);
    insere(f, 21.2);
    insere(f, 24.3);
    printf("Primeiro elemento: %f\n", retira(f));
    printf("Segundo elemento: %f\n", retira(f));
    printf("Configuração da fila:\n");
    imprime(f);
    libera(f);

    printf("\nFila com lista encadeada:\n");
    FilaL* fl = cria_l();
    insere_l(fl, 20.0);
    insere_l(fl, 20.8);
    insere_l(fl, 21.2);
    insere_l(fl, 24.3);
    printf("Primeiro elemento: %f\n", retira_l(fl));
    printf("Segundo elemento: %f\n", retira_l(fl));
    printf("Configuração da fila:\n");
    imprime_l(fl);
    libera_l(fl);

    return 0;
}
