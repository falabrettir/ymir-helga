#pragma once

#include "gerenciadores/gerenciador-eventos.h"
#include "gerenciadores/gerenciador-grafico.h"
class Jogo {
private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;

public:
  Jogo();
  ~Jogo();
  void executar();
};
