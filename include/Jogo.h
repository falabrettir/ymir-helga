#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Gerenciadores/GerenciadorEstados.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Jogo {
 private:
  Gerenciadores::GerenciadorGrafico *pGG;
  Gerenciadores::GerenciadorEventos *pGE;
  Gerenciadores::GerenciadorInput *pGI;
  Gerenciadores::GerenciadorEstados *pGS;

 public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
