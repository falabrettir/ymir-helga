#include "Gerenciadores/GerenciadorEventos.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

using namespace Gerenciadores;

Gerenciador_Eventos *Gerenciador_Eventos::instancia = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos() {}

Gerenciador_Eventos::~Gerenciador_Eventos() {}

Gerenciador_Eventos *Gerenciador_Eventos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Eventos();
  }
  return instancia;
}

void Gerenciador_Eventos::processaEventos() {}

void Gerenciador_Eventos::setGG(Gerenciador_Grafico *ppGG) { pGG = ppGG; }
