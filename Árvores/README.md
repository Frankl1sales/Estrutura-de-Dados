# 🌳 Árvores Binárias em C

Implementação de uma árvore binária em C desenvolvida como exercício da disciplina **Estruturas de Dados**, baseada no material de CELES e RANGEL (2002).

## 🚀 Funcionalidades

### Operações Básicas
- [x] Criação de árvore binária
- [x] Inserção de nós
- [x] Busca de elementos
- [x] Liberação de memória

### Percursos
- [x] Pré-ordem
- [x] Ordem simétrica (in-ordem)
- [x] Pós-ordem

### Informações
- [x] Cálculo da altura da árvore

## 🌲 Estrutura da Árvore

### Configuração Inicial
```
    a
   / \
  b   c
   \  / \
    d e  f
```

### Após Inserções
```
    a
   / \
  b   c
 /     \
x       f
/
y z
```

### Após Remoções
- Nó `e` removido

## 🛠 Como Usar

### Compilação
```bash
gcc arvore_binaria.c -o arvore_binaria
```

### Execução
```bash
./arvore_binaria
```

### 📊 Saída Esperada
```
Pré-ordem: a b x y z d c f
Ordem simétrica: y x z b d a c f
Pós-ordem: y z x d b f c a
Altura da árvore: 3
Busca 'z': Encontrado
Busca 'e': Não encontrado
```

## 📚 Conceitos Implementados

- **Estruturas de Dados**:
  - Árvore binária
  - Nós com ponteiros para filhos esquerdo e direito

- **Algoritmos**:
  - Percursos recursivos (pré, in e pós-ordem)
  - Cálculo de altura
  - Busca em árvores

- **Gerenciamento de Memória**:
  - Alocação dinâmica com `malloc`
  - Liberação segura com `free`

## 📖 Referência

CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, 2002.  
Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf)  
Acesso em: 17 abr. 2025.

---
⌨️ Desenvolvido como exercício acadêmico de Algoritmos e Estruturas de Dados