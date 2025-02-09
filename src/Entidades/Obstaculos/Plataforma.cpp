#include "Entidades/Obstaculos/Plataforma.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades::Obstaculos {

Plataforma::Plataforma(ID id, const sf::Vector2f& pos)
    : Obstaculo(id, pos), empuxo(0.f, 0.f) {
  switch (id) {
    case (ID::IDparede):

    case (ID::IDmadeira1):
      setTextura("/assets/Obstaculos/plataformafase1.png");
      break;

    case (ID::IDmadeira2):
      setTextura("/assets/Obstaculos/plataformafase2.png");
      break;

    case (ID::IDpedra):
      setTextura("/assets/Obstaculos/chaofase1.png");
      break;

    case (ID::IDgrama):
      setTextura("/assets/Obstaculos/chaofase2.png");
      break;

    default:
      break;
  }

  if (ehPlataforma(id)) {
    setTamanho({128 * 3, 16 * 3});
  } else {
    setTamanho({16, 1080});
  }
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
  if (pGC == nullptr) {
    std::cerr << "erro: Plataforma::executar() => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  pGC->notificar(this);

  // TODO: apagar
  sf::RectangleShape debugShape(tamanho);
  debugShape.setPosition(pSprite->getPosition());
  debugShape.setFillColor(sf::Color::Transparent);
  debugShape.setOutlineColor(sf::Color::Blue);
  debugShape.setOutlineThickness(1);
  pGG->getJanela()->draw(debugShape);
}

void Plataforma::obstacular(Entidades::Entidade* pEnt) {
  if (pEnt == nullptr) {
    std::cerr << "erro: Plataforma::obstacular() => pEnt == nullptr"
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (pGC == nullptr) {
    std::cerr << "erro: Plataforma::obstacular() => pGC == nullptr"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  sf::Vector2f novaPos = pEnt->getPos();
  sf::Vector2f ds = pGC->calcOverlap(pEnt, this);

  if (ds.x < ds.y) {                          // Eixo da colisão
    if (pEnt->getPos().x < this->getPos().x)  // Direção da colisao
      novaPos.x -= ds.x;                      // Colisão Esquerda => Direita
    else
      novaPos.x += ds.x;  // Colisao Direita => Esquerda
    pEnt->setVelX(0.f);
  }
  if (ds.y < ds.x) {                            // Eixo da colisão
    if (pEnt->getPos().y < this->getPos().y) {  // Direção da colisão
      novaPos.y -= ds.y;                        // Caindo
      pEnt->setNoChao(true);
    } else
      novaPos.y += ds.y;
    pEnt->setVelY(0.f);
  }
  pEnt->setPos(novaPos);
}
void Plataforma::colidir(Entidade* pEnt) {
  if (pEnt == nullptr) {
    std::cerr << "erro: Plataforma::colidir() => pEnt == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  obstacular(pEnt);
}

}  // namespace Entidades::Obstaculos
