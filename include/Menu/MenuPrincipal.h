#pragma once
#include "Menu.h"

namespace Menus {
class MenuPrincipal : public Menu {
 private:
  sf::Text titulo;

 public:
  MenuPrincipal(ID id);
  ~MenuPrincipal();
  void inicializaTitulo();
  void executar();
  void criarBotoes();
};
}  // namespace Menus
