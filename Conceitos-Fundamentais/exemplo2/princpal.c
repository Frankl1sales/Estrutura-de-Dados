/* Programa principal para conversão de temperatura */
#include <stdio.h>

float converte(float c);  // Declaração da função

int main(void)
{
    float t1;
    float t2;

    printf("Entre com temperatura em Celsius: ");
    scanf("%f", &t1);

    t2 = converte(t1);
    printf("A temperatura em Fahrenheit vale: %f\n", t2);

    return 0;
}
