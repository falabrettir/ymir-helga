#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Fases/Caverna.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Jogo {
 private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;
  Gerenciadores::Gerenciador_Input *pGI;
  Fases::Caverna caverna;

 public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
