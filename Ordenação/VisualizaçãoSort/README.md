# Simulador de Algoritmos de Ordenação

Este projeto implementa uma interface gráfica para visualizar a execução de três algoritmos de ordenação: **BubbleSort**, **MergeSort** e **QuickSort**. Ele usa o GTK+ 3.0 para criar a interface gráfica e permitir ao usuário escolher o algoritmo e visualizar o processo de ordenação.

## Requisitos

- **GTK+ 3.0**: Certifique-se de ter o GTK+ 3.0 instalado em seu sistema.
- **CMake**: O projeto utiliza o CMake para configuração e construção.
- **GCC**: Compilador C.

## No Ubuntu, você pode instalar o GTK+ 3.0 com o seguinte comando:

```bash
sudo apt-get install libgtk-3-dev
```

### Passo 1: Configurar o projeto com CMake

Crie um diretório de build e configure o projeto com CMake:

```bash
mkdir build
cd build
cmake ..
```

### Passo 2: Compilar o projeto

Compile o projeto utilizando CMake e o GCC:

```bash
cmake --build .
```

Ou, se preferir usar o comando direto do GCC (como mencionado na sua solicitação):

```bash
gcc -o sort_simulator sort_simulator.c $(pkg-config --cflags --libs gtk+-3.0)
```

### Passo 3: Executar o simulador

Após a compilação, execute o simulador:

```bash
./sort_simulator
```

## interface gráfica
Isso abrirá a janela com a interface gráfica, onde você poderá selecionar o algoritmo de ordenação e visualizar a execução.

### Como Funciona

O simulador permite ao usuário escolher entre três algoritmos de ordenação:

- BubbleSort
- MergeSort
- QuickSort

Uma vez que o algoritmo é selecionado, o botão "Iniciar Ordenação" executa o algoritmo escolhido e visualiza a ordenação em tempo real.
Contribuindo

Se você quiser contribuir para este projeto, sinta-se à vontade para abrir issues e pull requests.

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE.md para mais detalhes.


### Explicação do `CMakeLists.txt`:

1. **Versão do CMake**: A primeira linha define a versão mínima necessária do CMake para o projeto. Neste caso, é a versão 3.10.
2. **Projeto**: A linha `project(SortSimulator C)` define o nome do projeto e a linguagem utilizada (C).
3. **Flags de compilação**: A linha `set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")` adiciona a flag `-Wall` para exibir todos os avisos durante a compilação.
4. **PkgConfig e GTK+**: Utiliza o `pkg-config` para verificar se o GTK+ 3.0 está instalado e obter as flags de compilação e vinculação adequadas.
5. **Arquivos de origem**: A variável `SOURCES` contém os arquivos de origem para o projeto (no caso, o arquivo `sort_simulator.c`).
6. **Criação do executável**: A linha `add_executable(sort_simulator ${SOURCES})` cria o executável a partir dos arquivos de origem.
7. **Vinculação das bibliotecas**: As bibliotecas GTK+ 3.0 são vinculadas ao executável com as diretivas `target_include_directories` e `target_link_libraries`.
8. **Flags de compilação adicionais**: Utiliza `target_compile_options` e `target_link_options` para configurar as opções de compilação e vinculação, conforme o `pkg-config`.
