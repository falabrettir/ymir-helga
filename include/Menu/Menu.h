#pragma once
#include <SFML/System/Vector2.hpp>
#include <list>

#include "Menu/Botao.h"
#include "State.h"

namespace Menus {
class Menu : public Ente, public States::State {
 private:
  std::list<Botao *> listaBotoes;
  std::list<Botao *>::iterator itBotao;

 public:
  Menu(ID id);
  ~Menu();
  virtual void addBotao(const std::string &texto, const ID id, sf::Vector2f pos) = 0;
  void cima();
  void baixo();
  void inicializarIt();
  void executar();
};
}  // namespace Menus
