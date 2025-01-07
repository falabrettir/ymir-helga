#pragma once

#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <map>
#include <string>

namespace Gerenciadores {

class Gerenciador_Input {
private:
  static Gerenciador_Grafico *pGG;
  static Gerenciador_Input *instancia;
  std::map<sf::Keyboard::Key, std::string> keyMap;

private:
  Gerenciador_Input();
  ~Gerenciador_Input();
  Gerenciador_Input(const Gerenciador_Input &) = delete;
  Gerenciador_Input &operator=(const Gerenciador_Input &) = delete;

public:
  static Gerenciador_Input *getInstancia();
  static void setGG(Gerenciador_Grafico *ppGG);
  void processaInput();
};

} // namespace Gerenciadores
