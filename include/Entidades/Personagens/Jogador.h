#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"

namespace Entidades {

namespace Personagens {

class Jogador : public Entidades::Personagens::Personagem {
private:
  Gerenciadores::Gerenciador_Eventos *pGE;
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
