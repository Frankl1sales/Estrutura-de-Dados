# Matrizes Dinâmicas em C

Este projeto implementa duas formas de alocação dinâmica de matrizes em C, baseadas no conteúdo do capítulo 8 da apostila de Estruturas de Dados (CELES; RANGEL, 2002).

## Estratégias de Implementação

### 1. **Matriz representada por um vetor simples**
- A matriz é armazenada em um vetor unidimensional.
- Acesso feito por `mat[i * n + j]`.
- Usa menos ponteiros, mas exige cálculo manual de índice.

### 2. **Matriz representada por vetor de ponteiros**
- Cada linha é alocada separadamente.
- Acesso é direto com `mat[i][j]`, como em matrizes estáticas.
- Código mais legível, porém com overhead de múltiplas alocações.

## Funcionalidades

- `cria(m, n)` — Cria uma matriz `m x n`.
- `atribui(i, j, valor)` — Atribui um valor na posição `i,j`.
- `acessa(i, j)` — Retorna o valor na posição `i,j`.
- `libera()` — Libera a memória da matriz.

## Compilação e Execução

```bash
gcc matriz.c -o matriz
./matriz

## 📚 Referência

---

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
