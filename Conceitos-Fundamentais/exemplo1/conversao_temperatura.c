/* Programa para conversão de temperatura de Celsius para Fahrenheit */
#include <stdio.h>

float converte(float c) {
    float f;
    f = 1.8 * c + 32;
    return f;
}

int main(void) {
    float t1;
    float t2;

    /* mostra mensagem para usuario */
    printf("Digite a temperatura em Celsius: ");

    /* captura valor entrado via teclado */
    scanf("%f", &t1);

    /* realiza conversão */
    t2 = converte(t1);

    /* exibe resultado */
    printf("Temperatura em Fahrenheit: %.2f\n", t2);

    return 0;
}
