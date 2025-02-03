#include "Jogo.h"

#include <SFML/System/Vector2.hpp>

#include "Fases/Caverna.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "IDs.h"
#include "Menu/MenuPrincipal.h"

Jogo::Jogo()
    : pGG(Gerenciadores::GerenciadorGrafico::getInstancia()),
      pGE(Gerenciadores::GerenciadorEventos::getInstancia()),
      pGI(Gerenciadores::GerenciadorInput::getInstancia()),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()) {
  // caverna = new Fases::Caverna();
  // pGS->pushEstado(caverna);
  pGS->pushEstado(new Menus::MenuPrincipal(ID::IDmenuprincipal));
  // pGS->pushEstado(new MenuPrincipal());
}

Jogo::~Jogo() {}

void Jogo::atualizar() {
  pGE->processaEventos();

  pGG->atualizaDeltaTempo();
  pGS->executar();

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();
}

void Jogo::executar() {
  while (pGG->janelaAberta()) atualizar();
}
