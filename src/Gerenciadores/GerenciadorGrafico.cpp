#include "Gerenciadores/GerenciadorGrafico.h"
#include "Ente.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

using namespace Gerenciadores;

Gerenciador_Grafico *Gerenciador_Grafico::instancia = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico() {
  janela = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode()),
                                "Simon says", sf::Style::Fullscreen);
  janela->setVerticalSyncEnabled(
      true); // VSYNC janela->setFramerateLimit(30); // call it once, after
             // creating the window
  janela->requestFocus();

  larguraJanela = janela->getSize().x;
  alturaJanela = janela->getSize().y;
  std::clog << larguraJanela << " " << alturaJanela << std::endl;

  relogio.restart();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Grafico();
  }
  return instancia; // Singleton
}

bool Gerenciador_Grafico::janelaAberta() { return janela->isOpen(); }

void Gerenciador_Grafico::display() { janela->display(); }

void Gerenciador_Grafico::clear() { janela->clear(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  if (janela && pE) {
    janela->draw(*pE->getSprite());
  }
}

void Gerenciador_Grafico::fecharJanela() { janela->close(); }

sf::RenderWindow *Gerenciador_Grafico::getJanela() const { return janela; }

void Gerenciador_Grafico::atualizaDeltaTempo() {
  deltaTempo = relogio.restart().asMilliseconds();
}

const float Gerenciador_Grafico::getDeltaTempo() const { return deltaTempo; }

const float Gerenciador_Grafico::getLarguraJanela() const {
  return larguraJanela;
}
const float Gerenciador_Grafico::getAlturaJanela() const {
  return alturaJanela;
}
