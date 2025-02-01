#include "Gerenciadores/GerenciadorEstados.h"

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
  }
}

void GerenciadorEstados::pushEstado(States::State* s) { pilhaEstados.push(s); }

void GerenciadorEstados::popEstado() {
  delete topEstado();
  pilhaEstados.pop();
}

}  // namespace Gerenciadores
