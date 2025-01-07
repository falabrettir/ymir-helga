#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;
  int numVidas;

public:
  Personagem();
  virtual ~Personagem();

  virtual void mover(sf::Vector2<float> mov);
  virtual void executar() = 0;
};

} // namespace Personagens

} // namespace Entidades
