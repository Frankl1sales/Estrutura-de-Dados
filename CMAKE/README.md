# Meu Projeto C com CMake

Este é um exemplo básico de um projeto em C configurado com o CMake. O projeto simplesmente imprime "Olá, mundo!" na tela.

## Como Usar

### Passo 1: Compilar o Projeto

Para compilar o projeto, você precisa ter o CMake instalado. Se não tiver o CMake, pode instalá-lo com o seguinte comando (em distribuições baseadas no Debian):

```bash
sudo apt-get install cmake
```

Depois de garantir que o CMake está instalado, crie uma pasta para os arquivos de build e execute o CMake:

mkdir build
cd build
cmake ..
make

### Passo 2: Executar o Programa

Depois de compilar, você pode executar o programa com o seguinte comando na pasta build:

```bash
./meu_projeto
```

Isso deve exibir a mensagem:

- Olá, mundo! Este é um projeto C com CMake.

Descrição

Este projeto é um exemplo simples para demonstrar como usar o CMake para compilar um programa C. O arquivo CMakeLists.txt está configurado para compilar o código contido em main.c.
Contribuindo

Se você deseja contribuir para este projeto, por favor, envie um pull request.


### Como Funciona

1. **CMake**:
   - O `CMakeLists.txt` define o projeto, especifica a versão mínima do CMake e inclui as instruções para compilar o código.
   - O CMake gera arquivos de construção para o seu ambiente (por exemplo, Makefiles para sistemas baseados no Linux).

2. **Compilação**:
   - O comando `cmake ..` gera os arquivos necessários para a construção no diretório `build`.
   - O comando `make` compila o código com base nos arquivos gerados pelo CMake.

3. **Execução**:
   - Após a compilação, o programa executável será gerado no diretório `build`, e você pode rodá-lo com o comando `./meu_projeto`.



