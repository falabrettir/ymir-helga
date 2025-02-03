#pragma once
#include "Menu.h"

namespace Menus {
class MenuPrincipal : public Menu {
 private:
  sf::Text titulo;
  bool fase2;

 public:
  MenuPrincipal(ID id);
  ~MenuPrincipal();
  void inicializaTitulo();
  void executar();
  void criarBotoes();
  void setFase(Botao* botao);
  const bool getFase() const;
};
}  // namespace Menus
