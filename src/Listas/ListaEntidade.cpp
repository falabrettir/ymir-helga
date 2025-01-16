#include "Listas/ListaEntidades.h"

namespace Listas {
ListaEntidades::ListaEntidades() : LEs() {}
ListaEntidades::~ListaEntidades() { LEs.limpar(); }
void ListaEntidades::incluir(Entidades::Entidade *pE) { LEs.incluir(pE); }
void ListaEntidades::deletar(Entidades::Entidade *pE) { LEs.remover(pE); }
const int ListaEntidades::getSize() const { return LEs.getSize(); }
void ListaEntidades::limpar() { LEs.limpar(); }
Lista<Entidades::Entidade>::Iterator ListaEntidades::begin() const {
  return LEs.begin();
}
Lista<Entidades::Entidade>::Iterator ListaEntidades::end() const {
  return LEs.end();
}

} // namespace Listas
