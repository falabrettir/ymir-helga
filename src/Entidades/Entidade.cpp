#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Entidade::Entidade() : Ente(), gravidade(0, 2), velocidade(0, 0) {};

Entidade::~Entidade() {}

sf::Vector2f Entidade::getPos() const { return pos; }

void Entidade::setPos(sf::Vector2f &novaPos) { pos = novaPos; }

sf::Vector2f Entidade::getVel() const { return velocidade; }

void Entidade::setVel(sf::Vector2f &novaVel) {
  velocidade = novaVel + gravidade;
}
