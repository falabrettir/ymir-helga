#include "../include/jogo.h"

Jogo::Jogo() : rodando(false) {}

Jogo::~Jogo() { rodando = false; }

void Jogo::executar() {
  Gerenciadores::Gerenciador_Grafico *GG =
      new Gerenciadores::Gerenciador_Grafico();
  rodando = true;
  while (estaRodando()) {
    rodando = false;
  }
}

bool Jogo::estaRodando() const { return rodando; }
