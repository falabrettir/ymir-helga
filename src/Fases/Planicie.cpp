#include "Fases/Planicie.h"

#include <iostream>
#include <limits>

#include "Fabrica/FabricaEntidadesPlanicie.h"
#include "Fases/Fase.h"

using namespace Entidades;

namespace Fases {
int Planicie::contMago(0);
int Planicie::contEsq(0);
int Planicie::contPlat(0);
int Planicie::contGosma(0);
Planicie::Planicie(bool mp)
    : Fase(ID::IDplanicie, mp), minGosma(5), minPlat(4), minMago(4), minEsq(5) {
  std::clog << "Criando Planicie.\n";

  setTextura("/assets/Fundos/fundofase2escalado.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntPlanicie::getInstancia();

  dynamic_cast<Fabricas::FabEntPlanicie *>(pFE)->setFase(this);
  criarMapa("/assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {}

void Planicie::executar() {
  pGG->getJanela()->draw(getSprite());
  Fase::executar();
}
const int Planicie::getMinEsq() const { return minEsq; }
const int Planicie::getMinMago() const { return minMago; }
const int Planicie::getMinGosma() const { return minGosma; }
const int Planicie::getMinPlat() const { return minPlat; }

const int Planicie::getCont(char tipoEnt) {
  switch (tipoEnt) {
  case 'E':
    return contEsq;
  case 'W':
    return contMago;
  case 'G':
    return contGosma;
  case 'M':
    return contPlat;
  default:
    return std::numeric_limits<int>::max();
  }
}
void Planicie::incrementaContadores(char tipoEnt) {
  switch (tipoEnt) {
  case 'E':
    contEsq++;
  case 'W':
    contMago++;
  case 'G':
    contGosma++;
  case 'M':
    contPlat++;
  }
}

} // namespace Fases
