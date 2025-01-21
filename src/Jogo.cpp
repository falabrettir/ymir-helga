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

  Ente::setGerenciadorGrafico(pGG);

  // TODO: Colocar Entidades em uma lista dentro da fase
  pJog1 = new Entidades::Personagens::Jogador();
  pJog2 = new Entidades::Personagens::Jogador(false);
  pPlataforma = new Entidades::Obstaculos::Plataforma();

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
  while (pGG->janelaAberta())
    atualizar();
}
