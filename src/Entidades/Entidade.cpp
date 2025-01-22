#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Entidade::Entidade(int id)
    : Ente(id), pos(0, 0), velocidade(0, 0), gravidade(0, 0.1), tamanho(0, 0),
      noChao(false), buffer(nullptr){};

Entidade::~Entidade() { buffer = nullptr; }

void Entidade::setPos(sf::Vector2f novaPos) { pos = novaPos; }

void Entidade::setVel(sf::Vector2f novaVel) { velocidade = novaVel; }

void Entidade::setVelX(float velX) { velocidade.x = velX; }

void Entidade::setVelY(float velY) { velocidade.y = velY; }

void Entidade::setNoChao(bool noChao) { this->noChao = noChao; }

sf::Vector2f Entidade::getPos() const { return pos; }

sf::Vector2f Entidade::getVel() const { return velocidade; }

bool Entidade::getNoChao() const { return noChao; }

sf::Vector2<float> Entidade::getSize() const {
  return static_cast<sf::Vector2f>(pTexture->getSize());
}

void Entidade::cair() { setVel(getVel() + gravidade); }
void Entidade::setHitbox(sf::FloatRect &hitbox) { this->hitbox = hitbox; }
sf::FloatRect Entidade::getHitbox() const {
  return pSprite->getTransform().transformRect(hitbox);
}
