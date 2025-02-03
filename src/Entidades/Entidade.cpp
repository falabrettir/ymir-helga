#include "Entidades/Entidade.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades {

Gerenciadores::GerenciadorColisoes* Entidade::pGC(nullptr);

Entidade::Entidade(ID id)
    : Ente(id),
      pos(0, 0),
      velocidade(0, 0),
      gravidade(0, 0.1),
      tamanho(0, 0),
      noChao(false),
      olhandoEsquerda(false),
      buffer(nullptr) {
  if (pGC == nullptr) pGC = Gerenciadores::GerenciadorColisoes::getInstancia();

  if (ehPlataforma(id)) {
    sf::FloatRect hitbox(0.f, 0.f, 128.f, 16.f);
    setHitbox(hitbox);

  } else {
    sf::FloatRect hitbox(16.f, 16.f, 16.f, 16.f);
    setHitbox(hitbox);
  }
};

Entidade::~Entidade() { buffer = nullptr; }

void Entidade::mover() {
  if (velocidade.x >= 0) {
    atualizaOrientacao();
    setOlhandoEsquerda(false);
  } else {
    atualizaOrientacao();
    setOlhandoEsquerda(true);
  }
  sf::Vector2f novaPos = getPos() + (velocidade * pGG->getDeltaTempo());
  setPos(novaPos);
  pSprite->setPosition(novaPos);
}

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

void Entidade::setHitbox(sf::FloatRect& hitbox) { this->hitbox = hitbox; }

sf::FloatRect Entidade::getHitbox() const {
  return pSprite->getTransform().transformRect(hitbox);
}

}  // namespace Entidades
