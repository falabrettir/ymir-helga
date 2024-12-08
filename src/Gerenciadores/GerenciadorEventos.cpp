#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

using namespace Gerenciadores;

Gerenciador_Eventos *Gerenciador_Eventos::instancia = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos() : evento() {}

Gerenciador_Eventos::~Gerenciador_Eventos() {}

Gerenciador_Eventos *Gerenciador_Eventos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Eventos();
  }
  return instancia; // Singleton
}

sf::Event &Gerenciador_Eventos::getEvento() { return evento; }

void Gerenciador_Eventos::processaEventos(Gerenciador_Grafico *pGG) {
  while (pGG->pollEvent(getEvento())) {
    if (evento.type == sf::Event::Closed)
      pGG->fecharJanela();
  }
}
