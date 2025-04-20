#include <stdio.h>

int fatorial(int n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

int main() {
    int n = 5;
    printf("Fatorial de %d = %d\n", n, fatorial(n));
    return 0;
}
