#include "Entidades/Entidade.h"
#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"

namespace Listas {

ListaEntidades::ListaEntidades() : LEs() {}

ListaEntidades::~ListaEntidades() { limpar(); }

void ListaEntidades::incluir(Entidades::Entidade *e) {
  if (e != nullptr) LEs.incluir(e);
}

void ListaEntidades::deletar(Entidades::Entidade *e) {
  if (e != nullptr) LEs.remover(e);
}

const int ListaEntidades::getSize() const { return LEs.getSize(); }

void ListaEntidades::limpar() { LEs.limpar(); }

Listas::Lista<Entidades::Entidade>::Iterator ListaEntidades::begin() {
  return LEs.begin();
}
Listas::Lista<Entidades::Entidade>::Iterator ListaEntidades::end() {
  return LEs.end();
}

void ListaEntidades::executar() {
  Entidades::Entidade *aux = nullptr;
  for (int i = 0; i < LEs.getSize(); i++) {
    aux = LEs.operator[](i);
    aux->executar();
    aux->desenhar();
  }
}

}  // namespace Listas
