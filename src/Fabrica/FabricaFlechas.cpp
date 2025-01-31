#include "Fabrica/FabricaFlechas.h"

#include <iostream>

namespace Fabricas {

FabricaFlechas* FabricaFlechas::instancia = nullptr;

FabricaFlechas::FabricaFlechas() {}

FabricaFlechas::~FabricaFlechas() {}

FabricaFlechas* FabricaFlechas::getInstancia() {
  if (!instancia) {
    instancia = new FabricaFlechas();
    std::clog << "FabricaFlechas criada\n";
  }
  return instancia;
}

Entidades::Projetil* FabricaFlechas::criarProjetil(
    Entidades::Personagens::Personagem* pPersDono, int impulso) {
  return (new Entidades::Projetil(pPersDono, impulso));
}

}  // namespace Fabricas
