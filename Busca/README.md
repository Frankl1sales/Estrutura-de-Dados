# 🔍 Busca Binária e Árvores Binárias de Busca em C

Implementação de algoritmos de busca e estruturas de dados baseados no material de Estruturas de Dados da PUC-Rio (CELES, RANGEL, 2002).

## 📚 Conteúdo

1. **Busca Binária Genérica**
   - Implementação usando `bsearch` da biblioteca padrão
   - Funções de comparação para diferentes tipos de dados
   - Exemplos com inteiros e estruturas complexas

2. **Árvores Binárias de Busca**
   - Operações básicas: busca, inserção e remoção
   - Implementação recursiva
   - Balanceamento de árvores

## 🛠 Como Usar

### Compilação

```bash
gcc busca_arvore.c -o busca_arvore
```

### Execução

```bash
./busca_arvore
```

## 📋 Estrutura do Código

### Busca Binária

- bsearch_exemplo_int() - Busca em vetor de inteiros
- bsearch_exemplo_aluno() - Busca em vetor de estruturas Aluno

### Árvore Binária de Busca

- arv_busca() - Busca em árvore
- arv_insere() - Inserção na árvore
- arv_retira() - Remoção de nó
- arv_balanceia() - Balanceamento de árvore

### 📝 Exemplo de Saída

- Busca por 57: encontrado no índice 5
- Busca por 'Maria': encontrada
- Árvore em ordem: 1 2 3 4 6 8
- Altura da árvore: 3
- Árvore balanceada: 2 4 6

## 📚 Referência

---

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
