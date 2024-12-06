# Variáveis de configuração
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
set(SFML_GRAPHICS_LIBS sfml-graphics sfml-window sfml-system)
set(SFML_AUDIO_LIBS sfml-audio sfml-system)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Lib Gerenciador_Eventos
add_library(gerenciador-eventos
  ./gerenciadores/gerenciador-eventos.cpp
)

target_include_directories(gerenciador-eventos
  PUBLIC
  ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(gerenciador-eventos
  PUBLIC
  ${SFML_GRAPHICS_LIBS}
)

# ---------------------------------------------------------
# lib Gerenciador_Grafico
add_library(gerenciador-grafico
  ./gerenciadores/gerenciador-grafico.cpp
)

target_include_directories(gerenciador-grafico
  PUBLIC
  ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(gerenciador-grafico
  PUBLIC
  ${SFML_GRAPHICS_LIBS}
  gerenciador-eventos
)

# ---------------------------------------------------------
#lib Jogo
add_library(jogo ./jogo.cpp)

target_include_directories(jogo
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(jogo
  PUBLIC
  ${SFML_LIBS}
  gerenciador-grafico
  gerenciador-eventos
)

# ---------------------------------------------------------
# Executável principal
add_executable(main ./main.cpp)

target_include_directories(main
  PUBLIC
  ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(main
  PUBLIC
  jogo
)
