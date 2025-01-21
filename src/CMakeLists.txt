# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)

# ---------------------------------------------------------
# Biblioteca Jogo

add_library(jogo
  # Raiz do projeto
  Jogo.cpp
  Ente.cpp
  Observer.cpp
  Subject.cpp

  # Diretorio Gerenciadores
  Gerenciadores/GerenciadorGrafico.cpp
  Gerenciadores/GerenciadorEventos.cpp
  Gerenciadores/GerenciadorInput.cpp
  Gerenciadores/GerenciadorColisoes.cpp

  # Diretorio Controladores
  Controladores/ControladorJogador.cpp

  # Diretorio Entidades
  Entidades/Entidade.cpp
  Entidades/Personagens/Jogador.cpp
  Entidades/Personagens/Personagem.cpp
  Entidades/Personagens/Inimigo.cpp
  Entidades/Personagens/Slime.cpp
  Entidades/Obstaculos/Obstaculo.cpp
  Entidades/Obstaculos/Plataforma.cpp
)

target_link_libraries(jogo
  PRIVATE
  ${SFML_LIBS}
)

# ---------------------------------------------------------
# Executável principal

add_executable(main
  Main.cpp
)

target_link_libraries(main
  PRIVATE
  jogo
)
