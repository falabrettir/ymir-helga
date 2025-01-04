#include "Jogo.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  Ente::setGerenciadorGrafico(pGG);
}

Jogo::~Jogo() {}

void Jogo::executar() {}
