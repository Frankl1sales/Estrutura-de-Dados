#include <stdio.h>

int main() {
    int a;
    int *p;

    a = 5;
    p = &a;
    *p = 6;

    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", (void *)&a);
    printf("Valor de p (endereço de a): %p\n", (void *)p);
    printf("Conteúdo apontado por p: %d\n", *p);

    return 0;
}
