#include "Jogo.h"

#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();
  Ente::setGerenciadorGrafico(pGG);

  pGC->incluirPers(pJog1);
  pGC->incluirPers(pJog2);
  pGC->incluirObst(pPlataforma);

  pGI->inscrever(pJog1->getControlador());
  pGI->inscrever(pJog2->getControlador());

  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::atualizar() {
  pGE->processaEventos();

  pGG->atualizaDeltaTempo();

  pGC->executar();

  pJog1->executar();
  pJog2->executar();
  pGG->desenharEnte(static_cast<Ente *>(pPlataforma));
  pGG->desenharEnte(static_cast<Ente *>(pJog1));
  pGG->desenharEnte(static_cast<Ente *>(pJog2));

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();
}

void Jogo::executar() {
  while (pGG->janelaAberta()) atualizar();
}
