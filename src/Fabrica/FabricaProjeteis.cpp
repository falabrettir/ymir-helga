#include "Fabrica/FabricaProjeteis.h"

#include <iostream>

#include "Entidades/Projetil.h"

using namespace Entidades;

namespace Fabricas {

FabricaProjeteis *FabricaProjeteis::instancia = nullptr;

FabricaProjeteis::FabricaProjeteis() {
  std::clog << "Criando FabricaProjeteis\n";
}

FabricaProjeteis::~FabricaProjeteis() { delete instancia; }

FabricaProjeteis *FabricaProjeteis::getInstancia() {
  if (!instancia) {
    instancia = new FabricaProjeteis();
  }
  return instancia;
}

Entidades::Projetil *FabricaProjeteis::criarProjetil(
    Entidades::Personagens::Personagem *pPersDono, int impulso) {
  return (new Entidades::Projetil(pPersDono, impulso));
}

}  // namespace Fabricas
