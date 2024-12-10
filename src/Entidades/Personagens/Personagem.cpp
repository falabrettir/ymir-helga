#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace Entidades;

Personagens::Personagem::Personagem() {}

Personagens::Personagem::Personagem(sf::Vector2<float> pos,
                                    sf::Vector2<float> tamanho,
                                    const std::string &path)
    : Entidade::Entidade(pos, tamanho, path), hp(0), numVidas(2) {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover() {
  sf::Vector2<float> novaPos;

  const float deltaT = pGG->getDeltaTempo();

  velocidade.y += gravidade;

  novaPos.x = pos.x + velocidade.x * deltaT;
  novaPos.y = pos.y + velocidade.y * deltaT;

  if (novaPos.y > pGG->getAlturaJanela() - tamanho.y) {
    velocidade.y = 0;
    novaPos.y = pGG->getAlturaJanela() - tamanho.y;
  }

  this->setPos(novaPos);
  pSprite->setPosition(novaPos);
}

void Personagens::Personagem::salvarDataBuffer() {}
