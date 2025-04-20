#include <stdio.h>

int main(void) {
    char c;
    float v1, v2;
    FILE* fp;
    char linha[121];

    fp = fopen("figuras.txt", "rt");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, 121, fp)) {
        int n = sscanf(linha, " %c %f %f", &c, &v1, &v2);
        if (n > 0) {
            switch (c) {
                case '#':
                    break;
                case 'r':
                    if (n != 3) printf("Erro: retângulo inválido.\n");
                    else printf("Retângulo: base=%.2f, altura=%.2f\n", v1, v2);
                    break;
                case 't':
                    if (n != 3) printf("Erro: triângulo inválido.\n");
                    else printf("Triângulo: base=%.2f, altura=%.2f\n", v1, v2);
                    break;
                case 'c':
                    if (n != 2) printf("Erro: círculo inválido.\n");
                    else printf("Círculo: raio=%.2f\n", v1);
                    break;
                default:
                    printf("Erro: tipo desconhecido.\n");
                    break;
            }
        }
    }

    fclose(fp);
    return 0;
}
