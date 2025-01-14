#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Jogador::Jogador()
    : Personagens::Personagem(), pontos(0), inimMortos(0), tesouro(0), dano(25){

                                                                       };

Personagens::Jogador::~Jogador() {}

void Personagens::Jogador::calculaPontos() {}

void Personagens::Jogador::mover() { pSprite->setPosition(pos); }

void Personagens::Jogador::executar() {}
