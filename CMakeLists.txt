cmake_minimum_required(VERSION 3.20)
project(SimonSays LANGUAGES CXX)

# Configurações do projeto
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

# Padrões de compilação
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Adiciona CMAKE_SOURCE_DIR como variável global
add_compile_definitions(ROOT="${CMAKE_SOURCE_DIR}")

# Diretório de saída dos binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Opção para construir bibliotecas compartilhadas
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Diretório de includes do projeto
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${PROJECT_INCLUDE_DIR})

# Subdiretórios do projeto
add_subdirectory(src)
add_subdirectory(tests)
