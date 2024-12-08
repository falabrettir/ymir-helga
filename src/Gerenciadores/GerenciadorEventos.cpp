#include "Gerenciadores/Gerenciador-eventos.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

using namespace Gerenciadores;

Gerenciador_Eventos *Gerenciador_Eventos::instancia = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos() : evento() {}

Gerenciador_Eventos *Gerenciador_Eventos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Eventos();
  }
  return instancia; // Singleton
}

Gerenciador_Eventos::~Gerenciador_Eventos() {}

sf::Event &Gerenciador_Eventos::getEvento() { return evento; }
