#include "Entidades/Obstaculos/Obstaculo.h"

#include <SFML/System/Vector2.hpp>

namespace Entidades {
namespace Obstaculos {

Obstaculo::Obstaculo(ID id, const sf::Vector2f &pos, const bool danoso)
    : Entidade(id), pJog(nullptr), danoso(danoso) {
  setPos(pos);
}

Obstaculo::~Obstaculo() {
  pJog = nullptr;
  delete pJog;
}

const bool Obstaculo::ehDanoso() const { return danoso; }

}  // namespace Obstaculos
}  // namespace Entidades
