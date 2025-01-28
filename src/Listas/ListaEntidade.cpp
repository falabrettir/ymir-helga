#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"

namespace Listas {

ListaEntidades::ListaEntidades() : LEs() {}

ListaEntidades::~ListaEntidades() { limpar(); }

void ListaEntidades::incluir(Entidades::Entidade *e) { LEs.incluir(e); }

void ListaEntidades::deletar(Entidades::Entidade *e) { LEs.remover(e); }

const int ListaEntidades::getSize() const { return LEs.getSize(); }

void ListaEntidades::limpar() { LEs.limpar(); }

const Listas::Lista<Entidades::Entidade *>::Iterator
ListaEntidades::begin() const {
  return this->begin();
}

const Listas::Lista<Entidades::Entidade *>::Iterator
ListaEntidades::end() const {
  return this->end();
}

void ListaEntidades::executar() {
  Entidades::Entidade *aux = nullptr;
  for (int i = 0; i < LEs.getSize(); i++) {
    aux = LEs.operator[](i);
    aux->executar();
    aux->desenhar();
  }
}

} // namespace Listas
