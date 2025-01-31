#pragma once

#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"

namespace Fabricas {

class FabricaProjeteis {
 private:
  bool ativo;

 public:
  FabricaProjeteis();
  virtual ~FabricaProjeteis();

  virtual Entidades::Projetil *criarProjetil(
      Entidades::Personagens::Personagem *pPersDono, int impulso = 0) = 0;
};

}  // namespace Fabricas
