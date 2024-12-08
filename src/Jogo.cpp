#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
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
    while (pGG->pollEvent(pGE->getEvento()))
      pGG->clear();
    pGG->display();
  }
}
