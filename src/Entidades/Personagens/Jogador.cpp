#include "Entidades/Personagens/Jogador.h"

using namespace Entidades;

Personagens::Jogador::Jogador() {}

Personagens::Jogador::Jogador(sf::Vector2<float> pos,
                              sf::Vector2<float> tamanho,
                              const std::string &path)
    : Personagens::Personagem(pos, tamanho, path), pontos(0), inimMortos(0),
      tesouro(0), stamina(100), dano(10) {}

Personagens::Jogador::~Jogador() {}

void Personagens::Jogador::calculaPontos() {}

void Personagens::Jogador::salvarDataBuffer() {}

void Personagens::Jogador::executar() {}

void Personagens::Jogador::salvar() {}
