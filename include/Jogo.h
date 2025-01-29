#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Fases/Caverna.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Jogo {
 private:
  Gerenciadores::GerenciadorGrafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;
  Gerenciadores::Gerenciador_Input *pGI;
  Gerenciadores::Gerenciador_Estados *pGS;
  Fases::Caverna *caverna;

 public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
