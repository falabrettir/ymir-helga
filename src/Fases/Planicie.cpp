#include "Fases/Planicie.h"

#include "Fases/Fase.h"

using namespace Entidades;

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) {
  criarMapa("assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {}

void Planicie::executar() { Fase::executar(); }

}  // namespace Fases
