#pragma once

#include "Menu/Menu.h"
namespace Menus {
class GameOver : public Menu {
 private:
  sf::Text _gameOver;

 public:
  GameOver(ID id, bool venceu);
  ~GameOver();
  void inicializaTitulo(bool venceu);
  void criarBotoes();
  void executar();
};
}  // namespace Menus
