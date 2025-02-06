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

  void colidir(Entidade* pEnt = nullptr);
};

}  // namespace Entidades::Personagens::Inimigos
