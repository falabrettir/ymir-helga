#include "Jogo.h"
#include "Controladores/ControladorJogador.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pJog1 = new Skjolder();

  pGI->setContrJog(pJog1->getControlador());
  pGI->inscrever(pJog1->getControlador());
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pGE->processaEventos();

    pGG->atualizaDeltaTempo();

    pGG->desenharEnte(pJog1);

    pGG->display();
  }
}
