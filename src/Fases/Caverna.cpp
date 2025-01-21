#include "Fases/Caverna.h"

namespace Fases {

Caverna::Caverna() : Fase() {}

Caverna::~Caverna() {}

void Caverna::executar() { Fase::executar(); }

void Caverna::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
  case 'E':
    criarEsqueleto();
    break;
  case 'S':
    criarSlime();
    break;
  case 'P':
    criarPedra();
    break;
  case 'M':
    criarMadeira();
    break;
  case 'G':
    criarGosma();
    break;
  default:
    break;
  }
}

void Caverna::criarSlime(const sf::Vector2f &pos) {}

}; // namespace Fases
