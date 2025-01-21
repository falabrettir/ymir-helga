#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

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
  sf::IntRect novo = this->getSprite().getTextureRect();
  novo.width *= -1;
  this->getSprite().setTextureRect(novo);
}
