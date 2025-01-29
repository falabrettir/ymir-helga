#include "Gerenciadores/GerenciadorEstados.h"
namespace Gerenciadores {
Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

Gerenciador_Estados::Gerenciador_Estados() : pilhaEstados() {}

Gerenciador_Estados::~Gerenciador_Estados() {}

Gerenciador_Estados* Gerenciador_Estados::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Estados();
  }
  return instancia;
}

States::State* Gerenciador_Estados::topEstado() { return pilhaEstados.top(); }

void Gerenciador_Estados::executar() {
  if (!pilhaEstados.empty()) {
    topEstado()->executar();
  }
}

void Gerenciador_Estados::pushEstado(States::State* s) { pilhaEstados.push(s); }

void Gerenciador_Estados::popEstado() {
  delete topEstado();
  pilhaEstados.pop();
}
}  // namespace Gerenciadores
