# Exemplos de Condições e Laços em C

Este repositório contém exemplos ilustrativos dos principais conceitos de controle de fluxo na linguagem C, incluindo:

## ✅ Condições com `if`, `else` e operadores ternários

- **If aninhado**: permite decisões em múltiplos níveis.
- **Uso correto de blocos `{}`**: previne ambiguidade com `else`.
- **Construções `else if`**: imitam o comportamento de uma cadeia condicional.
- **Operador ternário (`? :`)**: alternativa mais enxuta ao `if-else`.

```c
maximo = a > b ? a : b;
```

## 🔁 Estruturas de repetição

- **`while`**: testa a condição no início.
- **`for`**: versão compacta do `while`.
- **`do-while`**: testa a condição no final — garante pelo menos uma execução.

### Exemplo com `do-while`
```c
do {
    scanf("%d", &n);
} while (n < 0);
```

## 🛑 Interrupção de laços

- **`break`**: encerra completamente o laço atual.
- **`continue`**: pula para a próxima iteração do laço.

## 🔧 Arquivo principal

Todas as funções estão no arquivo `exemplos_condicoes_lacos.c`. No `main`, você pode chamar qualquer função para testá-la.

## 📚 Compilação e execução

Compile com:

```bash
gcc exemplos_condicoes_lacos.c -o exemplos
./exemplos
```

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.

---