#pragma once

#include "Fabrica/FabricaProjeteis.h"

namespace Fabricas {

class FabricaFlechas : public FabricaProjeteis {
 private:
  static FabricaFlechas *instancia;

 private:
  FabricaFlechas();
  ~FabricaFlechas();
  FabricaFlechas(const FabricaFlechas &) = delete;
  FabricaFlechas &operator=(const FabricaFlechas &) = delete;

 public:
  static FabricaFlechas *getInstancia();

  Entidades::Projetil *criarProjetil(
      Entidades::Personagens::Personagem *pPersDono, int impulso = 0);
};

}  // namespace Fabricas
