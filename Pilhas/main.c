#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = cria();
    push(p, 10.5);
    push(p, 20.3);
    push(p, 30.7);

    printf("Conteudo da pilha:\n");
    imprime(p);

    printf("Elemento retirado: %f\n", pop(p));

    printf("Conteudo da pilha apos pop:\n");
    imprime(p);

    libera(p);
    return 0;
}