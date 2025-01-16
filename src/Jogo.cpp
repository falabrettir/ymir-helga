#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  pGE->setGG(pGG);
  pGE->setGI(pGI);

  // TODO: Colocar GC dentro da fase
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pSkjolder = new Entidades::Personagens::Skjolder();
  std::cerr << "skjolder criado" << std::endl;

  pHelga = new Entidades::Personagens::Helga();
  std::cerr << "helga criada" << std::endl;

  pPlataforma = new Entidades::Obstaculos::Plataforma();
  std::cerr << "prataforma criada" << std::endl;

  pGC->incluirChar(pSkjolder);
  pGC->incluirChar(pHelga);
  pGC->incluirObst(pPlataforma);
  pGI->inscrever(pSkjolder->getControlador());
  pGI->inscrever(pHelga->getControlador());
}

Jogo::~Jogo() {}

void Jogo::atualizar() {

  pGE->processaEventos();

  pGG->atualizaDeltaTempo();

  pGC->executar();

  pSkjolder->executar();
  pHelga->executar();

  pGG->desenharEnte(static_cast<Ente *>(pPlataforma));
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
