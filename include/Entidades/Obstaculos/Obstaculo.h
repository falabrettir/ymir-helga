#pragma once
#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"

namespace Entidades::Obstaculos {

class Obstaculo : public Entidade {
 protected:
  bool danoso;

 public:
  Obstaculo(ID id, const sf::Vector2f& pos, const bool danoso = false);
  virtual ~Obstaculo();

  virtual void executar() = 0;
  virtual void colidir(Entidade* pEnt = nullptr) = 0;
  virtual void obstacular(Entidade* pEnt) = 0;
  const bool ehDanoso() const;
};

}  // namespace Entidades::Obstaculos
