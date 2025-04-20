#include <stdio.h>

int main() {
    // Operadores aritméticos
    int a = 5, b = 2;
    printf("Aritméticos:\n");
    printf("5 + 2 = %d\n", a + b);
    printf("5 - 2 = %d\n", a - b);
    printf("5 * 2 = %d\n", a * b);
    printf("5 / 2 = %d (divisão inteira)\n", a / b);
    printf("5 %% 2 = %d (resto da divisão)\n\n", a % b);

    // Divisão real
    double x = 5.0, y = 2.0;
    printf("Divisão real: 5.0 / 2.0 = %.2f\n\n", x / y);

    // Atribuição composta
    int i = 10;
    i += 5;
    printf("Atribuição composta:\ni += 5 -> %d\n", i);

    // Incremento e decremento
    int n = 5;
    printf("\nIncremento/decremento:\n");
    printf("n = %d\n", n);
    printf("n++ = %d\n", n++); // pós-incremento
    printf("Agora n = %d\n", n);
    printf("++n = %d\n\n", ++n); // pré-incremento

    // Operadores relacionais e lógicos
    int c = 23;
    int d = c + 4;
    int resultado1 = (c < 20) || (d > c);
    int resultado2 = (c < 20) && (d > c);
    printf("Relacionais e lógicos:\n");
    printf("(c < 20) || (d > c) = %d\n", resultado1); // 1 (verdadeiro)
    printf("(c < 20) && (d > c) = %d\n\n", resultado2); // 0 (falso)

    // Operador sizeof
    printf("sizeof(float) = %lu bytes\n\n", sizeof(float));

    // Conversão de tipo
    int inteiro = (int) 3.5;
    int mod = (int) 3.5 % 2;
    printf("Conversão de tipo:\n");
    printf("int de 3.5 = %d\n", inteiro);
    printf("(int) 3.5 %% 2 = %d\n", mod);

    return 0;
}
