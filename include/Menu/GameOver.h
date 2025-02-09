#pragma once

#include "Menu/Menu.h"
namespace Menus {
class GameOver : public Menu {
 private:
  sf::Text _gameOver;

 public:
  GameOver(ID id);
  ~GameOver();
  void inicializaTitulo();
  void criarBotoes();
  void executar();
};
}  // namespace Menus
