#include "Entidades/Obstaculos/Plataforma.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades::Obstaculos {

Plataforma::Plataforma(ID id, const sf::Vector2f &pos)
    : Obstaculo(id, pos), empuxo(0.f, 0.f) {
  switch (id) {
    case (ID::IDmadeira1):
      std::clog << "Criando nova plataforma de madeira1\n";
      setTextura("/assets/Obstaculos/plataformafase1.png");
      break;

    case (ID::IDmadeira2):
      std::clog << "Criando nova plataforma de madeira2\n";
      setTextura("/assets/Obstaculos/plataformafase2.png");
      break;

    case (ID::IDpedra):
      std::clog << "Criando nova plataforma de pedra\n";
      setTextura("/assets/Obstaculos/chaofase1.png");
      break;

    case (ID::IDgrama):
      std::clog << "Criando nova plataforma de grama\n";
      setTextura("/assets/Obstaculos/chaofase2.png");
      break;

    default:
      break;
  }

  tamanho = {128 * 3, 16 * 3};
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
  pGC->notificar(this);
  sf::RectangleShape debugShape(tamanho);
  debugShape.setPosition(pSprite->getPosition());
  debugShape.setFillColor(sf::Color::Transparent);
  debugShape.setOutlineColor(sf::Color::Blue);
  debugShape.setOutlineThickness(1);
  pGG->getJanela()->draw(debugShape);
}

void Plataforma::obstacular(Entidades::Entidade *pEnt) {}

void Plataforma::colidir(Entidades::Entidade *pEnt) {}

}  // namespace Entidades::Obstaculos
