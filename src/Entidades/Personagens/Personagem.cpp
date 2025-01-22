#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace Entidades::Personagens;

Personagem::Personagem()
    : Entidade(), hp(100), numVidas(3), olhandoEsquerda(false) {}

Personagem::~Personagem() {}

void Personagem::mover() {
  sf::Vector2f novaPos = getPos() + (velocidade * pGG->getDeltaTempo());
  setPos(novaPos);
  pSprite->setPosition(novaPos);
}

void Personagem::setOlhandoEsquerda(bool olhandoEsquerda) {
  this->olhandoEsquerda = olhandoEsquerda;
}

void Personagem::inverteSprite() {
  sf::IntRect rect = getSprite().getTextureRect(); // left, top, width, height
  std::cerr << "CHAMEI A FUNCAO" << '\n';
  if (this->getVel().x < 0) {
    rect.left = rect.width;
    rect.width *= -1;
  } else {
    if (rect.width < 0) {
      rect.width *= -1;
      rect.left -= rect.width;
    }
  }
  getSprite().setTextureRect(rect);
}
