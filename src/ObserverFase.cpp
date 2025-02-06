#include "ObserverFase.h"

#include <iostream>
#include <map>

#include "Gerenciadores/GerenciadorEstados.h"
#include "IDs.h"
#include "Menu/MenuPausa.h"
#include "Observer.h"

ObservadorFase::ObservadorFase(Fases::Fase* fAtual)
    : Observer(),
      fAtual(fAtual),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()),
      pGI(Gerenciadores::GerenciadorInput::getInstancia()),
      teclasPressionadas() {
  pause = sf::Keyboard::Escape;
  teclasPressionadas.insert(std::pair<Key, bool>(pause, false));
  pGI->inscrever(this);
}

ObservadorFase::~ObservadorFase() {}

bool ObservadorFase::acharTecla(Key tecla) {
  return teclasPressionadas.find(tecla) != teclasPressionadas.end();
}
void ObservadorFase::atualizarTeclasPressionadas(sf::Keyboard::Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = true;
  }
}
void ObservadorFase::atualizarTeclasSoltas(sf::Keyboard::Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = false;
  }
}
void ObservadorFase::pausar() {
  std::cerr << "Pausar chamado\n";
  if (pGS->topEstado()->getId() == ID::IDfase) {
    std::cerr << "Dentro do if de Pausar\n";
    pGS->pushEstado(new Menus::MenuPausa(ID::IDmenupause, fAtual));
  }
}
void ObservadorFase::notificarJogadorMorreu() {
  // pGS->pushEstado(new Menus::MenuGameOver(ID::IDmenugameover));
}
void ObservadorFase::notificarProjetil() {}
void ObservadorFase::executar() {
  if (teclasPressionadas[pause]) {
    pausar();
  }  // TODO: notificarProjetil e notificarJogadorMorreu
}
