#include <stdio.h>

int main(void) {
    float v[10], med = 0.0, var = 0.0;
    int i;

    for (i = 0; i < 10; i++)
        scanf("%f", &v[i]);

    for (i = 0; i < 10; i++)
        med += v[i];
    med /= 10;

    for (i = 0; i < 10; i++)
        var += (v[i] - med) * (v[i] - med);
    var /= 10;

    printf("Media = %f Variancia = %f\n", med, var);
    return 0;
}