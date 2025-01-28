#include "Fabrica/FabricaEntidadesPlanicie.h"

#include <iostream>

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
  // TODO: Criar plataforma de madeira2
}

Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos) {
  // TODO: Criar chao de grama
}

void criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  // TODO: Switch case para criar entidades
}

}  // namespace Fabricas
