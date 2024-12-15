#pragma once

#include "Listas/Elemento.h"

namespace Listas {

template <typename TL> class Lista {
private:
  Elemento<TL> *pPrimeiro;
  Elemento<TL> *pUltimo;

public:
  Lista();
  ~Lista();

  void incluir(TL *p);
  void limpar();
};

} // namespace Listas
