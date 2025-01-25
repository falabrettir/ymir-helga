#include "Entidades/Obstaculos/Obstaculo.h"

#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Personagem.h"

namespace Entidades {
namespace Obstaculos {
Obstaculo::Obstaculo(ID id, const bool danoso) : Entidade(id), pJog(nullptr), danoso(danoso) {}
Obstaculo::~Obstaculo() {
  pJog = nullptr;
  delete pJog;
}
const bool Obstaculo::ehDanoso() const { return danoso; }
}  // namespace Obstaculos
}  // namespace Entidades
