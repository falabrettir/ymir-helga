#include "Listas/ListaEntidades.h"
#include <iostream>
namespace Listas {
ListaEntidades::ListaEntidades() : LEs() {}
ListaEntidades::~ListaEntidades() { limpar(); }
void ListaEntidades::incluir(Entidades::Entidade *e) {
  bool a = LEs.incluir(e);
  if (!a) {
    std::cout << "Erro na inserção da entidade!" << std::endl;
  }
}
void ListaEntidades::deletar(Entidades::Entidade *e) { LEs.remover(e); }
const int ListaEntidades::getSize() const { return LEs.getSize(); }
void ListaEntidades::limpar() { LEs.limpar(); }
} // namespace Listas
