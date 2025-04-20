### 🧠 O que são funções?

Funções são **blocos de código reutilizáveis** que ajudam a **organizar** e **modularizar** um programa. Elas permitem dividir tarefas complexas em partes menores e mais simples.

### ✅ Vantagens:
- Evita repetição de código.
- Facilita manutenção e entendimento do programa.
- Torna o código mais legível e organizado.

---

### 🔧 Sintaxe Geral de uma Função em C:

```c
tipo_retorno nome_da_função (lista_de_parâmetros)
{
    corpo_da_função
}
```

- **tipo_retorno**: tipo do valor que a função retorna (ex: `int`, `float`, `void`, etc).
- **nome_da_função**: identificador da função.
- **lista_de_parâmetros**: variáveis que a função recebe como entrada.

---

### 📌 Exemplo 1 – Função que imprime o fatorial de um número

```c
#include <stdio.h>

void fat(int n); // Protótipo da função

int main(void)
{
    int n;
    scanf("%d", &n);
    fat(n); // Chamada da função
    return 0;
}

void fat(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
        f *= i;

    printf("Fatorial = %d\n", f);
}
```

🔍 **Explicação:**
- A função `fat` recebe um número inteiro `n`.
- Calcula o fatorial e **imprime** diretamente o resultado.
- O tipo de retorno é `void` (sem retorno).

---

### 📌 Exemplo 2 – Função que retorna o fatorial

```c
#include <stdio.h>

int fat(int n); // Protótipo da função

int main(void)
{
    int n, r;
    scanf("%d", &n);
    r = fat(n); // Função retorna o valor
    printf("Fatorial = %d\n", r);
    return 0;
}

int fat(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
        f *= i;

    return f;
}
```

🔍 **Explicação:**
- A função `fat` **retorna** o fatorial calculado.
- `main` é responsável por imprimir.
- Tipo de retorno da função é `int`.

---

### ⚠️ Importante:

1. **Protótipo da função**:
   - Deve ser declarado antes de sua chamada no código.
   - Exemplo: `int fat(int n);`
   - É opcional incluir nomes de parâmetros, mas recomendável.

2. **Uso de `void`**:
   - Se a função **não recebe parâmetros** → `int func(void)`
   - Se **não retorna valor** → `void nome_funcao(...)`

3. **Função `main` deve sempre retornar `int`**:
   - `return 0;` → indica execução bem-sucedida.
   - Outros valores podem indicar erro.

---

### 🧪 Testes com erros comuns

```c
fat(4.5); // Erro: função espera int, valor passado é float
```

O compilador acusa erro graças ao protótipo correto!

---

### 📚 Resumo:

| Elemento        | Descrição                                       |
|-----------------|-------------------------------------------------|
| `tipo_retorno`  | Tipo do dado que a função devolve               |
| `void`          | Usado quando não há retorno ou parâmetros       |
| `protótipo`     | Declaração antecipada da função                 |
| `main`          | Função obrigatória que inicia o programa        |
| `return`        | Encerra a função e devolve valor (se aplicável) |

# Exemplos Ponteiros e Recursividade em C

Este repositório contém exemplos de código em linguagem C baseados na seção 4 da apostila (CELES; RANGEL, 2002), abordando conceitos fundamentais como:

- Ponteiros de variáveis
- Atribuição e acesso via ponteiros
- Passagem de ponteiros para funções
- Recursividade

## Arquivos

### 1. `ponteiro_simples.c`

Demonstra o uso básico de ponteiros:

```c
int a;
int *p;
p = &a;
*p = 2;
```

Imprime: `2`

---

### 2. `ponteiro_nao_inicializado.c`

Exemplo de ERRO comum ao usar ponteiro sem inicializar:

```c
int a, b, *p;
a = 2;
*p = 3; // ERRO: ponteiro não aponta para local válido
```

⚠️ O comportamento é indefinido. Pode parecer que funciona, mas pode causar corrupção de memória.

---

### 3. `troca_incorreta.c`

Exemplo de função de troca mal implementada (não usa ponteiros):

```c
void troca(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}
```

Resultado: valores **não** são trocados no `main`.

---

### 4. `troca_correta.c`

Versão correta da função de troca usando ponteiros:

```c
void troca(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}
```

Resultado: valores são **trocados corretamente** no `main`.

---

### 5. `fatorial_recursivo.c`

Exemplo de função recursiva para cálculo de fatorial.

---

### 6. `fatorial_iterativo.c`

Versão iterativa da função de fatorial, útil para comparar com a versão recursiva.

---

## Como compilar e executar

Você pode compilar qualquer um dos arquivos usando `gcc`:

```bash
gcc -o programa ponteiro_simples.c
./programa
```

Ou, se preferir, use o `make` com o arquivo `Makefile`.

---

## Requisitos

- Compilador C (como `gcc`)
- Terminal Linux/Mac ou MinGW no Windows

---

# 📘 Execução de Funções e Pilha em C

Conforme (CELES; RANGEL, 2002), a execução do programa segue o modelo de pilha. De maneira resumida, esse modelo funciona assim: cada vez que uma função é executada, suas variáveis locais são armazenadas na pilha. Quando uma função é chamada, os argumentos passados são copiados para a pilha e passam a ser tratados como variáveis locais da função chamada. Ao término da execução da função, a região da pilha usada por ela é descartada. Por esse motivo, não é possível acessar variáveis locais fora do escopo da função onde foram declaradas.

## 💻 Código: `fatorial_iterativo.c`

```c
#include <stdio.h>

int fat (int n);

int main (void)
{
    int n = 5;
    int r;
    r = fat(n);
    printf("Fatorial de %d = %d\n", n, r);
    return 0;
}

int fat (int n)
{
    int f = 1;
    while (n != 0)
    {
        f *= n;
        n--;
    }
    return f;
}
```

---

## 🧪 Resultado Esperado

```
Fatorial de 5 = 120
```

> Mesmo que o parâmetro `n` seja alterado dentro da função `fat`, isso **não afeta** a variável `n` em `main()`, pois a **passagem de parâmetros em C é por valor**.  
> 
> Como explicam Celes e Rangel (2002), isso significa que a função chamada recebe apenas uma cópia do valor original. Assim, qualquer alteração feita em `n` dentro de `fat` não interfere na variável `n` da função `main`, mesmo que ambas compartilhem o mesmo nome, pois são variáveis locais e independentes.

---

## 🔍 Explicação da Pilha de Execução

A execução do programa pode ser explicada em etapas:

| Etapa | Função | Stack (Pilha de Execução)           | Observação |
|-------|--------|--------------------------------------|------------|
| 1     | `main` | `n = 5, r = ?`                      | Variáveis locais de `main` são alocadas |
| 2     | `main` | Chama `fat(n)`                      | Valor 5 é copiado para `n` de `fat` |
| 3     | `fat`  | `n = 5, f = 1`                      | `n` local e `f` local são criados |
| 4     | `fat`  | Loop até `n = 0`, `f = 120`         | Computação de fatorial |
| 5     | `fat`  | Retorna `120`                       | `n` e `f` são removidos da pilha |
| 6     | `main` | `r = 120`                           | Variável `r` recebe o valor retornado |

---

## 📚 Conclusão

- A linguagem C **usa passagem por valor**: cada função recebe **cópias** dos argumentos.
- A **stack** é usada para armazenar **variáveis locais** e **parâmetros**.
- Após o término de uma função, os dados locais da stack são **descartados**.

---

## 🧪 Compilação e Execução

```bash
gcc -o fatorial fatorial_iterativo.c
./fatorial
```

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.

---
