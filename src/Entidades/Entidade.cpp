#include "Entidades/Entidade.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades {

Gerenciadores::GerenciadorColisoes *
    Entidade::pGC(Gerenciadores::GerenciadorColisoes::getInstancia());

Entidade::Entidade(ID id)
    : Ente(id), pos(0, 0), velocidade(0, 0), gravidade(0, 0.002), noChao(false),
      olhandoEsquerda(false) {};

Entidade::~Entidade() { std::clog << "~Entidade" << std::endl; }

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

void Entidade::atualizaOrientacao() {
  if (olhandoEsquerda) {
    pSprite->setScale(-3.f, 3.f);
    pSprite->setOrigin(pSprite->getLocalBounds().width, 0);
  } else {
    pSprite->setScale(3.f, 3.f);
    pSprite->setOrigin(0, 0);
  }
}

void Entidade::cair() { setVel(getVel() + gravidade * pGG->getDeltaTempo()); }

void Entidade::desenhar() {
  if (pGG) {
    pGG->desenharEnte(this);
  } else {
    std::cerr << "erro: Entidade::desenhar() => pGG == nullptr";
    exit(EXIT_FAILURE);
  }
}

// ============================================================================
// Getters e setters
// ============================================================================

void Entidade::setVel(const sf::Vector2f &novaVel) { velocidade = novaVel; }

void Entidade::setVelX(const float &velX) { velocidade.x = velX; }

void Entidade::setVelY(const float &velY) { velocidade.y = velY; }

void Entidade::setPos(const sf::Vector2f &novaPos) {
  pos = novaPos;
  pSprite->setPosition(novaPos);
}

void Entidade::setPosX(const float &x) {
  pos.x = x;
  pSprite->setPosition(x, pos.y);
}

void Entidade::setPosY(const float &y) {
  pos.y = y;
  pSprite->setPosition(pos.x, y);
}

void Entidade::setOlhandoEsquerda(const bool &olhandoEsquerda) {
  this->olhandoEsquerda = olhandoEsquerda;
}

void Entidade::setNoChao(const bool &noChao) { this->noChao = noChao; }

sf::Vector2f Entidade::getPos() const { return pos; }

sf::Vector2f Entidade::getVel() const { return velocidade; }

bool Entidade::getNoChao() const { return noChao; }

bool Entidade::getOlhandoEsquerda() const { return olhandoEsquerda; }

sf::Vector2f Entidade::getTamanho() const { return tamanho; }

void Entidade::setTamanho(const sf::Vector2f tam) { tamanho = tam; }

} // namespace Entidades
