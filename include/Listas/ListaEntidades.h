#pragma once

#include "Listas/Lista.h"
namespace Entidades {
class Entidade;
}
namespace Listas {

class ListaEntidades {
private:
  Lista<Entidades::Entidade> LEs;

public:
  ListaEntidades();
  ~ListaEntidades();

  void incluir(Entidades::Entidade *pE);
  void deletar(Entidades::Entidade *pE);
  const int getSize() const;
  void limpar();
  Listas::Lista<Entidades::Entidade>::Iterator begin();
  Listas::Lista<Entidades::Entidade>::Iterator end();

  void executar();
};

} // namespace Listas
