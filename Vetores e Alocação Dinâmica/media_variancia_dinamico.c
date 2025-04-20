#include <stdio.h>
#include <stdlib.h>

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
    int n;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    float *v = (float *)malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &v[i]);

    float med = media(n, v);
    float var = variancia(n, v, med);

    printf("Media = %f Variancia = %f\n", med, var);

    free(v);
    return 0;
}
