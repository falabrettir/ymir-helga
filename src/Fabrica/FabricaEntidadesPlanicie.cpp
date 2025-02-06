#include "Fabrica/FabricaEntidadesPlanicie.h"

#include <iostream>

#include "Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

namespace Fabricas {

FabEntPlanicie *FabEntPlanicie::instancia = nullptr;

FabEntPlanicie::FabEntPlanicie() : FabricaEntidades() {
  std::clog << "Criando FabEntPlanicie\n";
}

FabEntPlanicie::~FabEntPlanicie() {
  std::clog << "Destruindo FabEntPlanicie\n";
}

FabEntPlanicie *FabEntPlanicie::getInstancia() {
  if (!instancia) {
    instancia = new FabEntPlanicie();
    std::clog << "FabEntPlanicie criado\n";
  }
  return instancia;
}

Obstaculos::Plataforma *FabEntPlanicie::criarMadeira(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlat =
      new Obstaculos::Plataforma(ID::IDmadeira2, pos);
  return novaPlat;
}

Obstaculos::Plataforma *FabEntPlanicie::criarChao(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlat =
      new Obstaculos::Plataforma(ID::IDgrama, pos);
  return novaPlat;
}

Entidade *FabEntPlanicie::criarEntidade(char tipoEntidade,
                                        const sf::Vector2f &pos) {
  switch (tipoEntidade) {
  case 'E':
    if (pP->getCont(tipoEntidade) < pP->getMinEsq() || rand() % 5 > 1) {
      pP->incrementaContadores(tipoEntidade);
      return criarEsqueleto(pos);
    }
    break;
  case 'S':
    if (pP->getCont(tipoEntidade) < pP->getMinMago() || rand() % 5 > 1) {
      pP->incrementaContadores(tipoEntidade);
      return criarMago(pos);
    }
    break;
  case 'P':
    return criarChao(pos);
    break;
  case 'M':
    if (pP->getCont(tipoEntidade) < pP->getMinPlat() || rand() % 5 > 1) {
      pP->incrementaContadores(tipoEntidade);
      return criarMadeira(pos);
    }
    break;
  case 'G':
    if (pP->getCont(tipoEntidade) < pP->getMinGosma() || rand() % 5 > 1) {
      pP->incrementaContadores(tipoEntidade);
      return criarGosma(pos);
    }
    break;
  case 'J':
    return criarJogador(pos);
  default:
    return nullptr;
  }
  return nullptr;
}
void FabEntPlanicie::setFase(Fases::Planicie *pP) { this->pP = pP; }

} // namespace Fabricas
