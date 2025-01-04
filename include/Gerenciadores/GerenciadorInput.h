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

public:
  ~Gerenciador_Input();
  Gerenciador_Input *getInstancia();
  void setGG(Gerenciador_Grafico *pGG);
  void processaInput();
  bool teclaPressionada(sf::Keyboard::Key tecla) const;
};

} // namespace Gerenciadores
