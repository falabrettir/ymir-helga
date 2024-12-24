#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Personagem::Personagem() : Entidade() {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover() {
  sf::Vector2<float> novaPos = getPos() + velocidade;
  this->setPos(novaPos);
}
