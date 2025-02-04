#pragma once

#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <map>
#include <string>

#include "Subject.h"

namespace Controladores {
class Controlador_Jogador;
}  // namespace Controladores

namespace Gerenciadores {

class GerenciadorInput : public Subject {
 private:
  static GerenciadorInput *instancia;
  std::map<sf::Keyboard::Key, std::string> keyMap;

 private:
  GerenciadorInput();
  ~GerenciadorInput();
  GerenciadorInput(const GerenciadorInput &) = delete;
  GerenciadorInput &operator=(const GerenciadorInput &) = delete;

 public:
  static GerenciadorInput *getInstancia();

  void ProcessaTeclaPressionada(sf::Keyboard::Key tecla);
  void ProcessaTeclaSolta(sf::Keyboard::Key tecla);
};

}  // namespace Gerenciadores
