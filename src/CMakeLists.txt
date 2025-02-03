# Variáveis de dependências
set(SFML_LIBS sfml-graphics sfml-window sfml-system sfml-audio)

# ---------------------------------------------------------
# Biblioteca Jogo

add_library(jogo
  # Raiz do projeto
  Jogo.cpp
  Ente.cpp
  State.cpp

  # Diretorio Observer
  Observer/Observer.cpp
  Observer/Subject.cpp

  # Diretorio Gerenciadores
  Gerenciadores/GerenciadorColisoes.cpp
  Gerenciadores/GerenciadorEstados.cpp
  Gerenciadores/GerenciadorEventos.cpp
  Gerenciadores/GerenciadorGrafico.cpp
  Gerenciadores/GerenciadorInput.cpp

  # Diretorio Controladores
  Controladores/ControladorJogador.cpp
  Controladores/ControladorMenu.cpp

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

  # Diretorio Fabrica
  Fabrica/FabricaEntidadesCaverna.cpp
  Fabrica/FabricaEntidades.cpp
  Fabrica/FabricaEntidadesPlanicie.cpp
  Fabrica/FabricaFireball.cpp
  Fabrica/FabricaFlechas.cpp
  Fabrica/FabricaProjeteis.cpp

  # Entidades::Obstaculos
  Entidades/Obstaculos/Espinho.cpp
  Entidades/Obstaculos/Gosma.cpp
  Entidades/Obstaculos/Obstaculo.cpp
  Entidades/Obstaculos/Plataforma.cpp

  # Diretorio Fases
  Fases/Caverna.cpp
  Fases/Fase.cpp
  Fases/Planicie.cpp

  #Diretorio Menu
  Menu/Menu.cpp
  Menu/MenuPrincipal.cpp
  Menu/Botao.cpp

  # Diretorio Listas
  Listas/ListaEntidade.cpp
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
