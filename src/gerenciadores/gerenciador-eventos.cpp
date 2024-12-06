#include "gerenciadores/gerenciador-eventos.h"
#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Window/Window.hpp>

using namespace Gerenciadores;

void Gerenciador_Eventos::executar(Gerenciador_Grafico *pGG) {
  sf::Window *pJanela = pGG->getJanela();
  while (pJanela->pollEvent(evento)) {

    // Close window: exit
    if (evento.type == sf::Event::Closed)
      pJanela->close();
  }
}
