#include "Entidades/Obstaculos/Plataforma.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Entidades::Obstaculos {

Plataforma::Plataforma(ID id, const bool ehFlut)
    : Obstaculo(id), altura(540.f), ehFlutuante(ehFlut), empuxo(0.f, 0.f) {
  setTexture("/assets/Prataforma.png");

  sf::Vector2f posInicial(400, 900);
  setPos(posInicial);
  pSprite->setPosition(posInicial);
  sf::FloatRect hitbox({0.f, 0.f, 171.f, 18.f});
  pSprite->setTextureRect({2, 11, 171, 18});
  setHitbox(hitbox);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() { std::cout << "Executando obst"; }

void Plataforma::obstacular(Entidades::Entidade *pEnt) { std::cout << "obstaculando"; }

void Plataforma::colidir(Entidades::Entidade *pEnt, sf::Vector2f ds) {
  sf::Vector2f posEntidade = pEnt->getPos();
  sf::Vector2f velEntidade = pEnt->getVel();

  if (ds.x < 0.f && ds.y < 0.f) {  // Colidiu
    if (ds.x > ds.y) {             // Colisao em X
      if (posEntidade.x < this->getPos().x)
        posEntidade.x += ds.x;
      else
        posEntidade.x -= ds.x;
      velEntidade.x = 0.0f;

    } else {                                   // Colisao em Y
      if (posEntidade.y < this->getPos().y) {  // Colidiu por cima
        posEntidade.y += ds.y;
        pEnt->setNoChao(true);
      } else {  // Colidiu por baixo
        posEntidade.y -= ds.y;
      }
      velEntidade.y = 0.0f;
    }
  }

  pEnt->setPos(posEntidade);
  pEnt->setVel(velEntidade);
}

}  // namespace Entidades::Obstaculos
