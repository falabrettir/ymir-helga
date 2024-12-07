#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Window/Event.hpp>

using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico()
    : textureMap(), janela(sf::VideoMode(800, 600), "Simon says") {
  janela.setVerticalSyncEnabled(true); // VSYNC
  janela.setFramerateLimit(30); // call it once, after creating the window
  janela.requestFocus();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

void Gerenciador_Grafico::display() { janela.display(); }

bool Gerenciador_Grafico::estaAberta() { return janela.isOpen(); }

bool Gerenciador_Grafico::pollEvent(sf::Event &evento) {
  return janela.pollEvent(evento);
}
