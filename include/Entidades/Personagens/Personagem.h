#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;
  int numVidas;
  bool olhandoEsquerda;

public:
  Personagem();
  virtual ~Personagem();
  virtual void mover(bool left);
  virtual void executar() = 0;
};

} // namespace Personagens

} // namespace Entidades
