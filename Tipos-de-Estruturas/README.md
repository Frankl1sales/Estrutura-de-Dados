# Estruturas de Dados em C – PUC-Rio

Na linguagem C, contamos com tipos primitivos como char, int, float, entre outros, além de seus ponteiros, que podem ser utilizados na definição de variáveis. No entanto, quando lidamos com dados mais complexos, compostos por múltiplos campos com tipos diferentes, é necessário utilizar recursos que possibilitem o agrupamento desses diversos tipos em uma única estrutura (CELES; RANGEL, 2002).

## Conteúdo

### 1. Estruturas Simples

- Declaração e uso de estruturas do tipo `Ponto`
- Captura e impressão de pontos
- Cálculo da distância entre dois pontos
- Uso de `typedef` para definição de tipos personalizados

### 2. Alocação Dinâmica

- Alocação de uma estrutura com `malloc`
- Acesso via ponteiro (`->`)

### 3. Vetores de Estruturas

- Representação de polígonos como vetores de pontos
- Cálculo da área de um polígono genérico
- Leitura dinâmica do número de pontos e das coordenadas via teclado

### 4. Vetores de Ponteiros para Estruturas

- Simulação de uma tabela de alunos
- Alocação e desalocação de alunos dinamicamente
- Preenchimento e impressão de dados via teclado

## Compilação

Compile os arquivos com:

```bash
gcc main.c ponto.c -o ponto
gcc aluno.c -o aluno
```

## Execução

Exemplo do Polígono

```bash
./ponto
```

Exemplo da Tabela de Alunos

```bash
./aluno
```

## 📚 Referência

---

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
