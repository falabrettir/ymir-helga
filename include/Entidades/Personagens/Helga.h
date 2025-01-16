#pragma once

#include "Jogador.h"

namespace Entidades::Personagens {

class Helga : public Entidades::Personagens::Jogador {
private:
  // TODO:
  // Classe projetil
  // Projetil* pFlecha;
  short int numFlechas;

public:
  Helga();
  ~Helga();
  void atacar();
  void executar();
};

} // namespace Entidades::Personagens
