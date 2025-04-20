# Estruturas de Dados – Fila

Este projeto implementa dois tipos de estruturas de filas em C:

- ✅ **Fila com vetor circular**: utiliza índices incrementados circularmente.
- ✅ **Fila com lista encadeada**: utiliza ponteiros para início e fim da lista.

## 📁 Arquivos

- `fila.h` / `fila_vetor.c`: implementação da fila com vetor circular.
- `fila_lista.h` / `fila_lista.c`: implementação da fila com lista encadeada.
- `main.c`: testes para ambas as implementações.
- `README.md`: este arquivo.

## 🧠 Conceitos

### Fila com vetor circular

- Usa índice `ini` para remoção e `fim` para inserção.
- Usa incremento circular: `(i + 1) % N`.
- Capacidade da fila é `N - 1` para evitar ambiguidade.

### Fila com lista encadeada

- Usa ponteiros `ini` e `fim`.
- Inserção feita ao final, remoção no início.
- Ponteiros atualizados após cada operação.

## 🛠️ Compilação

```bash
gcc main.c fila_vetor.c fila_lista.c -o fila
./fila

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.

---
