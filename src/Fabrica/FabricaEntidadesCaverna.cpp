#include "Fabrica/FabricaEntidadesCaverna.h"

#include <iostream>

#include "Entidades/Obstaculos/Plataforma.h"
#include "Fabrica/FabricaEntidades.h"
#include "IDs.h"

using namespace Entidades;

namespace Fabricas {

FabEntCaverna *FabEntCaverna::instancia = nullptr;

FabEntCaverna::FabEntCaverna() : FabricaEntidades() {}

FabEntCaverna::~FabEntCaverna() {}

FabEntCaverna *FabEntCaverna::getInstancia() {
  if (!instancia) {
    instancia = new FabEntCaverna();
    std::clog << "FabEntCaverna criado\n";
  }
  return instancia;
}

Obstaculos::Plataforma *FabEntCaverna::criarMadeira(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlat =
      new Obstaculos::Plataforma(ID::IDmadeira1, pos);
  return novaPlat;
}

Obstaculos::Plataforma *FabEntCaverna::criarChao(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlat =
      new Obstaculos::Plataforma(ID::IDpedra, pos);
  return novaPlat;
}

void FabEntCaverna::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
    case 'E':
      // TODO: somar a quantidade de esqueletos na fase
      criarEsqueleto(pos);
      break;
    case 'S':
      // TODO: somar a quantidade de slimes na fase
      criarSlime(pos);
      break;
    case 'P':
      criarChao(pos);
      break;
    case 'M':
      criarMadeira(pos);
      break;
    case 'G':
      criarGosma(pos);
      break;
    case 'J':
      criarJogador(pos);
      break;
    default:
      break;
  }
}

}  // namespace Fabricas
