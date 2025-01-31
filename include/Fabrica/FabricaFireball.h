#pragma once

#include "Entidades/Projetil.h"
#include "FabricaProjeteis.h"

namespace Fabricas {

class FabricaFireball : public FabricaProjeteis {
 private:
  static FabricaFireball *instancia;

 private:
  FabricaFireball();
  ~FabricaFireball();
  FabricaFireball(const FabricaFireball &) = delete;
  FabricaFireball &operator=(const FabricaFireball &) = delete;

 public:
  static FabricaFireball *getInstancia();

  Entidades::Projetil *criarProjetil(
      Entidades::Personagens::Personagem *pPersDono, int impulso = 0);
};

}  // namespace Fabricas
