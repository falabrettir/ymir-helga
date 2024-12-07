#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Window/Event.hpp>

using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(800, 600), "SFML window") {}

void Gerenciador_Grafico::display() { janela.display(); }

bool Gerenciador_Grafico::estaAberta() { return janela.isOpen(); }

bool Gerenciador_Grafico::pollEvent() {
  return janela.pollEvent(sf::Event event);
}
