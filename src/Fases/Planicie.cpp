#include "Fases/Planicie.h"
#include "Fases/Fase.h"

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) {}

Planicie::~Planicie() {}

void Planicie::executar() { Fase::executar(); }

void Planicie::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
  case 'E':
    criarEsqueleto(pos);
    break;
  case 'O':
    criarOrc(pos);
    break;
  case 'G':
    criarGrama(pos);
    break;
  case 'M':
    criarMadeira(pos);
    break;
  case 'P':
    criarEspinho(pos);
    break;
  default:
    break;
  }
}

} // namespace Fases
