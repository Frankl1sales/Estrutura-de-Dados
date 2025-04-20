#include <stdio.h>

void troca(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 7;
    troca(a, b);
    printf("Após troca incorreta: a = %d, b = %d\n", a, b);
    return 0;
}
