#include "Gerenciadores/GerenciadorGrafico.h"
#include "Ente.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

using namespace Gerenciadores;

Gerenciador_Grafico *Gerenciador_Grafico::instancia = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico() {
  janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Simon says");
  janela->setVerticalSyncEnabled(
      true); // VSYNC janela->setFramerateLimit(30); // call it once, after
             // creating the window
  janela->requestFocus();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Grafico();
  }
  return instancia; // Singleton
}

void Gerenciador_Grafico::display() { janela->display(); }

bool Gerenciador_Grafico::janelaAberta() { return janela->isOpen(); }

bool Gerenciador_Grafico::pollEvent(sf::Event &evento) {
  return janela->pollEvent(evento);
}

void Gerenciador_Grafico::clear() { janela->clear(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  if (pE) {
    pE->desenhar();
  }
}

void Gerenciador_Grafico::fecharJanela() { janela->close(); }
sf::RenderWindow *Gerenciador_Grafico::getJanela() const { return janela; }
