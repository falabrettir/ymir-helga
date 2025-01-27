#include "Entidades/Obstaculos/Plataforma.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Entidades::Obstaculos {

// TODO: Refatorar (atributo altura)
Plataforma::Plataforma(ID id, const sf::Vector2f &pos)
    : Obstaculo(id, pos), altura(540.f), empuxo(0.f, 0.f) {
  switch (id) {
    case (ID::IDmadeira1):
      setTextura("");  // TODO: Adicionar caminho para sprite madeira1
      ehFlutuante = true;
      break;

    case (ID::IDmadeira2):
      setTextura("");  // TODO: Adicionar caminho para sprite madeira2
      ehFlutuante = true;
      break;

    case (ID::IDpedra):
      setTextura("");  // TODO:: Adicionar caminho para sprite pedra
      ehFlutuante = false;
      break;

    case (ID::IDgrama):
      setTextura("");  // TODO:: Adicionar caminho para sprite grama
      ehFlutuante = false;
      break;

    default:
      break;
  }

  sf::FloatRect hitbox({0.f, 0.f, 171.f, 18.f});
  pSprite->setTextureRect({2, 11, 171, 18});
  setHitbox(hitbox);
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
