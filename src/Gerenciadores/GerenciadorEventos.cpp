#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

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

void Gerenciador_Eventos::setGG(Gerenciador_Grafico *pGG) {
  if (pGG) {
    this->pGG = pGG;
    pJanela = pGG->getJanela();
  }
}

void Gerenciador_Eventos::setGI(Gerenciador_Input *pGI) {
  if (pGI) {
    this->pGI = pGI;
  }
}

void Gerenciador_Eventos::processaEventos() {
  if (pJanela && pGG) {

    sf::Event evento;

    while (pJanela->pollEvent(evento)) {

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
  }
}
} // namespace Gerenciadores
