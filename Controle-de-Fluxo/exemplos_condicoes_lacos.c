#include <stdio.h>

void exemplo_if_aninhado() {
    int a, b;
    printf("Insira dois numeros inteiros: ");
    scanf("%d%d", &a, &b);
    if (a % 2 == 0)
        if (b % 2 == 0)
            printf("Voce inseriu dois numeros pares!\n");
}

void exemplo_if_simples() {
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d%d", &a, &b);
    if ((a % 2 == 0) && (b % 2 == 0))
        printf("Voce digitou dois numeros pares!\n");
}

void temperatura_incorreta() {
    int temp;
    printf("Digite a temperatura: ");
    scanf("%d", &temp);
    if (temp < 30)
        if (temp > 20)
            printf("Temperatura agradavel\n");
        else
            printf("Temperatura muito quente\n");
}

void temperatura_correta() {
    int temp;
    printf("Digite a temperatura: ");
    scanf("%d", &temp);
    if (temp < 30) {
        if (temp > 20)
            printf("Temperatura agradavel\n");
    } else {
        printf("Temperatura muito quente\n");
    }
}

void temperatura_else_if() {
    int temp;
    printf("Digite a temperatura: ");
    scanf("%d", &temp);
    if (temp < 10)
        printf("Temperatura muito fria\n");
    else if (temp < 20)
        printf("Temperatura fria\n");
    else if (temp < 30)
        printf("Temperatura agradavel\n");
    else
        printf("Temperatura muito quente\n");
}

void fatorial_while() {
    int i = 1, n, f = 1;
    printf("Digite um número inteiro nao negativo: ");
    scanf("%d", &n);
    while (i <= n) {
        f *= i;
        i++;
    }
    printf("Fatorial = %d\n", f);
}

void fatorial_for() {
    int i, n, f = 1;
    printf("Digite um número inteiro nao negativo: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        f *= i;
    }
    printf("Fatorial = %d\n", f);
}

void fatorial_do_while() {
    int i, n, f = 1;
    do {
        printf("Digite um valor inteiro nao negativo: ");
        scanf("%d", &n);
    } while (n < 0);
    for (i = 1; i <= n; i++)
        f *= i;
    printf("Fatorial = %d\n", f);
}

void exemplo_break() {
    int i;
    for (i = 0; i < 10; i++) {
        if (i == 5)
            break;
        printf("%d ", i);
    }
    printf("fim\n");
}

void exemplo_continue() {
    int i;
    for (i = 0; i < 10; i++) {
        if (i == 5)
            continue;
        printf("%d ", i);
    }
    printf("fim\n");
}

int main() {
    int escolha;

    printf("Escolha uma das funcoes para executar:\n");
    printf("1 - exemplo_if_aninhado\n");
    printf("2 - exemplo_if_simples\n");
    printf("3 - temperatura_incorreta\n");
    printf("4 - temperatura_correta\n");
    printf("5 - temperatura_else_if\n");
    printf("6 - fatorial_while\n");
    printf("7 - fatorial_for\n");
    printf("8 - fatorial_do_while\n");
    printf("9 - exemplo_break\n");
    printf("10 - exemplo_continue\n");
    printf("Digite o número da função desejada: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            exemplo_if_aninhado();
            break;
        case 2:
            exemplo_if_simples();
            break;
        case 3:
            temperatura_incorreta();
            break;
        case 4:
            temperatura_correta();
            break;
        case 5:
            temperatura_else_if();
            break;
        case 6:
            fatorial_while();
            break;
        case 7:
            fatorial_for();
            break;
        case 8:
            fatorial_do_while();
            break;
        case 9:
            exemplo_break();
            break;
        case 10:
            exemplo_continue();
            break;
        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}