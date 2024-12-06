#pragma once
#include "../include/gerenciador-grafico.h"

class Jogo {
private:
  bool rodando;

public:
  Jogo();
  ~Jogo();
  void executar();
  bool estaRodando() const;
};
