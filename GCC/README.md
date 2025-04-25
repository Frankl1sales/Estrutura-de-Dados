# Exemplo Básico em C com GCC

Este exemplo é uma introdução prática ao uso do compilador **GCC** para programas escritos na linguagem **C**. Ele demonstra como compilar e executar código C na linha de comando, além de apresentar uma pequena biblioteca para cálculo de áreas.

---

## 🧠 Conceitos Básicos

O **GCC** (GNU Compiler Collection) é um compilador de código aberto amplamente utilizado. Ele transforma seu código C em um programa binário (executável) que pode ser executado pelo computador.

### Etapas do compilador

1. **Analisador Léxico**: quebra o código em tokens.
2. **Analisador Sintático**: verifica se os tokens seguem a gramática da linguagem.
3. **Analisador Semântico**: verifica o sentido das instruções.

---

## 📁 Estrutura do Exemplo

```bash
 ├── 📄 area.c // Implementação das funções de área 
 ├── 📄 area.h // Cabeçalho com definições e protótipos 
 ├── 📄 main.c // Função principal 
 └── 📄 README.md // Este arquivo
```

---

## 🔧 Como Compilar e Executar

### 1. Compilar com GCC

```bash
gcc -Wall -Wextra main.c area.c -o programa -lm
```

Explicando as flags:

- **Wall**: mostra alertas comuns.
- **Wextra**: mostra alertas adicionais.
- **lm**: linka a biblioteca de matemática.
- **o** programa: define o nome do executável.

### 2. Executar

```bash
./programa
```

### 📌 Dica Extra

Se seu compilador reclamar que M_PI não está definido (erro comum no GCC), você já está protegido — o valor foi definido diretamente em area.h!

### Teste Rápido

```bash
gcc -Wall -Wextra main.c area.c -o programa -lm
./programa
```

```bash
Área do círculo de raio 2.00: 12.57
Área do triângulo com lados 3.00, 4.00, 5.00: 6.00
```

## **Referências**  

Este projeto foi desenvolvido com base no material didático do **Prof. André Grégio**, apresentado no tutorial:

> **Grégio, A.** Tutorial GCC – Introdução ao uso do compilador GCC no desenvolvimento em linguagem C.  
> Departamento de Informática – Universidade Federal do Paraná (UFPR).  
> Disponível em: [https://www.inf.ufpr.br/gregio/CI1056/TutorialGCC.pdf](https://www.inf.ufpr.br/gregio/CI1056/TutorialGCC.pdf)
