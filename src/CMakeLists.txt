# Package GerenciadorGrafico
add_library(gerenciador-grafico)

target_include_directories(gerenciador-grafico
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

# ---------------------------------------
# Executável principal
add_executable(jogo ./jogo.cpp)

target_include_directories(jogo
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(jogo
  PUBLIC
  sfml-graphic
  sfml-window
  sfml-system
  sfml-audio
  gerenciador-grafico
)
