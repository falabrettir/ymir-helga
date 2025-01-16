#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {
namespace Obstaculos {
Obstaculo::Obstaculo(const bool danoso)
    : Entidade(), pJog(nullptr), danoso(danoso) {}
Obstaculo::~Obstaculo() {
  pJog = nullptr;
  delete pJog;
}
const bool Obstaculo::ehDanoso() const { return danoso; }
void Obstaculo::colidirObst(Entidades::Personagens::Personagem *pPers,
                            sf::Vector2f ds) {
  sf::Vector2f posPers = pPers->getPos();
  sf::Vector2f tamPers = pPers->getSize();
  sf::Vector2f velPers = pPers->getVel();
  if (ds.x < 0.f && ds.y < 0.f) { // colidiu
    if (ds.x > ds.y) {
      if (posPers.x < this->getPos().x) {
        posPers.x += ds.x;
      } else {
        posPers.x -= ds.x;
      }
      velPers.x = 0.0f;
    } else {
      if (posPers.y < this->getPos().y) {
        posPers.y += ds.y;
        // TODO:
        // cozinhar algum jeito de tratar jogadores e inimigos de modo diferente
        if () {
        }
      }
    }
  }
}
} // namespace Obstaculos
} // namespace Entidades
