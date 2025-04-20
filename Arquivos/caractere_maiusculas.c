#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    char entrada[121];
    char saida[121];
    FILE* e;
    FILE* s;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%120s", entrada);
    printf("Digite o nome do arquivo de saída: ");
    scanf("%120s", saida);

    e = fopen(entrada, "rt");
    if (e == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    s = fopen(saida, "wt");
    if (s == NULL) {
        printf("Não foi possível abrir o arquivo de saída.\n");
        fclose(e);
        return 1;
    }

    while ((c = fgetc(e)) != EOF) {
        fputc(toupper(c), s);
    }

    fclose(e);
    fclose(s);
    return 0;
}
