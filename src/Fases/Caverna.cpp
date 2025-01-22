#include "Fases/Caverna.h"

namespace Fases {

Caverna::Caverna() : Fase(), contEsqueletos(0), contSlimes(0) {}

Caverna::~Caverna() {}

void Caverna::executar() { Fase::executar(); }

void Caverna::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
  case 'E':
    criarEsqueleto(pos);
    break;

  case 'S':
    criarSlime(pos);
    break;

  case 'P':
    criarPedra(pos);
    break;

  case 'M':
    criarMadeira(pos);
    break;

  case 'G':
    criarGosma(pos);
    break;

  case 'J':
    criarJogador(pos);
    break;

  default:
    break;
  }
}

void Caverna::criarSlime(const sf::Vector2f &pos) {}

}; // namespace Fases
