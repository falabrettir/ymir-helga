# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)
set(SFML_GRAPHICS_LIBS sfml-graphics sfml-window sfml-system)
set(SFML_AUDIO_LIBS sfml-audio sfml-system)

# ---------------------------------------------------------
# Biblioteca Gerenciadores+Ente
add_library(gerenciadores-core
  Gerenciadores/GerenciadorGrafico.cpp
  Gerenciadores/GerenciadorEventos.cpp
  Ente.cpp
)

target_link_libraries(gerenciadores-core
  PRIVATE
  ${SFML_GRAPHICS_LIBS}
)

# ---------------------------------------------------------
# Biblioteca Entidades
add_library(entidades
  Entidades/Entidade.cpp
  Entidades/Personagens/Jogador.cpp
  Entidades/Personagens/Personagem.cpp
  Entidades/Personagens/Inimigo.cpp
  Entidades/Personagens/Slime.cpp
)

target_link_libraries(gerenciadores-core
  PRIVATE
  ${SFML_LIBS}
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
  entidades
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
