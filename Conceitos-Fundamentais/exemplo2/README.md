# Exemplo 2 - Conversor de Temperatura em C

O exemplo 2 é aborda a ideia de dividir o arquivo para que facilite o entendimento geral. Nesse sentido é uma continuação do exemplo 1 para conversão de valores de temperatura de Celsius para Fahrenheit, mas agora, aplicando o principio da modularização.  

## 🔧 Programas com Múltiplos Arquivos

Projetos maiores geralmente são divididos em **múltiplos arquivos-fonte** para modularização do código.

Suponha agora que o programa de conversão de temperatura seja dividido em dois arquivos: converte.c e principal.c.

### Estrutura de Arquivos

- `converte.c`: contém a função de conversão
- `principal.c`: contém a função `main`

### `converte.c`

```c
float converte(float c) {
    return 1.8 * c + 32;
}
```

### `principal.c`

```c
#include <stdio.h>

float converte(float c); // declaração da função

int main(void) {
    float t1, t2;
    printf("Entre com temperatura em Celsius: ");
    scanf("%f", &t1);
    t2 = converte(t1);
    printf("A temperatura em Fahrenheit vale: %f\n", t2);
    return 0;
}
```

### Compilando tudo de uma vez

Uma forma simples de gerar o executável é compilar os dois arquivos de uma vez:

```bash
gcc -o prog converte.c principal.c
```

No entanto, isso não é o ideal para projetos maiores. O mais eficiente é compilar os arquivos separadamente e, em seguida, ligá-los (linkar) em um único executável. Isso evita recompilar partes que não foram modificadas.

### Compilando por etapas (recomendado)

```bash
gcc -c converte.c       # gera converte.o
gcc -c principal.c      # gera principal.o
gcc -o prog converte.o principal.o
```

>A opção -c instrui o compilador a gerar apenas os arquivos objeto (.o ou .obj), sem criar o executável.
>Por fim, usamos o gcc para linkar os arquivos objetos e gerar o executável final.

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
---
