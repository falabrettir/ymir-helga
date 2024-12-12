#include "../include/Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Inimigos::Inimigo::Inimigo() {}
Personagens::Inimigos::Inimigo::Inimigo(sf::Vector2<float> pos,
                                        sf::Vector2<float> tamanho,
                                        const std::string &path)
    : Entidades::Personagens::Personagem(pos, tamanho, path) {}
Personagens::Inimigos::Inimigo::~Inimigo() {}
void Personagens::Inimigos::Inimigo::salvarDataBuffer() {}
