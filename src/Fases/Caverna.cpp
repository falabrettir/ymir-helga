#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Fabrica/FabricaEntidadesCaverna.h"

using namespace Entidades;

namespace Fases {

Caverna::Caverna() : Fase(), contEsqueletos(0), contSlimes(0) {
  std::clog << "Criando caverna.\n";

  setTextura("/assets/Fundos/fundofase1escalado.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntCaverna::getInstancia();

  criarMapa("/assets/Mapas/caverna.txt");
}

Caverna::~Caverna() {}

void Caverna::executar() {
  pGG->getJanela()->draw(getSprite());
  Fase::executar();
}
};  // namespace Fases
