#include "Gerenciadores/GerenciadorEstados.h"

#include <cstdlib>
#include <iostream>

#include "State.h"

namespace Gerenciadores {

GerenciadorEstados* GerenciadorEstados::instancia = nullptr;

GerenciadorEstados::GerenciadorEstados()
    : mapStates(), idAtual(ID::unknown), idAnterior(ID::unknown) {}

GerenciadorEstados::~GerenciadorEstados() {
  std::map<ID, States::State*>::iterator it;
  for (it = mapStates.begin(); it != mapStates.end(); ++it) {
    delete it->second;
  }
}

GerenciadorEstados* GerenciadorEstados::getInstancia() {
  if (!instancia) {
    instancia = new GerenciadorEstados();
  }
  return instancia;
}

void GerenciadorEstados::executar() { mapStates[idAtual]->executar(); }

void GerenciadorEstados::mudarEstado(ID id) {
  idAnterior = idAtual;
  idAtual = id;
}

void GerenciadorEstados::inserirEstado(States::State* s) {
  if (s) {
    mapStates.insert(std::pair<ID, States::State*>(s->getId(), s));
    if (idAtual == ID::unknown) {
      mudarEstado(s->getId());
    }
  } else {
    std::cerr << "Ponteiro nulo em GerenciadorEstados::pushEstado\n";
    exit(EXIT_FAILURE);
  }
}
const ID GerenciadorEstados::getEstadoAnterior() { return this->idAnterior; }
const ID GerenciadorEstados::getEstadoAtual() { return this->idAtual; }

}  // namespace Gerenciadores
