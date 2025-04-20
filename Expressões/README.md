# Operadores em C

Este exemplo demonstra o uso de diversos operadores em linguagem C, conforme apresentado na disciplina de Estruturas de Dados em (CELES; RANGEL, 2002).

## Conteúdo Demonstrado

### 🔢 Operadores Aritméticos
- `+`, `-`, `*`, `/`, `%` (módulo)
- Divisão inteira versus divisão real
- Exemplo de verificação de número par ou ímpar com `%`

### 🧮 Atribuição e Operadores Compostos
- `=`, `+=`, `-=`, `*=`, `/=`, `%=`
- Exemplo: `i += 2` equivalente a `i = i + 2`

### ⬆️ Incremento e Decremento
- Pós e pré-incremento: `n++` e `++n`
- Uso prático com diferença entre os dois

### 🔍 Operadores Relacionais
- `==`, `!=`, `<`, `>`, `<=`, `>=`

### 🔗 Operadores Lógicos
- `&&` (E), `||` (OU), `!` (negação)
- Curto-circuito na avaliação de expressões

### 📏 sizeof
- Retorna o tamanho de tipos de dados em bytes
- Exemplo: `sizeof(float)` retorna 4

### 🔄 Conversão de Tipo (Casting)
- Conversão explícita com `(tipo)`
- Demonstração da conversão de `double` para `int`

## Compilação e Execução

Para compilar e executar o programa:

```bash
gcc operadores.c -o operadores
./operadores
```

## 📚 Referência

> CELES, Waldemar; RANGEL, José Lucas. *Apostila de Estruturas de Dados*. Rio de Janeiro: PUC-Rio, Curso de Engenharia, 2002. Disponível em: [https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf](https://www-usr.inf.ufsm.br/~juvizzotto/elc1067-2013b/estrut-dados-pucrio.pdf). Acesso em: 17 abr. 2025.
---