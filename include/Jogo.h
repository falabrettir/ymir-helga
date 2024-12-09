#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Color.hpp>
class Jogo {
private:
  Gerenciadores::Gerenciador_Grafico *pGG;
  Gerenciadores::Gerenciador_Eventos *pGE;
  Entidades::Personagens::Jogador *pJog;

public:
  Jogo();
  ~Jogo();
  void executar();
};
