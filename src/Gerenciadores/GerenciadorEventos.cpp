#include "Gerenciadores/GerenciadorEventos.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

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
void Gerenciador_Eventos::processaInput(Entidades::Personagens::Jogador *pJog) {
  // Initialize movement vector to zero
  sf::Vector2<float> mov(0.0f, 0.0f);
  bool moveu = 0;
  // Handle movement input
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    mov.y -= pJog->getVel().y; // Move up
    moveu = 1;
    std::cout << "Pra cima  " << mov.y << std::endl;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    mov.y += pJog->getVel().y; // Move down
    moveu = 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    mov.x -= pJog->getVel().x; // Move left
    moveu = 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    mov.x += pJog->getVel().x; // Move right
    moveu = 1;
  }

  // Move the player using the calculated movement vector
  if (moveu) {
    pJog->mover(mov);
  }
}
