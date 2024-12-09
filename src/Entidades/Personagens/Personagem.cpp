#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Personagem::Personagem() {}

Personagens::Personagem::Personagem(sf::Vector2<float> pos,
                                    sf::Vector2<float> tamanho,
                                    const std::string &path)
    : Entidade::Entidade(pos, tamanho, path), hp(0), numVidas(2) {}

Personagens::Personagem::~Personagem() {}

void Personagens::Personagem::mover() {
  sf::Vector2<float> novaPos = getPos() + velocidade;
  this->setPos(novaPos);
}

void Personagens::Personagem::salvarDataBuffer() {}
