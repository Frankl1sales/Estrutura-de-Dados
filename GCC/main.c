#include <stdio.h>
#include "area.h"

int main() {
    double raio = 2.5;
    double a = 3.0, b = 4.0, c = 5.0;

    printf("Área do círculo de raio %.2f: %.2f\n", raio, area_circulo(raio));
    printf("Área do triângulo com lados %.2f, %.2f, %.2f: %.2f\n", a, b, c, area_triangulo(a, b, c));

    return 0;
}
