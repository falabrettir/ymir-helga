#include "Menu/Menu.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorInput.h"
#include "IDs.h"
#include "Menu/Botao.h"
#include "State.h"

namespace Menus {
Menu::Menu(ID id)
    : Ente(id),
      States::State(id),
      listaBotoes(),
      itBotao(),
      pContr(),
      pGI(Gerenciadores::GerenciadorInput::getInstancia()) {
  listaBotoes.clear();
}
Menu::~Menu() {
  itBotao = listaBotoes.begin();
  while (itBotao != listaBotoes.end()) {
    delete *itBotao;
    *itBotao = nullptr;
    ++itBotao;
  }
  listaBotoes.clear();
}
void Menu::inicializarIt() {
  try {
    itBotao = listaBotoes.begin();
    (*itBotao)->setSelecionado(true);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }
}
void Menu::cima() {
  (*itBotao)->setSelecionado(false);
  if (itBotao == listaBotoes.begin()) {
    itBotao = listaBotoes.end();
  }
  --itBotao;
  (*itBotao)->setSelecionado(true);
}
void Menu::baixo() {
  (*itBotao)->setSelecionado(false);
  itBotao++;
  if (itBotao == listaBotoes.end()) {
    itBotao = listaBotoes.begin();
  }
  (*itBotao)->setSelecionado(true);
}
const ID Menu::getIdSelecionado() const { return (*itBotao)->getId(); }
void Menu::addBotao(const std::string &texto, const ID id, sf::Vector2f pos) {
  listaBotoes.push_back(new Botao(texto, id, pos));
}
Botao *Menu::getBotao() { return *itBotao; }

}  // namespace Menus
