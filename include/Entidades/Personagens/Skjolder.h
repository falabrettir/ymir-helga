#pragma once
#include "Jogador.h"

namespace Entidades::Personagens {

class Skjolder : public Entidades::Personagens::Jogador {
private:
  float stamina;
  short int furia;

public:
  Skjolder();
  ~Skjolder();
  void atacar();
  void executar();
};

} // namespace Entidades::Personagens
