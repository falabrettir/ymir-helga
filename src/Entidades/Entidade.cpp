#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Entidade::Entidade()
    : Ente(), pos(0, 0), velocidade(0, 0), gravidade(0, 1), tamanho(0, 0),
      buffer(nullptr) {};

Entidade::~Entidade() {}

sf::Vector2f Entidade::getPos() const { return pos; }

sf::Vector2f Entidade::getVel() const { return velocidade; }

void Entidade::setPos(sf::Vector2f &novaPos) { pos = novaPos; }

void Entidade::setVel(sf::Vector2f &novaVel) { velocidade = novaVel; }

sf::Vector2<float> Entidade::getSize() const {
  return static_cast<sf::Vector2f>(pTexture->getSize());
}

void Entidade::cair() {
  sf::Vector2f novaVel = getVel() + gravidade;
  setPos();
  setVel(novaVel);
}
