# Definindo a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto C)

# Definindo o padrão de compilação para C
set(CMAKE_C_STANDARD 11)

# Adicionando o executável que será gerado a partir do arquivo main.c
add_executable(meu_projeto main.c)
