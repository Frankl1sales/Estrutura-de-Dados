#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void) {
    float v = 4.5;
    float c = MAX(v, 3.0);
    printf("Maior valor: %.1f\n", c);
    return 0;
}