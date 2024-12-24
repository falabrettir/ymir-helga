#pragma once

namespace Fases {

class Fase {

public:
  Fase();
  ~Fase();

  virtual void executar();
  void criarPlataformas();
  void criarCenario();
};

} // namespace Fases
