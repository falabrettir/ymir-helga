#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Personagem::Personagem() : Entidade() {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover() {
  sf::Vector2f novaPos = getPos() + (velocidade * pGG->getDeltaTempo());
  setPos(novaPos);
  pSprite->setPosition(pos);
}
