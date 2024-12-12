#include "Jogo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Slime.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  Ente::setGerenciadorGrafico(pGG);

  pJog = new Entidades::Personagens::Jogador(
      sf::Vector2<float>(50.0, 50.0), sf::Vector2<float>(16.0, 16.0),
      "/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
  pSl = new Inimigos::Slime(
      sf::Vector2<float>(90.0, 90.0), sf::Vector2<float>(16.0, 16.0),
      "/assets/Characters(100x100)/Slime/Slime/Slime-Idle.png");
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pGE->processaEventos(pGG);

    pGG->atualizaDeltaTempo();

    pGE->processaInput(pJog);

    pSl->desenhar();

    pJog->desenhar();

    pGG->display();
  }
}
