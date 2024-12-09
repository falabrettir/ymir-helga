#pragma once

#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/RectangleShape.hpp>

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
  Jogador(const std::string &path);
  ~Jogador();

  void calculaPontos();
  void salvarDataBuffer();
  void executar();
};

} // namespace Personagens

} // namespace Entidades
