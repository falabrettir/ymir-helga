#include "Gerenciadores/GerenciadorEventos.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"

namespace Gerenciadores {
Gerenciador_Eventos *Gerenciador_Eventos::instancia = nullptr;

Gerenciador_Eventos::Gerenciador_Eventos()
    : pJanela(nullptr), pGG(nullptr), pGI(nullptr) {}

Gerenciador_Eventos::~Gerenciador_Eventos() {
  pJanela = nullptr;
  pGG = nullptr;
  pGI = nullptr;
}

Gerenciador_Eventos *Gerenciador_Eventos::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Eventos();
  }
  return instancia;
}

void Gerenciador_Eventos::setGG(GerenciadorGrafico *pGG) {
  if (pGG) {
    this->pGG = pGG;
    pJanela = pGG->getJanela();
  } else {
    std::cerr << "erro: em Gerenciador_Eventos::setGG(), pGG == nullptr\n";
  }
}

void Gerenciador_Eventos::setGI(Gerenciador_Input *pGI) {
  if (pGI) {
    this->pGI = pGI;
  } else {
    std::cerr << "erro: em Gerenciador_Eventos::setGI(), pGI == nullptr\n";
  }
}

void Gerenciador_Eventos::processaEventos() {
  if (pJanela && pGG) {
    sf::Event evento;

    while (pJanela->pollEvent(evento)) {
      // windowClose ou ESC para fechar a janela
      if (evento.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        pGG->fecharJanela();
      }

      else if (evento.type == sf::Event::KeyPressed) {
        pGI->ProcessaTeclaPressionada(evento.key.code);
      }

      else if (evento.type == sf::Event::KeyReleased) {
        pGI->ProcessaTeclaSolta(evento.key.code);
      }
    }
  } else {
    std::cerr << "erro: em Gerenciador_Eventos::processaEventos(), pGG == "
                 "nullptr || pJanela == nullptr\n";
  }
}
}  // namespace Gerenciadores
