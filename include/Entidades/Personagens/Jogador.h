#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens {

class Jogador : public Personagem {
protected:
  int pontos;
  int inimMortos;
  int tesouro;
  int dano;
  bool pudePular;

public:
  Jogador();
  ~Jogador();

  void calculaPontos();
  void mover();
  void pular();
  virtual void atacar() = 0;
  virtual void executar() = 0;
};

} // namespace Entidades::Personagens
