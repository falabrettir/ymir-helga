#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();

  // TODO: Colocar GC dentro da fase
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  pGE->setGG(pGG);
  pGE->setGI(pGI);

  // TODO: Colocar GC dentro da fase
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  // TODO: Colocar Entidades em uma lista dentro da fase
  pSkjolder = new Entidades::Personagens::Skjolder();
  pHelga = new Entidades::Personagens::Helga();
  pPlataforma = new Entidades::Obstaculos::Plataforma();

  pGC->incluirPers(pSkjolder);
  pGC->incluirPers(pHelga);
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
  pSkjolder->debug.setPosition(pSkjolder->getPos());
  pGG->getJanela()->draw(pPlataforma->debug);
  pGG->getJanela()->draw(pSkjolder->debug);
  pGG->desenharEnte(static_cast<Ente *>(pPlataforma));
  pGG->desenharEnte(static_cast<Ente *>(pSkjolder));
  pGG->desenharEnte(static_cast<Ente *>(pHelga));

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();
}

void Jogo::executar() {
  while (pGG->janelaAberta())
    atualizar();
}
