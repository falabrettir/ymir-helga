#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"

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
  void mover(bool esquerda);
  void pular();
  virtual void atacar() = 0;
  virtual void executar() = 0;
};

} // namespace Entidades::Personagens
