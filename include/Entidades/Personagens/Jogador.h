#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"

namespace Entidades {

namespace Personagens {

class Jogador : public Entidades::Personagens::Personagem {
protected:
  Gerenciadores::Gerenciador_Eventos *pGE;
  int pontos;
  int inimMortos;
  int tesouro;
  int dano;
  bool pulou;

public:
  Jogador();
  ~Jogador();

  void calculaPontos();
  virtual void mover(bool left);
  void pular();
  virtual void atacar() = 0;
  virtual void executar() = 0;
};

} // namespace Personagens

} // namespace Entidades
