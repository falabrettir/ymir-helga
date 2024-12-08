# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
set(SFML_GRAPHICS_LIBS sfml-graphics sfml-window sfml-system)
set(SFML_AUDIO_LIBS sfml-audio sfml-system)

# ---------------------------------------------------------
# Biblioteca Gerenciadores+Ente
add_library(gerenciadores-core
  Gerenciadores/GerenciadorGrafico.cpp
  Gerenciadores/GerenciadorEventos.cpp
  Ente/Ente.cpp
)

target_link_libraries(gerenciadores-core
  PRIVATE
  ${SFML_GRAPHICS_LIBS}
)

# ---------------------------------------------------------
# Biblioteca Jogo
add_library(jogo
  Jogo.cpp
)

target_link_libraries(jogo
  PRIVATE
  ${SFML_LIBS}
  gerenciadores-core
)

# ---------------------------------------------------------
# Executável principal

add_executable(simon_says
  Main.cpp
)

target_link_libraries(simon_says
  PRIVATE
  ${SFML_LIBS}
  jogo
  gerenciadores-core
)
