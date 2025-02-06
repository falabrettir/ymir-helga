#pragma once
#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Jogador.h"
namespace Entidades {
namespace Obstaculos {
class Obstaculo : public Entidade {
 protected:
  bool danoso;
  Personagens::Jogador *pJog;

 public:
  Obstaculo(ID id, const sf::Vector2f &pos, const bool danoso = false);
  virtual ~Obstaculo();

  virtual void executar() = 0;
  virtual void obstacular(Entidade *pEnt) = 0;
  void colidir(Entidade *pEnt = nullptr);
  const bool ehDanoso() const;
};
}  // namespace Obstaculos
}  // namespace Entidades
