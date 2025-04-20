#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto* p1 = cria(0.0, 0.0);
    Ponto* p2 = cria(3.0, 4.0);

    float d = distancia(p1, p2);
    printf("Distância entre os pontos: %.2f\n", d);

    float x, y;
    acessa(p2, &x, &y);
    printf("Coordenadas de p2: (%.2f, %.2f)\n", x, y);

    atribui(p1, 1.0, 1.0);
    acessa(p1, &x, &y);
    printf("Novas coordenadas de p1: (%.2f, %.2f)\n", x, y);

    libera(p1);
    libera(p2);

    return 0;
}
