#include "Jogo.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pObst = new Entidades::Obstaculos::Plataforma();

  pSkjolder = new Entidades::Personagens::Skjolder();
  std::cerr << "skjolder criado" << std::endl;

  pHelga = new Entidades::Personagens::Helga();
  std::cerr << "helga criada" << std::endl;

  pGC->incluirChar(pHelga);
  pGC->incluirChar(pSkjolder);
  pGC->incluirObst(pObst);

  pGI->inscrever(pSkjolder->getControlador());
  pGI->inscrever(pHelga->getControlador());

  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::atualizar() {

  pGE->processaEventos();

  pGG->atualizaDeltaTempo();

  pSkjolder->executar();
  pHelga->executar();

  pGG->desenharEnte(static_cast<Ente *>(pSkjolder));
  pGG->desenharEnte(static_cast<Ente *>(pHelga));

  // Sempre deixar display antes de clear
  pGG->display();

  pGG->clear();
}

void Jogo::executar() {

  while (pGG->janelaAberta()) {
    atualizar();
  }
}
