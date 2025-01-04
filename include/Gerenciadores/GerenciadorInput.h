#pragma once

#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>

namespace Gerenciadores {

class Gerenciador_Input {
private:
  Gerenciador_Grafico *pGG;
  static Gerenciador_Input *instancia;

private:
  Gerenciador_Input();
  Gerenciador_Input(const Gerenciador_Input &) = delete;
  Gerenciador_Input &operator=(const Gerenciador_Input &) = delete;

public:
  ~Gerenciador_Input();
  static Gerenciador_Input &getInstancia();
  void setGG(Gerenciador_Grafico *pGG);
  void processaInput();
};

} // namespace Gerenciadores
