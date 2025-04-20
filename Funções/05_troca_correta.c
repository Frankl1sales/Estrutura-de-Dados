#include <stdio.h>

void troca(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int a = 5, b = 7;
    troca(&a, &b);
    printf("Após troca correta: a = %d, b = %d\n", a, b);
    return 0;
}
