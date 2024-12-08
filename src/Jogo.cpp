#include "Jogo.h"
#include <SFML/Graphics/Color.hpp>

Jogo::Jogo() {
  // : pGG(Gerenciadores::Gerenciador_Grafico::getInstancia()),
  // pGE(Gerenciadores::Gerenciador_Eventos::getInstancia() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
}

Jogo::~Jogo() {}

void Jogo::executar() {

  while (pGG->janelaAberta()) {
    pGG->clear();
    pGE->processaEventos(pGG);
    pGG->display();
  }
}
