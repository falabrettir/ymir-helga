#pragma once

#include <SFML/System/Vector2.hpp>

#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {

class Slime : public Inimigo {
 private:
  double viscosidade;

 public:
  Slime(const sf::Vector2f& pos);
  ~Slime();

  void executar();
  void atacar();

  void colidir(Entidade* pEnt, sf::Vector2f ds = {0, 0});
};

}  // namespace Entidades::Personagens::Inimigos
