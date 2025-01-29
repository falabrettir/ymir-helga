#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Fases/Caverna.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Jogo {
 private:
  Gerenciadores::GerenciadorGrafico *pGG;
  Gerenciadores::GerenciadorEventos *pGE;
  Gerenciadores::GerenciadorInput *pGI;
  Gerenciadores::GerenciadorEstados *pGS;
  Fases::Caverna *caverna;

 public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
