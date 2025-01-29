#include "Fases/Planicie.h"

#include "Fases/Fase.h"

using namespace Entidades;

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) {
  criarMapa("assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {}

void Planicie::executar() { Fase::executar(); }

void Planicie::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
    case 'E':
      criarEsqueleto(pos);
      break;
    case 'W':
      criarMago(pos);
      break;
    case 'G':
      criarGrama(pos);
      break;
    case 'M':
      criarMadeira(pos);
      break;
    case 'S':
      criarEspinho(pos);
      break;
    case 'J':
      criarJogador(pos);
      break;
    default:
      break;
  }
}

}  // namespace Fases
