#pragma once

// Segunda fase

#include "Fase.h"

namespace Fases {

class Planicie : public Fase {
private:
  const int minOrc = 3;
  const int maxOrc = 5;
  const int minSlimes = 3;
  const int maxSlimes = 5;

public:
  Planicie();
  ~Planicie();

  void executar();
  void criarObstaculos();
  void criarInimigos();
  void criarSlimes();
  void criarOrcs();
  void criarEntidades();
};

} // namespace Fases
