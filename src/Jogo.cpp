#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pSkjolder = new Entidades::Personagens::Skjolder();

  pGI->inscrever(pSkjolder->getControlador());

  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pGE->processaEventos();

    pGG->atualizaDeltaTempo();

    pGG->desenharEnte(pSkjolder);

    pGG->display();
  }
}
