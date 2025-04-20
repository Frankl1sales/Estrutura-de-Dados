#include <stdio.h>
#include <string.h>

int main(void) {
    int n = 0, achou = 0;
    char entrada[121], subcadeia[121], linha[121];
    FILE* fp;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%120s", entrada);
    printf("Digite a subcadeia: ");
    scanf("%120s", subcadeia);

    fp = fopen(entrada, "rt");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    while (fgets(linha, 121, fp) != NULL) {
        n++;
        if (strstr(linha, subcadeia) != NULL) {
            achou = 1;
            break;
        }
    }

    fclose(fp);

    if (achou)
        printf("Achou na linha %d.\n", n);
    else
        printf("Não achou.\n");

    return 0;
}
