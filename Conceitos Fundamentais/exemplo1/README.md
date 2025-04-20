# Exemplo 1 - Conversor de Temperatura em C

[O exemplo 1](conversao_temperatura.c) é tratado na apostila como demostração de um programa em C, tendo como objetivo a conversão de valores de temperatura de Celsius para Fahrenheit. Além disso, é apresentado os conceitos fundamentais sobre o processo de compilação de programas escritos na linguagem C, utilizando o compilador `gcc`.

---

## 🚀 O que o programa faz?

- Solicita ao usuário uma temperatura em graus Celsius.
- Converte esse valor para Fahrenheit usando a fórmula:
  
  ```c
  F = 1.8 * C + 32
- Exibe o resultado convertido na tela.

---

## 🧱 Estrutura do Código

```c
/* Programa para conversão de temperatura de Celsius para Fahrenheit */
#include <stdio.h>
```

A função converte receberá o valor em Celsius e depois aplicará na formula

```c
float converte(float c) {
    float f;
    f = 1.8 * c + 32;
    return f;
}
```

A função main é o coração de um programa em C, atuando como o ponto de entrada e gerenciadora principal da execução. Vamos decompor cada parte do código fornecido:

```c
int main(void) {
    // corpo da função
    return 0;
}
```

>int indica que a função retorna um valor inteiro (código de status)
>void significa que a função não recebe parâmetros
>return 0 indica término bem-sucedido (convenção em C)

A seguir trata-se do corpo da função main:

```c
int main(void) {
    float t1;
    float t2;

    /* mostra mensagem para usuario */
    printf("Digite a temperatura em Celsius: ");

    /* captura valor entrado via teclado */
    scanf("%f", &t1);

    /* realiza conversão */
    t2 = converte(t1);

    /* exibe resultado */
    printf("Temperatura em Fahrenheit: %.2f\n", t2);

    return 0;
}
```

---
🧠 Explicação Geral do corpo da função main

No início do programa, são declaradas duas variáveis locais chamadas t1 e t2, ambas do tipo float, que permite armazenar números com ponto flutuante. Em seguida, o programa exibe uma mensagem pedindo que o usuário digite uma temperatura em Celsius. Esse valor é lido com a função scanf e armazenado em t1.

Depois disso, a função converte é chamada, passando t1 como argumento. Essa função realiza o cálculo da conversão de Celsius para Fahrenheit usando a fórmula F = 1.8 * C + 32, e retorna o resultado, que é armazenado na variável t2.

Por fim, o programa exibe a temperatura convertida na tela utilizando printf, formatando o valor com duas casas decimais.

---

## 🎓 O que se aprende com esse programa?

- Como declarar e usar variáveis do tipo `float`.
- Como criar e chamar uma função (`converte`).
- Como utilizar as funções `printf()` e `scanf()` para entrada e saída de dados.
- Como fazer cálculos simples e retornar resultados.

---

## 💡 Observação

Esse é um exemplo didático que reforça a lógica de programação e ensina o básico sobre como funciona o ciclo de entrada-processamento-saída.

---

## 📎 Como compilar e executar

Se você estiver usando o compilador `gcc`, basta rodar os seguintes comandos no terminal:

```bash
gcc -o conversor conversao_temperatura.c
./conversor
```

---

## 📚 Referência

CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [PUC-Rio - Estruturas de Dados](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
