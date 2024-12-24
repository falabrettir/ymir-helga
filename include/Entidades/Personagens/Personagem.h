#pragma once

#include "Entidades/Entidade.h"

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;
  int numVidas;

public:
  Personagem();
  virtual ~Personagem();

  virtual void mover();
  virtual void executar() = 0;
};

} // namespace Personagens

} // namespace Entidades
