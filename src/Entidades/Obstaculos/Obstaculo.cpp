#include "Entidades/Obstaculos/Obstaculo.h"

#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades {
namespace Obstaculos {

Obstaculo::Obstaculo(ID id, const sf::Vector2f &pos, const bool danoso)
    : Entidade(id), pJog(nullptr), danoso(danoso) {
  pGC->incluirObst(this);
  setPos(pos);
}

Obstaculo::~Obstaculo() {
  pJog = nullptr;
  delete pJog;
}

const bool Obstaculo::ehDanoso() const { return danoso; }

}  // namespace Obstaculos
}  // namespace Entidades
