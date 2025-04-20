# Manipulação de Arquivos em C

Este projeto contém exemplos de leitura e escrita de arquivos em C, baseados nos materiais da disciplina **Estruturas de Dados – PUC-Rio**.

## Exemplos

### 1. Acesso Caractere a Caractere

- **`caractere_linhas.c`**: Conta o número de linhas do arquivo `entrada.txt`.
- **`caractere_maiusculas.c`**: Converte todo o conteúdo de um arquivo texto para letras maiúsculas.

### 2. Acesso Linha a Linha

- **`linha_subcadeia.c`**: Procura uma subcadeia dentro de cada linha de um arquivo.
- **`linha_figuras.c`**: Interpreta figuras geométricas salvas linha a linha em `figuras.txt`.
- **`linha_pontos3d.c`**: Lê coordenadas de pontos em 3D ou 2D do arquivo `pontos3d.txt`.

## Como Compilar

```sh
gcc caractere_linhas.c -o caractere_linhas
gcc caractere_maiusculas.c -o caractere_maiusculas
gcc linha_subcadeia.c -o linha_subcadeia
gcc linha_figuras.c -o linha_figuras
gcc linha_pontos3d.c -o linha_pontos3d
```

## Como Executar

```sh
./caractere_linhas
./caractere_maiusculas
./linha_subcadeia
./linha_figuras
./linha_pontos3d
```

>Obs.: Verifique se os arquivos entrada.txt, figuras.txt e pontos3d.txt estão presentes no diretório.