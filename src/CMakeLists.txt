# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
set(SFML_GRAPHICS_LIBS sfml-graphics sfml-window sfml-system)
set(SFML_AUDIO_LIBS sfml-audio sfml-system)

# ---------------------------------------------------------
# Biblioteca Gerenciador_Eventos
add_library(gerenciador-eventos
  gerenciadores/gerenciador-eventos.cpp
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
# Biblioteca Gerenciador_Grafico
add_library(gerenciador-grafico
  gerenciadores/gerenciador-grafico.cpp
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
# Biblioteca Jogo
add_library(jogo jogo.cpp)

target_include_directories(jogo
  PUBLIC
  ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(jogo
  PUBLIC
  ${SFML_LIBS}
  gerenciador-grafico
)

# ---------------------------------------------------------
# Executável principal
add_executable(simon_says main.cpp)

target_include_directories(simon_says
  PUBLIC
  ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(simon_says
  PUBLIC
  jogo
)
