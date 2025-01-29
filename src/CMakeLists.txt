# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)

# ---------------------------------------------------------
# Biblioteca Jogo

add_library(jogo
  # Raiz do projeto
  Jogo.cpp
  Ente.cpp

  # Diretorio Observer
  Observer/Observer.cpp
  Observer/Subject.cpp

  # Diretorio Gerenciadores
  Gerenciadores/GerenciadorGrafico.cpp
  Gerenciadores/GerenciadorEventos.cpp
  Gerenciadores/GerenciadorInput.cpp
  Gerenciadores/GerenciadorColisoes.cpp
  Gerenciadores/GerenciadorEstados.cpp

  # Diretorio Controladores
  Controladores/ControladorJogador.cpp

  # Diretorio Entidades
  Entidades/Entidade.cpp
  Entidades/Projetil.cpp

  # Entidades::Personagens
  Entidades/Personagens/Esqueleto.cpp
  Entidades/Personagens/Inimigo.cpp
  Entidades/Personagens/Jogador.cpp
  Entidades/Personagens/Mago.cpp
  Entidades/Personagens/Personagem.cpp
  Entidades/Personagens/Slime.cpp

  # Entidades::Obstaculos
  Entidades/Obstaculos/Obstaculo.cpp
  Entidades/Obstaculos/Plataforma.cpp
  Entidades/Obstaculos/Espinho.cpp
  Entidades/Obstaculos/Gosma.cpp

  # Diretorio Fases
  Fases/Caverna.cpp
  Fases/Fase.cpp
  Fases/Planicie.cpp

  # Diretorio Listas
  Listas/ListaEntidade.cpp

  # Diretorio Fabrica
  Fabrica/FabricaEntidades.cpp
  Fabrica/FabricaEntidadesCaverna.cpp
  Fabrica/FabricaEntidadesPlanicie.cpp
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
