#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"

namespace Fabricas {

class FabricaProjeteis {
 private:
  static FabricaProjeteis *instancia;

 private:
  FabricaProjeteis();
  ~FabricaProjeteis();
  FabricaProjeteis(const FabricaProjeteis &) = delete;
  FabricaProjeteis &operator=(const FabricaProjeteis &) = delete;

 public:
  static FabricaProjeteis *getInstancia();

  Entidades::Projetil *criarProjetil(
      Entidades::Personagens::Personagem *pPersDono, int impulso = 0);
};

}  // namespace Fabricas
