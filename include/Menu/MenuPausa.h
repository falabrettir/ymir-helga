#pragma once
#include "Fases/Fase.h"
#include "Menu/Menu.h"
namespace Menus {
class MenuPausa : public Menu {
 private:
  Fases::Fase* faseAtual;

 public:
  MenuPausa(ID id, Fases::Fase* fAtual);
  ~MenuPausa();
  void executar();
  void criarBotoes();
};
}  // namespace Menus
