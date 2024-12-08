#pragma once

#include "Entidades/Entidade.h"
#include "Listas/Lista.h"

namespace Listas {

class ListaEntidades {
private:
  Lista<Entidade> LEs;

public:
  ListaEntidades();
  ~ListaEntidades();

  void incluir(Entidade *pE);
  void percorrer();
};

} // namespace Listas
