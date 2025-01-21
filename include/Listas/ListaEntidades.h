#pragma once

#include "Entidades/Entidade.h"
#include "Listas/Lista.h"

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

  const Listas::Lista<Entidades::Entidade *>::Iterator begin() const;
  const Listas::Lista<Entidades::Entidade *>::Iterator end() const;

  void percorrer();
};

} // namespace Listas
