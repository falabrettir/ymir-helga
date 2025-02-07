#include "Gerenciadores/GerenciadorEventos.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"

namespace Gerenciadores {
GerenciadorEventos *GerenciadorEventos::instancia = nullptr;

GerenciadorEventos::GerenciadorEventos()
    : pGG(GerenciadorGrafico::getInstancia()),
      pGI(GerenciadorInput::getInstancia()) {
  pJanela = pGG->getJanela();
}

GerenciadorEventos::~GerenciadorEventos() {
  pJanela = nullptr;
  pGG = nullptr;
  pGI = nullptr;
  delete instancia;
}

GerenciadorEventos *GerenciadorEventos::getInstancia() {
  if (!instancia) {
    instancia = new GerenciadorEventos();
  }
  return instancia;
}

void GerenciadorEventos::processaEventos() {
  if (pJanela && pGG) {
    sf::Event evento;

    while (pJanela->pollEvent(evento)) {
      // windowClose ou ESC para fechar a janela
      if (evento.type == sf::Event::Closed) {
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
    std::cerr << "erro: Gerenciador_Eventos::processaEventos(), pGG == "
                 "nullptr || pJanela == nullptr\n";
    exit(EXIT_FAILURE);
  }
}
}  // namespace Gerenciadores
