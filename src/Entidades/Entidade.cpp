#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Entidade::Entidade() : Ente() {
  velocidade = sf::Vector2<float>(0.f, 0.f);
  gravidade = sf::Vector2<float>(0.f, 0.f);
}

Entidade::~Entidade() {}

sf::Vector2<float> Entidade::getPos() const { return pos; }

void Entidade::setPos(sf::Vector2<float> &novaPos) { pos = novaPos; }

sf::Vector2<float> Entidade::getVel() const { return velocidade; }

void Entidade::setVel(sf::Vector2<float> &novaVel) { velocidade = novaVel; }
