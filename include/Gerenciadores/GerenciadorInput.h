#pragma once

#include <SFML/Window.hpp>

namespace Gerenciadores {

class Gerenciador_Input {
private:
  sf::Window *pJanela;

public:
  void processaInput();
  bool teclaPressionada(sf::Keyboard::Key tecla) const;
};

} // namespace Gerenciadores
