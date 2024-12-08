#pragma once

#include "Gerenciadores/Gerenciador-Eventos.h"
#include "Gerenciadores/Gerenciador-Grafico.h"
class Jogo {
private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;

public:
  Jogo();
  ~Jogo();
  void executar();
};
