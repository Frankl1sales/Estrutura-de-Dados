#include <stdio.h>

int main() {
    int a;
    int *p;

    p = &a;
    *p = 2;

    printf("Valor de a atribuído via ponteiro: %d\n", a);

    return 0;
}
