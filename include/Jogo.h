#pragma once

#include "Entidades/Personagens/Helga.h"
#include "Entidades/Personagens/Skjolder.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Color.hpp>

class Jogo {
private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;
  Gerenciadores::Gerenciador_Input *pGI;
  Entidades::Personagens::Skjolder *pSkjolder;
  Entidades::Personagens::Helga *pHelga;

public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
