#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
private:
  int hp;
  int numVidas;
  bool olhandoEsquerda;

public:
  Personagem();
  virtual ~Personagem();

  virtual void mover();

  void setOlhandoEsquerda(bool olhandoEsquerda);
};

} // namespace Personagens

} // namespace Entidades
