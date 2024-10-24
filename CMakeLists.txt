cmake_minimum_required(VERSION 3.28)
project(SimonSays LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Adicionar arquivos de código fonte
set(SOURCES
./src/main.cpp
./src/utils.cpp)

# Adicionar arquivos de cabeçalho
set(HEADER_FILES
./include/utils.hpp)

add_executable(exe ${SOURCES} ${HEADER_FILES})
target_include_directories(exe PRIVATE ./include/)

target_link_libraries(exe PRIVATE sfml-graphics)
