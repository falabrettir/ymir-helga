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

void Plataforma::obstacular(Entidades::Entidade *pEnt) {
  sf::Vector2f novaPos = pEnt->getPos();
  sf::Vector2f ds = pGC->calcOverlap(pEnt, this);
  if (ds.x < ds.y) {                         // Eixo da colisão
    if (pEnt->getPos().x < this->getPos().x) // Direção da colisao
      novaPos.x -= ds.x;                     // Colisão Esquerda => Direita
    else
      novaPos.x += ds.x; // Colisao Direita => Esquerda
    pEnt->setVelX(0.f);
  }
  if (ds.y < ds.x) {                           // Eixo da colisão
    if (pEnt->getPos().y < this->getPos().y) { // Direção da colisão
      novaPos.y -= ds.y;                       // Caindo
      pEnt->setNoChao(true);
    } else
      novaPos.y += ds.y;
    pEnt->setVelY(0.f);
  }
  pEnt->setPos(novaPos);
}
void Plataforma::colidir(Entidade *pEnt) {
  if (pEnt) {
    obstacular(pEnt);
  }
}

} // namespace Entidades::Obstaculos
