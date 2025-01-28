#include "Fabrica/FabricaEntidadesCaverna.h"

#include <iostream>

#include "Fabrica/FabricaEntidades.h"

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
  // TODO: Criar plataforma de madeira1
}

Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos) {
  // TODO: Criar chao de pedra
}

void criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  // TODO: Switch case para criar entidades
}

}  // namespace Fabricas
