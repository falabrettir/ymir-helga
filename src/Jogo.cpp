#include "Jogo.h"

#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "Menu/MenuPrincipal.h"

Jogo::Jogo()
    : pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
      pGE(Gerenciadores::GerenciadorEventos::getInstancia()),
      pGI(Gerenciadores::GerenciadorInput::getInstancia()),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()) {
  // caverna = new Fases::Caverna();
  // pGS->pushEstado(caverna);
  pGS->inserirEstado(Menus::MenuPrincipal::getInstancia());
  // pGS->pushEstado(new MenuPrincipal());
}

Jogo::~Jogo() {}

void Jogo::atualizar() {
  pGE->processaEventos();

  pGS->executar();

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();

  pGG->atualizaDeltaTempo();
}

void Jogo::executar() {
  while (pGG->janelaAberta()) atualizar();
}
