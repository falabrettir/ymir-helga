#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>

using namespace Entidades;

namespace Fases {

Caverna::Caverna() : Fase(), contEsqueletos(0), contSlimes(0) {
  criarMapa("/assets/Mapas/caverna.txt");

  executar();
}

Caverna::~Caverna() {}

void Caverna::executar() { Fase::executar(); }
};  // namespace Fases
