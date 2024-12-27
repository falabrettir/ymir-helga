#include "Gerenciadores/GerenciadorEventos.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

using namespace Gerenciadores;

Gerenciador_Eventos *Gerenciador_Eventos::instancia = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos() : janelaFechada(true) {}

Gerenciador_Eventos::~Gerenciador_Eventos() {}

Gerenciador_Eventos *Gerenciador_Eventos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Eventos();
  }
  return instancia; // Singleton
}

void Gerenciador_Eventos::processaEventos(sf::Window *pJanela) {
  sf::Event evento;

  while (pJanela->pollEvent(evento)) {
    if (evento.type == sf::Event::Closed) {
      janelaFechada = true;
    }
  }
}

bool Gerenciador_Eventos::getJanelaFechada() { return janelaFechada; }

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
