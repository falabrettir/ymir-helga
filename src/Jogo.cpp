#include "Jogo.h"

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pJog = new Entidades::Personagens::Jogador();
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pJog->executar();

    pGE->processaEventos(pGG);

    pGG->display();
  }
}
