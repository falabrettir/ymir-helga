#include "Fabrica/FabricaEntidadesPlanicie.h"

#include <iostream>

#include "Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

namespace Fabricas {

FabEntPlanicie *FabEntPlanicie::instancia = nullptr;

FabEntPlanicie::FabEntPlanicie() : FabricaEntidades() {}

FabEntPlanicie::~FabEntPlanicie() {}

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
      // TODO: somar a quantidade de esqueletos na fase
      return criarEsqueleto(pos);
    case 'S':
      // TODO: somar a quantidade de magos na fase
      return criarMago(pos);
    case 'P':
      return criarChao(pos);
    case 'M':
      return criarMadeira(pos);
    case 'G':
      return criarGosma(pos);
    case 'J':
      return criarJogador(pos);
    default:
      return nullptr;
  }
}

}  // namespace Fabricas
