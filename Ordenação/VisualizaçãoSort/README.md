Visualizador de Algoritmos de Ordenação com GTK

Este projeto é uma aplicação gráfica feita em C utilizando a biblioteca GTK+ 3, que permite visualizar o funcionamento de algoritmos de ordenação em tempo real: BubbleSort, MergeSort e QuickSort.
📸 Captura de Tela

(Adicione uma imagem da interface gráfica aqui, se desejar)
📋 Requisitos

    GTK+ 3

    CMake

    gcc

No Ubuntu/Debian, você pode instalar os pacotes necessários com:

sudo apt update
sudo apt install build-essential cmake libgtk-3-dev

📦 Compilação com CMake
1. Clonar o repositório

git clone https://github.com/seuusuario/sorting-visualizer-gtk.git
cd sorting-visualizer-gtk

2. Gerar build com CMake

mkdir build
cd build
cmake ..
make

3. Executar o programa

./sorting_visualizer

📁 Estrutura do Projeto

sorting-visualizer-gtk/
├── CMakeLists.txt
├── main.c
└── README.md

⚙️ CMakeLists.txt

Aqui está um exemplo de CMakeLists.txt para compilar o projeto:

cmake_minimum_required(VERSION 3.10)
project(sorting_visualizer C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(sorting_visualizer main.c)
target_link_libraries(sorting_visualizer ${GTK3_LIBRARIES})

🚀 Como Usar

    Abra o programa.

    Escolha um dos algoritmos disponíveis:

        BubbleSort

        MergeSort

        QuickSort

    Clique em Iniciar Ordenação.

    Observe as barras sendo ordenadas visualmente na tela!

🧠 Sobre os Algoritmos

    BubbleSort: Ordenação simples que compara pares adjacentes e troca se necessário.

    MergeSort: Algoritmo eficiente de divisão e conquista.

    QuickSort: Algoritmo recursivo baseado em partições com pivôs.

🛠️ Desenvolvido com

    GTK+ 3

    C

    CMake

👨‍💻 Autor

Feito com 💻 por [Seu Nome]