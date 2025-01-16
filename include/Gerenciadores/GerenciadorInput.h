#pragma once

#include "Subject.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <map>
#include <string>

namespace Controladores {
class Controlador_Jogador;
} // namespace Controladores

namespace Gerenciadores {

class Gerenciador_Input : public Subject {
private:
  static Gerenciador_Input *instancia;
  std::map<sf::Keyboard::Key, std::string> keyMap;

private:
  Gerenciador_Input();
  ~Gerenciador_Input();
  Gerenciador_Input(const Gerenciador_Input &) = delete;
  Gerenciador_Input &operator=(const Gerenciador_Input &) = delete;

public:
  static Gerenciador_Input *getInstancia();

  void ProcessaTeclaPressionada(sf::Keyboard::Key tecla);
  void ProcessaTeclaSolta(sf::Keyboard::Key tecla);
};

} // namespace Gerenciadores
