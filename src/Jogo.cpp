#include "Jogo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  Ente::setGerenciadorGrafico(pGG);

  pJog = new Entidades::Personagens::Jogador(
      sf::Vector2<float>(larguraJanela / 2.0, alturaJanela / 2.0),
      sf::Vector2<float>(16.0, 16.0),
      "/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pJog->desenhar();

    pGE->processaEventos(pGG);

    pGG->display();
  }
}
