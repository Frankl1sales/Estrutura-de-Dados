#include <stdio.h>

float media(int n, float *v) {
    float s = 0.0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s / n;
}

float variancia(int n, float *v, float m) {
    float s = 0.0;
    for (int i = 0; i < n; i++)
        s += (v[i] - m) * (v[i] - m);
    return s / n;
}

int main(void) {
    float v[10], med, var;
    for (int i = 0; i < 10; i++)
        scanf("%f", &v[i]);

    med = media(10, v);
    var = variancia(10, v, med);

    printf("Media = %f Variancia = %f\n", med, var);
    return 0;
}
