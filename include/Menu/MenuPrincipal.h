#pragma once
#include "Menu.h"

namespace Menus {
class MenuPrincipal : public Menu {
private:
  sf::Text titulo;
  bool fase2;
  bool mp;
  static MenuPrincipal *instancia;

private:
  MenuPrincipal();
  ~MenuPrincipal();
  MenuPrincipal(const MenuPrincipal &) = delete;
  MenuPrincipal &operator=(const MenuPrincipal &) = delete;

public:
  static MenuPrincipal *getInstancia();
  void inicializaTitulo();
  void executar();
  void criarBotoes();
  void setFase(Botao *botao);
  void setMultijogador(Botao *botao);
  const bool getFase() const;
  const bool getMp() const;
};
} // namespace Menus
