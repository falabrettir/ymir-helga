#include "ObserverFase.h"

#include <iostream>
#include <map>

#include "Fases/Planicie.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "IDs.h"
#include "Menu/MenuPausa.h"
#include "Menu/MenuPrincipal.h"
#include "Observer.h"

ObservadorFase::ObservadorFase(Fases::Fase *fAtual)
    : Observer(), fAtual(fAtual),
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
  if (pGS->getEstadoAtual() == ID::IDcaverna ||
      pGS->getEstadoAtual() == ID::IDplanicie) {
    std::cerr << "Dentro do if de Pausar\n";
    pGS->inserirEstado(Menus::MenuPausa::getInstancia());
    pGS->mudarEstado(ID::IDmenupause);
  }
}
void ObservadorFase::notificarJogadorMorreu() {
  // pGS->pushEstado(new Menus::MenuGameOver(ID::IDmenugameover));
}
void ObservadorFase::executar() {
  if (teclasPressionadas[pause]) {
    pausar();
  }
}
void ObservadorFase::notificarFim() {
  if (fAtual->States::State::getId() == ID::IDcaverna) {
    std::clog << "NotficarFim" << std::endl;
    fAtual->limparListas();
    pGS->inserirEstado(
        new Fases::Planicie(Menus::MenuPrincipal::getInstancia()->getMp()));
    pGS->mudarEstado(ID::IDplanicie);
  } else {
    std::clog << "WINNER WINNER CHICKEN DINNER" << std::endl;
  } // TODO: COZER
}
