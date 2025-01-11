#include "Gerenciadores/GerenciadorGrafico.h"
#include "Ente.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

namespace Gerenciadores {

Gerenciador_Grafico *Gerenciador_Grafico::instancia = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico() : deltaTempo(0.f) {
  pJanela = new sf::RenderWindow(sf::VideoMode(800, 600), "Simon says");
  pJanela->setVerticalSyncEnabled(true);
  pJanela->setFramerateLimit(30);
  pJanela->requestFocus();

  larguraJanela = pJanela->getSize().x;
  alturaJanela = pJanela->getSize().y;

  relogio.restart();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
  pJanela = nullptr;
  instancia = nullptr;
}

Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Grafico();
  }
  return instancia;
}

bool Gerenciador_Grafico::janelaAberta() { return pJanela->isOpen(); }

void Gerenciador_Grafico::display() { pJanela->display(); }

void Gerenciador_Grafico::clear() { pJanela->clear(); }

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  std::clog << "desenharEnte" << std::endl;
  if (pJanela && pE) {
    pJanela->draw(*pE->getSprite());
  } else {
    std::clog << "Nullptr em desenharEnte" << std::endl;
  }
}

void Gerenciador_Grafico::fecharJanela() {
  pJanela->close();
  pJanela = nullptr;
}

sf::RenderWindow *Gerenciador_Grafico::getJanela() const {
  if (pJanela) {
    return pJanela;
  }
  return nullptr;
}

void Gerenciador_Grafico::atualizaDeltaTempo() {
  deltaTempo = relogio.restart().asSeconds();
}

const float Gerenciador_Grafico::getDeltaTempo() const { return deltaTempo; }

const float Gerenciador_Grafico::getLarguraJanela() const {
  return larguraJanela;
}
const float Gerenciador_Grafico::getAlturaJanela() const {
  return alturaJanela;
}
} // namespace Gerenciadores
