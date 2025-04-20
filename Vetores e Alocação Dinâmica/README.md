# 📚 Vetores e Alocação Dinâmica em C

Exercícios baseados na Seção 5 do livro *"Estruturas de Dados"* de W. Celes e J. L. Rangel.  
Este repositório contém exemplos práticos sobre vetores, ponteiros, e alocação dinâmica de memória em C.

---

## 📁 Arquivos

### 1. `media_variancia.c`
Cálculo da **média** e **variância** de 10 números reais utilizando um vetor fixo.

📌 Destaques:
- Uso de vetores com índice
- Uso de `scanf` e `printf`
- Cálculo direto no `main`

### 2. `media_variancia_funcoes.c`
Mesma lógica do exemplo anterior, mas agora usando funções específicas para o cálculo da média e da variância.

📌 Destaques:
- Passagem de vetores como ponteiros (`float *v`)
- Reutilização de código via funções

### 3. `incrementa_vetor.c`
Demonstra como modificar os elementos de um vetor dentro de uma função.

📌 Destaques:
- Incremento de cada elemento do vetor
- Ponteiros e modificação de memória

### 4. `media_variancia_dinamico.c`
Versão melhorada que utiliza **alocação dinâmica de memória** para trabalhar com um número de elementos definido em tempo de execução.

📌 Destaques:
- Uso de `malloc` e `free`
- Vetor com tamanho dinâmico
- Maior flexibilidade e economia de memória

---

## 🧪 Compilação e Execução

Compile os arquivos com `gcc`:

```bash
gcc media_variancia.c -o media_variancia
gcc media_variancia_funcoes.c -o media_variancia_funcoes
gcc incrementa_vetor.c -o incrementa_vetor
gcc media_variancia_dinamico.c -o media_variancia_dinamico
```

Execute:

```bash
./media_variancia
```

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
