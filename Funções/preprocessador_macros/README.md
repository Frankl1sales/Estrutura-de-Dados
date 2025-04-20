# Exemplos de Pré-processador e Macros em C

Este repositório contém exemplos do uso de pré-processador e macros na linguagem C. O pré-processador é responsável por realizar modificações no código antes de sua compilação. Este exemplo ilustra o uso de diretivas de pré-processamento como `#include`, `#define` e macros com parâmetros.

## Diretivas do Pré-processador

### 1. Inclusão de Arquivos com `#include`

A diretiva `#include` é utilizada para incluir arquivos de cabeçalho no código fonte. O pré-processador substitui a diretiva pela implementação do arquivo incluído.

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

Este exemplo inclui a biblioteca padrão `stdio.h` que contém funções de entrada e saída, como `printf`.

### 2. Definição de Constantes com `#define`

A diretiva `#define` é usada para definir constantes simbólicas que podem ser substituídas no código.

```c
#define PI 3.14159

float area(float r) {
    return PI * r * r;
}
```

Neste caso, o pré-processador substitui todas as ocorrências de `PI` por `3.14159` antes da compilação.

### 3. Macros com Parâmetros

Macros também podem ser definidas com parâmetros. Isso permite reutilizar o código com diferentes entradas.

```c
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 5, y = 10;
    printf("Max: %d\n", MAX(x, y));
    return 0;
}
```

A macro `MAX(a, b)` irá substituir `a` e `b` com os valores passados e calcular o maior entre eles.

### 4. Erros de Macro Sem Parênteses

Macros podem causar problemas se não forem corretamente agrupadas com parênteses. No exemplo abaixo, o cálculo não ocorre como esperado:

```c
#define DIF(a,b) a - b

int main() {
    printf("Resultado: %d\n", 4 * DIF(5, 3));
    return 0;
}
```

O resultado esperado seria `8`, mas a saída será `17`, pois o pré-processador substitui a macro por `4 * 5 - 3`, onde a multiplicação tem precedência sobre a subtração.

### 5. Corrigindo Erros com Parênteses

Para corrigir os problemas de precedência, devemos envolver as expressões dentro da macro com parênteses:

```c
#define DIF(a,b) ((a) - (b))

int main() {
    printf("Resultado: %d\n", 4 * DIF(5, 3));
    return 0;
}
```

Agora, a saída será correta, `8`.

### 6. Macros com Parênteses para Evitar Erros

Aqui está outro exemplo, onde a falta de parênteses na definição da macro causa um erro de cálculo:

```c
#define PROD(a,b) (a * b)

int main() {
    printf("Resultado: %d\n", PROD(3 + 4, 2));
    return 0;
}
```

A saída será `11`, e não `14`, como esperado.

A solução é definir a macro corretamente, com parênteses envolvendo os parâmetros:

```c
#define PROD(a,b) ((a) * (b))
```

Agora a macro irá funcionar corretamente.

## Conclusão

- O pré-processador de C é uma ferramenta poderosa para incluir bibliotecas, definir constantes simbólicas e criar macros reutilizáveis.
- Ao trabalhar com macros, é essencial usar parênteses para evitar erros de precedência e garantir que o comportamento esperado seja mantido.
- A definição de macros com parâmetros permite a criação de código reutilizável, mas deve ser feita com cautela para evitar erros sutis.

## Compilação

Para compilar os exemplos, você pode usar o seguinte comando:

```bash
gcc -o preprocessador_macros_exemplos preprocessador_macros_exemplos.c
./preprocessador_macros_exemplos
```

A execução do programa vai demonstrar o uso de macros e pré-processador em C.

## 📚 Referência
> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
