#include "Fases/Fase.h"

namespace Fases {

Fase::Fase() {
  vecJog.clear();
  listaEntidades.limpar();
}

Fase::~Fase() {
  vecJog.clear();
  listaEntidades.limpar();
}

void Fase::criarPlataformas() {}

void Fase::criarCenario() {}

void Fase::executar() {
  criarPlataformas();
  criarCenario();
}

} // namespace Fases
