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
  std::clog << "Criando Planicie." << std::endl;

  setTextura("/assets/Fundos/planicie.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntPlanicie::getInstancia();
  dynamic_cast<Fabricas::FabEntPlanicie*>(pFE)->setFase(this);

  criarMapa("/assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {
  delete pFE;
  pFE = nullptr;
}

void Planicie::executar() {
  if (pGG == nullptr) {
    std::cerr << "erro: Planicie::executar() => pGG == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Desenha o fundo
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
      break;
    case 'W':
      return contMago;
      break;
    case 'G':
      return contGosma;
      break;
    case 'M':
      return contPlat;
      break;
    default:
      return std::numeric_limits<int>::max();
      break;
  }
}

void Planicie::incrementaContadores(char tipoEnt) {
  switch (tipoEnt) {
    case 'E':
      contEsq++;
      break;
    case 'W':
      contMago++;
      break;
    case 'G':
      contGosma++;
      break;
    case 'M':
      contPlat++;
      break;
  }
}

}  // namespace Fases
