#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;

Personagens::Personagem::Personagem() : Entidade() {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover() {
  pos += velocidade * pGG->getDeltaTempo();
  pSprite->setPosition(pos);
}
