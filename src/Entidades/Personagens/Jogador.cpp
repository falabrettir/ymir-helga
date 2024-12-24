#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Jogador::Jogador()
    : Personagens::Personagem(), pontos(0), inimMortos(0), tesouro(0),
      stamina(100), dano(25) {

  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
};

Personagens::Jogador::~Jogador() {}

void Personagens::Jogador::calculaPontos() {}

void Personagens::Jogador::executar() {}
