#pragma once
#include "Menu/Menu.h"
namespace Menus {
class MenuPausa : public Menu {
 private:
  static MenuPausa* instancia;

 private:
  MenuPausa();
  ~MenuPausa();
  MenuPausa(const MenuPausa&) = delete;
  MenuPausa& operator=(const MenuPausa&) = delete;

 public:
  static MenuPausa* getInstancia();
  void executar();
  void criarBotoes();
};
}  // namespace Menus
