#include "Fabrica/FabricaFireball.h"

#include <iostream>

namespace Fabricas {

FabricaFireball* FabricaFireball::instancia = nullptr;

FabricaFireball::FabricaFireball() {}

FabricaFireball::~FabricaFireball() {}

FabricaFireball* FabricaFireball::getInstancia() {
  if (!instancia) {
    instancia = new FabricaFireball();
    std::clog << "FabricaFireball criada\n";
  }
  return instancia;
}

Entidades::Projetil* FabricaFireball::criarProjetil(
    Entidades::Personagens::Personagem* pPersDono, int impulso) {
  return (new Entidades::Projetil(pPersDono, impulso));
}

}  // namespace Fabricas
