# Pilha (Stack) – Implementações em C

Este projeto apresenta duas implementações da estrutura de dados Pilha, baseadas no material do curso de Estruturas de Dados (CELES; RANGEL, 2002):

🧠 Conceito

Pilha é uma estrutura do tipo LIFO (Last-In, First-Out), onde o último elemento inserido é o primeiro a ser removido. Muito utilizada em aplicações como:

    Pilha de chamadas de funções (call stack)

    Calculadoras pós-fixadas

    Desfazer/refazer operações

- 📦 **pilha_vetor.c**: Implementação com vetor.
- 🔗 **pilha_lista.c**: Implementação com lista encadeada.

## ✨ Funcionalidades

- Criar uma pilha
- Empilhar (`push`)
- Desempilhar (`pop`)
- Verificar se a pilha está vazia
- Liberar memória
- Imprimir elementos da pilha (do topo à base)

## 🚀 Como compilar e rodar

Escolha uma implementação e compile com o `main.c`.

### Vetor

```bash
gcc main.c pilha_vetor.c -o pilha
./pilha
```

### Lista

```bash
gcc main.c pilha_lista.c -o pilha
./pilha
```

# 📚 Referência

---

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
