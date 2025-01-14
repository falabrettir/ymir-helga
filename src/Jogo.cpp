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

void Jogo::atualizar() {
  pGE->processaEventos();

  pGG->atualizaDeltaTempo();

  pSkjolder->executar();

  pGG->desenharEnte(static_cast<Ente *>(pSkjolder));

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();
}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    atualizar();
  }
}
