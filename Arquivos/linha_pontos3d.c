#include <stdio.h>

typedef struct {
    float x, y, z;
} Ponto;

int main(void) {
    FILE* fp;
    char linha[121];
    Ponto pontos[100];
    int count = 0;

    fp = fopen("pontos3d.txt", "rt");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    while (fgets(linha, 121, fp) && count < 100) {
        float x, y, z = 0;
        int n = sscanf(linha, "%f %f %f", &x, &y, &z);
        if (n >= 2) {
            pontos[count].x = x;
            pontos[count].y = y;
            pontos[count].z = z;
            count++;
        }
    }

    fclose(fp);

    for (int i = 0; i < count; i++) {
        printf("Ponto %d: (%.2f, %.2f, %.2f)\n", i+1, pontos[i].x, pontos[i].y, pontos[i].z);
    }

    return 0;
}
