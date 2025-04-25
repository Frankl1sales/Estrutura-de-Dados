# Defina a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Defina o nome do projeto
project(SortSimulator C)

# Defina as flags para o compilador
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Verifique se o GTK+ 3.0 está instalado e configure o pacote
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Adicione os arquivos de origem
set(SOURCES sort_simulator.c)

# Crie o executável com o nome "sort_simulator"
add_executable(sort_simulator ${SOURCES})

# Vincule a biblioteca GTK+ 3.0 ao seu executável
target_include_directories(sort_simulator PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_libraries(sort_simulator ${GTK3_LIBRARIES})

# Defina os flags de compilação com base no pkg-config
target_compile_options(sort_simulator PRIVATE ${GTK3_CFLAGS_OTHER})
target_link_options(sort_simulator PRIVATE ${GTK3_LDFLAGS})

