#include "jogo.h"
#include "gerenciadores/gerenciador-eventos.h"
#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Graphics/Color.hpp>

Jogo::Jogo() : rodando(false) {}

Jogo::~Jogo() { rodando = false; }

void Jogo::executar() {
  Gerenciadores::Gerenciador_Grafico *pGG =
      new Gerenciadores::Gerenciador_Grafico();

  Gerenciadores::Gerenciador_Eventos *pGE =
      new Gerenciadores::Gerenciador_Eventos();

  rodando = true;

  while (estaRodando()) {
    pGE->executar(pGG);
    pGG->getJanela()->clear(sf::Color::Black);
  }
}

bool Jogo::estaRodando() const { return rodando; }
