#pragma once

#include "Entidades/Obstaculos/Plataforma.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Color.hpp>

class Jogo {
private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;
  Gerenciadores::Gerenciador_Input *pGI;
  Gerenciadores::Gerenciador_Colisoes *pGC;
  Entidades::Personagens::Jogador *pJog1;
  Entidades::Personagens::Jogador *pJog2;
  Entidades::Obstaculos::Plataforma *pPlataforma;

public:
  Jogo();
  ~Jogo();
  void atualizar();
  void executar();
};
