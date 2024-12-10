#pragma once

#include "Entidades/Personagens/Personagem.h"

namespace Entidades {

namespace Personagens {

class Jogador : public Entidades::Personagens::Personagem {
private:
  int pontos;
  int inimMortos;
  int tesouro;
  int stamina;
  int dano;

public:
  Jogador();
  Jogador(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
          const std::string &path);
  ~Jogador();

  void calculaPontos();
  void salvarDataBuffer();
  void executar();
  void salvar();
};

} // namespace Personagens

} // namespace Entidades
