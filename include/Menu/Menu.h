#pragma once
#include <SFML/System/Vector2.hpp>
#include <list>

#include "Gerenciadores/GerenciadorInput.h"
#include "Menu/Botao.h"
#include "State.h"
namespace Controladores {
class ControladorMenu;
}

namespace Menus {
class Menu : public Ente, public States::State {
 protected:
  std::list<Botao *> listaBotoes;
  std::list<Botao *>::iterator itBotao;
  Controladores::ControladorMenu *pContr;
  Gerenciadores::GerenciadorInput *pGI;

 public:
  Menu(ID id);
  ~Menu();
  void addBotao(const std::string &texto, const ID id, sf::Vector2f pos);
  const ID getIdSelecionado() const;
  void cima();
  void baixo();
  void inicializarIt();
  virtual void executar() = 0;
};
}  // namespace Menus
