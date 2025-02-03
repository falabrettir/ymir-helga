#include "Gerenciadores/GerenciadorEstados.h"

#include <cstdlib>
#include <iostream>

namespace Gerenciadores {

GerenciadorEstados* GerenciadorEstados::instancia = nullptr;

GerenciadorEstados::GerenciadorEstados() : pilhaEstados() {}

GerenciadorEstados::~GerenciadorEstados() { delete instancia; }

GerenciadorEstados* GerenciadorEstados::getInstancia() {
  if (!instancia) {
    instancia = new GerenciadorEstados();
  }
  return instancia;
}

States::State* GerenciadorEstados::topEstado() { return pilhaEstados.top(); }

void GerenciadorEstados::executar() {
  if (!pilhaEstados.empty()) {
    topEstado()->executar();
  } else {
    std::cerr << "Pilha vazia!\n";
  }
}

void GerenciadorEstados::pushEstado(States::State* s) {
  if (s)
    pilhaEstados.push(s);
  else {
    std::cerr << "Ponteiro nulo em GerenciadorEstados::pushEstado\n";
    exit(EXIT_FAILURE);
  }
}

void GerenciadorEstados::popEstado() {
  delete topEstado();
  pilhaEstados.pop();
}

}  // namespace Gerenciadores
