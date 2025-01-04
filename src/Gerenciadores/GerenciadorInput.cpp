#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/Window/Window.hpp>

using namespace Gerenciadores;

Gerenciador_Input *Gerenciador_Input::instancia = nullptr;

Gerenciador_Input::Gerenciador_Input() {}

Gerenciador_Input::~Gerenciador_Input() {}

Gerenciador_Input *Gerenciador_Input::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Input();
  }
  return instancia;
}

void Gerenciador_Input::setGG(Gerenciador_Grafico *pGG) { this->pGG = pGG; }
