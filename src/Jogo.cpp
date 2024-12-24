#include "Jogo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  Ente::setGerenciadorGrafico(pGG);
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
