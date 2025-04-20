#include <stdio.h>

int main() {
    int a, b, *p;
    
    a = 2;
    *p = 3;  // ERRO! p não foi inicializado
    b = a + (*p);  // comportamento indefinido

    printf("Valor de b (comportamento indefinido!): %d\n", b);

    return 0;
}
