#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;

Personagens::Personagem::Personagem() : Entidade() {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover(sf::Vector2<float> mov) {
  sf::Vector2<float> novaPos = this->getPos();
  novaPos += mov * pGG->getDeltaTempo();
  this->setPos(novaPos);
  pSprite->setPosition(novaPos);
}
