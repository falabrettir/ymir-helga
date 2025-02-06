#include "Entidades/Entidade.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades {

Gerenciadores::GerenciadorColisoes* Entidade::pGC(
    Gerenciadores::GerenciadorColisoes::getInstancia());

Entidade::Entidade(ID id)
    : Ente(id),
      pos(0, 0),
      velocidade(0, 0),
      gravidade(0, 0.08),
      noChao(false),
      olhandoEsquerda(false),
      buffer(nullptr) {
  if (ehPlataforma(id)) {
    sf::FloatRect hitbox(0.f, 0.f, 3 * 128.f, 3 * 16.f);
    setHitbox(hitbox);
  } else {
    sf::FloatRect hitbox(0, 0, 3 * 16.f, 3 * 16.f);
    setHitbox(hitbox);
  }
};

Entidade::~Entidade() { buffer = nullptr; }

void Entidade::mover() {
  if (velocidade.x > 0) {
    atualizaOrientacao();
    setOlhandoEsquerda(false);
  } else if (velocidade.x < 0) {
    atualizaOrientacao();
    setOlhandoEsquerda(true);
  }
  sf::Vector2f novaPos = getPos() + (velocidade * pGG->getDeltaTempo());
  setPos(novaPos);
}

void Entidade::setOlhandoEsquerda(bool olhandoEsquerda) {
  this->olhandoEsquerda = olhandoEsquerda;
}

void Entidade::atualizaOrientacao() {
  if (olhandoEsquerda) {
    pSprite->setScale(-3.f, 3.f);
    pSprite->setOrigin(pSprite->getLocalBounds().width, 0);
  } else {
    pSprite->setScale(3.f, 3.f);
    pSprite->setOrigin(0, 0);
  }
}

bool Entidade::getOlhandoEsquerda() { return olhandoEsquerda; }

void Entidade::setPos(sf::Vector2f novaPos) {
  pos = novaPos;
  pSprite->setPosition(novaPos);
}

void Entidade::setVel(sf::Vector2f novaVel) { velocidade = novaVel; }

void Entidade::setVelX(float velX) { velocidade.x = velX; }

void Entidade::setVelY(float velY) { velocidade.y = velY; }

void Entidade::setNoChao(bool noChao) { this->noChao = noChao; }

sf::Vector2f Entidade::getPos() const { return pos; }

sf::Vector2f Entidade::getVel() const { return velocidade; }

bool Entidade::getNoChao() const { return noChao; }

sf::Vector2f Entidade::getTamanho() const { return tamanho; }

void Entidade::cair() { setVel(getVel() + gravidade); }

void Entidade::setHitbox(sf::FloatRect& hitbox) { this->hitbox = hitbox; }

sf::FloatRect Entidade::getHitbox() const { return hitbox; }

void Entidade::desenhar() {
  if (pGG) {
    pGG->desenharEnte(this);
  } else {
    std::cerr << "erro: Entidade::desenhar() => pGG == nullptr";
    exit(EXIT_FAILURE);
  }
}
}  // namespace Entidades
