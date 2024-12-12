#pragma once
#include "Jogador.h"

namespace Inimigos {

class Inimigo {
protected:
  int nivelMadade;

public:
  Inimigo();
  virtual ~Inimigo();

  void salvarDataBuffer();
  virtual void executar() = 0;
  virtual void danificar(Entidades::Personagens::Jogador *pJog) = 0;
};

} // namespace Inimigos
