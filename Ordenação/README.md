# 📊 Algoritmos de Ordenação Genéricos em C

Implementação de algoritmos de ordenação genéricos em C, baseados no material de Estruturas de Dados da PUC-Rio (CELES, RANGEL, 2002).

## 📚 Conteúdo

1. **Ordenação Bolha Genérica**
   - Função de comparação para diferentes tipos
   - Funções auxiliares de acesso e troca
   - Implementação genérica do algoritmo

2. **QuickSort Genérico**
   - Versão específica para inteiros
   - Versão genérica usando ponteiros de função
   - Exemplo de uso com `qsort` da biblioteca padrão

3. **Exemplos Práticos**
   - Ordenação de números reais
   - Ordenação de estruturas Aluno
   - Ordenação de vetores de ponteiros

## 🛠 Como Usar

### Compilação

```bash
gcc ordenacao.c -o ordenacao
```

Execução

```bash
./ordenacao
```

## 📋 Estrutura do Código

### Funções Principais

- bolha_gen() - Ordenação bolha genérica
- rapida() - QuickSort para inteiros
- qsort() - Uso da função da biblioteca padrão

### Funções Auxiliares

- acessa() - Acesso genérico a elementos do vetor
- troca() - Troca genérica de elementos
- Funções de comparação para diferentes tipos

## 📝 Exemplo de Saída

- Vetor de inteiros ordenado: 12 25 33 37 48 57 86 92
- Vetor de reais ordenado: 12.1 25.6 33.3 37.7 48.3 57.4 86.6 92.8
- Alunos ordenados por nome: [Ana, Carlos, João, Maria]

## 📚 Referência

---

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
