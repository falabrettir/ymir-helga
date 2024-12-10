#include "Entidades/Personagens/Personagem.h"
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
  std::clog << "Personagem se movendo.\n";
  std::clog << "Posicao atual: (" << pos.x << " " << pos.y << ")\n";
  std::clog << "Velocidade atual: (" << velocidade.x << " " << velocidade.y
            << ")" << std::endl;
  sf::Vector2<float> novaPos = getPos() + velocidade * pGG->getDeltaTempo();
  novaPos.y += gravidade;

  if (novaPos.y > alturaJanela - tamanho.y) {
    std::clog << "Atingi o piso" << std::endl;
    novaPos.y = alturaJanela - tamanho.y;
  }

  this->setPos(novaPos);
  pSprite->setPosition(novaPos);
}

void Personagens::Personagem::salvarDataBuffer() {}
