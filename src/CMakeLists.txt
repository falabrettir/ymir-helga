# lib Gerenciador_Grafico
add_library(gerenciador-grafico ./gerenciador-grafico.cpp)

target_include_directories(gerenciador-grafico
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(gerenciador-grafico
  PUBLIC
  sfml-graphics
  sfml-window
  sfml-system
)

#lib Jogo
add_library(jogo ./jogo.cpp)

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

# ---------------------------------------
# Executável principal
add_executable(main ./main.cpp)

target_include_directories(main
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(main
  PUBLIC
  jogo
)
