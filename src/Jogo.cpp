#include "Jogo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();

  Ente::setGerenciadorGrafico(pGG);
  Gerenciadores::Gerenciador_Eventos::setGG(pGG);
  Gerenciadores::Gerenciador_Input::setGG(pGG);
}

Jogo::~Jogo() {}

void Jogo::executar() {}
