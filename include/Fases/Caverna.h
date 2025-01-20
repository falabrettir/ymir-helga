#pragma once

// Primeira fase

#include "Fase.h"

namespace Fases {

class Caverna : public Fase {
private:
  const int minEsqueletos = 3;
  const int maxEsqueletos = 5;
  const int minSlimes = 3;
  const int maxSlimes = 5;

public:
  Caverna();
  ~Caverna();

  void executar();
  void criarObstaculos();
  void criarInimigos();
  void criarSlimes();
  void criarEsqueletos();
  void criarEntidades();
};

} // namespace Fases
