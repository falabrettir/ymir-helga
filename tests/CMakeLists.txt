# Procurar Catch2 (necessário para testes)
find_package(Catch2 REQUIRED)

# Executável dos testes
add_executable(tests
  MainTests.cpp
)

# Adiciona o diretorio 'include/'
target_include_directories(tests
  PRIVATE
  ${PROJECT_INCLUDE_DIR}
)

# Linka todos os arquivos de implementacao do jogo aos testes
target_link_libraries(tests
  PUBLIC
  jogo
  Catch2::Catch2
)

# Descoberta automática de testes
include(CTest)
include(Catch)
catch_discover_tests(tests)
