#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <limits>

#include "Fabrica/FabricaEntidadesCaverna.h"

using namespace Entidades;

namespace Fases {
int Caverna::contSlimes(0);
int Caverna::contEsqueletos(0);
int Caverna::contGosmas(0);
int Caverna::contPlat(0);
Caverna::Caverna()
    : Fase(), minEsqueletos(3), minSlimes(3), minGosmas(4), minPlat(5) {
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
const int Caverna::getMinEsq() const { return minEsqueletos; }
const int Caverna::getMinSli() const { return minSlimes; }
const int Caverna::getMinGosmas() const { return minGosmas; }
const int Caverna::getMinPlat() const { return minPlat; }

const int Caverna::getCont(char tipoEnt) {
  switch (tipoEnt) {
  case 'E':
    return contEsqueletos;
  case 'S':
    return contSlimes;
  case 'G':
    return contGosmas;
  case 'M':
    return contPlat;
  default:
    return std::numeric_limits<int>::max();
  }
}
}; // namespace Fases
