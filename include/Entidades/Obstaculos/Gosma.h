#pragma once

#include "Obstaculo.h"

namespace Entidades::Obstaculos {
class Gosma : public Obstaculo {
private:
  float pegajosidade;

public:
  Gosma(const sf::Vector2f &pos);
  ~Gosma();

  const float getPegajosidade() const;

  void executar();
  void obstacular(Entidade *pEnt);
  void colidir(Entidade *pEnt = nullptr);
};
} // namespace Entidades::Obstaculos
