#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;

Personagens::Personagem::Personagem() {}

Personagens::Personagem::Personagem(sf::Vector2<float> pos,
                                    sf::Vector2<float> tamanho,
                                    const std::string &path)
    : Entidade::Entidade(pos, tamanho, path), hp(0), numVidas(2) {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover(sf::Vector2<float> mov) {
  sf::Vector2<float> novaPos = this->getPos();
  novaPos.x += mov.x * pGG->getDeltaTempo();
  novaPos.y += mov.y * pGG->getDeltaTempo();
  this->setPos(novaPos);
  pSprite->setPosition(novaPos);
}

void Personagens::Personagem::salvarDataBuffer() {}
