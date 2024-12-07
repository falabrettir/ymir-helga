#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Window/Event.hpp>

using namespace Gerenciadores;

Gerenciador_Grafico *instancia(nullptr);

Gerenciador_Grafico::Gerenciador_Grafico()
    : textureMap(), janela(sf::VideoMode(800, 600), "Simon says") {
  janela.setVerticalSyncEnabled(true); // VSYNC
  janela.setFramerateLimit(30); // call it once, after creating the window
  janela.requestFocus();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

void Gerenciador_Grafico::display() { janela.display(); }

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Grafico();
  }
  return instancia; // Singleton
}

bool Gerenciador_Grafico::janelaAberta() { return janela.isOpen(); }

bool Gerenciador_Grafico::pollEvent(sf::Event &evento) {
  return janela.pollEvent(evento);
}

sf::RenderWindow Gerenciador_Grafico::getJanela() { return this->janela; }

void Gerenciador_Grafico::clear() { janela.clear(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  if (pE->sprite) {
    getJanela().draw(pE->sprite);
  }
}
