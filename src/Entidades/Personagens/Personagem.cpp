#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;

Personagens::Personagem::Personagem() : Entidade() {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover(bool left) {
  pos += velocidade * pGG->getDeltaTempo();
  pSprite->setPosition(pos);
}
