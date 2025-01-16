#pragma once
#include "Entidades/Personagens/Jogador.h"
#include <SFML/System/Vector2.hpp>
namespace Entidades {
namespace Obstaculos {
class Obstaculo : public Entidade {
protected:
  bool danoso;
  Personagens::Jogador *pJog;

public:
  Obstaculo(const bool danoso = false);
  virtual ~Obstaculo();
  virtual void executar() = 0;
  virtual void obstacular(Entidade *pEnt) = 0;
  virtual void colidir(Entidades::Entidade *pEnt,
                       sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
  const bool ehDanoso() const;
};
} // namespace Obstaculos
} // namespace Entidades
