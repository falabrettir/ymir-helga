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
  ~Jogador();

  void executar();
  void calculaPontos();
};

} // namespace Personagens

} // namespace Entidades
