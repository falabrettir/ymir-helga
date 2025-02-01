#pragma once
#include "Menu/Botao.h"
#include "State.h"
#include <list>

namespace Menus {
class Menu : public Ente, public States::State {
private:
  std::list<Botao *> listaBotoes;
  std::list<Botao *>::iterator itBotao;

public:
  Menu(ID id);
  ~Menu();
  void addBotao(std::string &texto, const ID id);
};
} // namespace Menus
