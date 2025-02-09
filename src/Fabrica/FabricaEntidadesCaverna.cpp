#include "Fabrica/FabricaEntidadesCaverna.h"

#include <time.h>

#include <iostream>

#include "Entidades/Obstaculos/Plataforma.h"
#include "Fabrica/FabricaEntidades.h"
#include "IDs.h"

using namespace Entidades;

namespace Fabricas {

FabEntCaverna* FabEntCaverna::instancia = nullptr;

FabEntCaverna::FabEntCaverna(const bool mp) : FabricaEntidades() {
  srand(time(nullptr));
}

FabEntCaverna::~FabEntCaverna() {
  std::clog << "Destruindo FabEntCaverna\n";
}

FabEntCaverna* FabEntCaverna::getInstancia(const bool mp) {
  if (!instancia) {
    instancia = new FabEntCaverna(mp);
  }
  return instancia;
}

Obstaculos::Plataforma* FabEntCaverna::criarMadeira(const sf::Vector2f& pos) {
  Obstaculos::Plataforma* novaPlat =
      new Obstaculos::Plataforma(ID::IDmadeira1, pos);
  return novaPlat;
}

Obstaculos::Plataforma* FabEntCaverna::criarChao(const sf::Vector2f& pos) {
  Obstaculos::Plataforma* novaPlat =
      new Obstaculos::Plataforma(ID::IDpedra, pos);
  return novaPlat;
}

Entidade* FabEntCaverna::criarEntidade(char tipoEntidade,
                                       const sf::Vector2f& pos) {
  switch (tipoEntidade) {
    case 'E':
      if (pC->getCont(tipoEntidade) < pC->getMinEsq() || rand() % 5 > 1) {
        pC->incrementaContadores(tipoEntidade);
        return criarEsqueleto(pos);
      }
      break;
    case 'S':
      if (pC->getCont(tipoEntidade) < pC->getMinSli() || rand() % 5 > 1) {
        pC->incrementaContadores(tipoEntidade);
        return criarSlime(pos);
      }
      break;
    case 'P':
      return criarChao(pos);
      break;
    case 'M':
      if (pC->getCont(tipoEntidade) < pC->getMinPlat() || rand() % 5 > 1) {
        pC->incrementaContadores(tipoEntidade);
        return criarMadeira(pos);
      }
      break;
    case 'G':
      if (pC->getCont(tipoEntidade) < pC->getMinEsp() || rand() % 5 > 1) {
        pC->incrementaContadores(tipoEntidade);
        return criarEspinho(pos);
      }
      break;
    case 'J':
      return criarJogador(pos);
      break;
    case 'H':
      if (pC->getMp()) {
        return criarJogador(pos);
        break;
      } else
        break;
    case 'F':
      return criarParede(pos);
    default:
      return nullptr;
  }
  return nullptr;
}
void FabEntCaverna::setFase(Fases::Caverna* pC) {
  this->pC = pC;
}

}  // namespace Fabricas
