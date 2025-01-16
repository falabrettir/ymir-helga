#include "Entidades/Obstaculos/Plataforma.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
namespace Entidades {
namespace Obstaculos {
Plataforma::Plataforma(const bool ehFlut)
    : Obstaculo(), altura(540.f), ehFlutuante(ehFlut), empuxo(0.f, 0.f) {
  setTexture("/assets/Prataforma.png");
  sf::Vector2<float> posIni(400.f, 900.f);
  setPos(posIni);
  pSprite->setPosition(posIni);
  sf::Vector2<float> velIni(0.f, 0.f);
  setVel(velIni);
}
Plataforma::~Plataforma() {}
void Plataforma::executar() { std::cout << "Executando obst"; }
void Plataforma::obstacular(Entidades::Entidade *pEnt) {
  std::cout << "obstaculando";
}
void Plataforma::colidir(Entidades::Entidade *pEnt, sf::Vector2f ds) {
  sf::Vector2f posEnt = pEnt->getPos();
  sf::Vector2f tamEnt = pEnt->getSize();
  sf::Vector2f velEnt = pEnt->getVel();
  if (ds.x < 0.f && ds.y < 0.f) { // colidiu
    if (ds.x > ds.y) {
      if (posEnt.x < this->getPos().x) {
        posEnt.x += ds.x;
      } else {
        posEnt.x -= ds.x;
      }
      velEnt.x = 0.0f;
    } else {
      if (posEnt.y < this->getPos().y) {
        posEnt.y += ds.y;
        pEnt->setNoChao(true);
      } else {
        posEnt.y -= ds.y;
      }
      velEnt.y = 0.0f;
    }
  }
  pEnt->setPos(posEnt);
  pEnt->setVel(velEnt);
}

} // namespace Obstaculos
} // namespace Entidades
