#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(void) {
    int n, i;
    Ponto *poligono;

    printf("Digite o número de pontos do polígono: ");
    scanf("%d", &n);

    poligono = (Ponto*) malloc(n * sizeof(Ponto));

    if (poligono == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Ponto %d:\n", i + 1);
        captura(&poligono[i]);
    }

    printf("Área do polígono: %.2f\n", area(n, poligono));

    free(poligono);
    return 0;
}
