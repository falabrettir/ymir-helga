#include "Fases/Planicie.h"

#include <iostream>

#include "Fabrica/FabricaEntidadesPlanicie.h"
#include "Fases/Fase.h"

using namespace Entidades;

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) {
  std::clog << "Criando Planicie.\n";

  setTextura("/assets/Fundos/fundofase2escalado.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntPlanicie::getInstancia();

  criarMapa("assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {}

void Planicie::executar() {
  pGG->getJanela()->draw(getSprite());
  Fase::executar();
}

}  // namespace Fases
