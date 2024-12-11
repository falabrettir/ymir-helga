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

void Personagens::Personagem::mover(sf::Vector2<float> mov) {
  sf::Vector2<float> novaPos = this->getPos();
  novaPos.x += mov.x;
  novaPos.y += mov.y;
  this->setPos(novaPos);
  pSprite->setPosition(novaPos);
  std::cout << mov.x << " " << mov.y << std::endl;
  std::cout << novaPos.x << " " << novaPos.y << std::endl;
}

void Personagens::Personagem::salvarDataBuffer() {}
