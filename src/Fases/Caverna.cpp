#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace Entidades;

namespace Fases {

Caverna::Caverna() : Fase(), contEsqueletos(0), contSlimes(0) {
  std::clog << "Criando caverna.\n";

  criarMapa("/assets/Mapas/caverna.txt");

  executar();
}

Caverna::~Caverna() {}

void Caverna::executar() { Fase::executar(); }
};  // namespace Fases
