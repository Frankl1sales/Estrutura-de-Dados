#include <stdio.h>
#define PROD(a,b) (a * b)

int main(void) {
    printf("Resultado PROD errado: %d\n", PROD(3+4, 2));
    return 0;
}