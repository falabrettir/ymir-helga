#pragma once

#include <SFML/System/Vector2.hpp>

#include "Inimigo.h"

namespace Entidades {
namespace Personagens {
namespace Inimigos {
class Slime : public Inimigo {
 private:
  double viscosidade;

 public:
  Slime(ID id, float visada, int dano);
  ~Slime();
  void executar();
  void colidir(Entidade* pEnt, sf::Vector2f ds = {0, 0});
};
}  // namespace Inimigos
}  // namespace Personagens
}  // namespace Entidades
