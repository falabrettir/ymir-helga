#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() : pJog2(nullptr), pSl(nullptr) {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pJog1 = new Skjolder();

  pGI->inscrever(pJog1->getControlador());

  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGE->processaEventos();

    pGG->atualizaDeltaTempo();

    pGG->desenharEnte(pJog1);

    pGG->clear();
    pGG->display();
  }
}
