#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <limits>

#include "Fabrica/FabricaEntidadesCaverna.h"

using namespace Entidades;

namespace Fases {
int Caverna::contSlimes(0);
int Caverna::contEsq(0);
int Caverna::contEsp(0);
int Caverna::contPlat(0);
Caverna::Caverna(bool mp)
    : Fase(ID::IDcaverna, mp), minEsq(3), minSlimes(3), minEsp(4), minPlat(5) {
  std::clog << "Criando caverna.\n";

  setTextura("/assets/Fundos/caverna.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntCaverna::getInstancia();
  dynamic_cast<Fabricas::FabEntCaverna *>(pFE)->setFase(this);
  criarMapa("/assets/Mapas/caverna.txt");
}

Caverna::~Caverna() {}

void Caverna::executar() {
  pGG->getJanela()->draw(getSprite());
  Fase::executar();
}
const int Caverna::getMinEsq() const { return minEsq; }
const int Caverna::getMinSli() const { return minSlimes; }
const int Caverna::getMinEsp() const { return minEsp; }
const int Caverna::getMinPlat() const { return minPlat; }

const int Caverna::getCont(char tipoEnt) {
  switch (tipoEnt) {
  case 'E':
    return contEsq;
  case 'S':
    return contSlimes;
  case 'G':
    return contEsp;
  case 'M':
    return contPlat;
  default:
    return std::numeric_limits<int>::max();
  }
}
void Caverna::incrementaContadores(char tipoEnt) {
  switch (tipoEnt) {
  case 'E':
    contEsq++;
  case 'S':
    contSlimes++;
  case 'G':
    contEsp++;
  case 'M':
    contPlat++;
  }
}
}; // namespace Fases
