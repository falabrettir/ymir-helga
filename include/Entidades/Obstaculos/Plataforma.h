#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Obstaculo.h"

namespace Entidades::Obstaculos {

class Plataforma : public Obstaculo {
private:
  sf::Vector2f empuxo;

public:
  Plataforma(ID id, const sf::Vector2f &pos);
  ~Plataforma();
  void executar();
  void colidir(Entidade *pEnt = nullptr);
  void obstacular(Entidades::Entidade *pEnt);
};

} // namespace Entidades::Obstaculos
