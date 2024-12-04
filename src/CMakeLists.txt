# Package GerenciadorGrafico
add_library(gerenciador-grafico)

# ---------------------------------------
# Executável principal
add_executable(jogo ./Jogo.cpp)

target_include_directories(jogo
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(jogo
  PUBLIC
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
  gerenciador-grafico
)
