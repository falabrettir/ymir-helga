#include "Menu/Menu.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "IDs.h"
#include "Menu/Botao.h"
#include "State.h"

namespace Menus {
Menu::Menu(ID id) : Ente(id), States::State(), listaBotoes(), itBotao() { listaBotoes.clear(); }
Menu::~Menu() {
  itBotao = listaBotoes.begin();
  while (itBotao != listaBotoes.end()) {
    delete *itBotao;
    *itBotao = nullptr;
    ++itBotao;
  }
  listaBotoes.clear();
}
void Menu::executar() {
  std::cerr << "Executar de menu\n";
  desenhar();
  itBotao = listaBotoes.begin();
  while (itBotao != listaBotoes.end()) {
    (*itBotao)->executar();
    ++itBotao;
  }
}
void Menu::inicializarIt() {
  try {
    itBotao = listaBotoes.begin();
    (*itBotao)->setSelecionado(true);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    exit(1);
  }
}
void Menu::cima() {
  Menus::Botao* botao = *itBotao;
  botao->setSelecionado(false);
  if (itBotao == listaBotoes.begin()) {
    itBotao = listaBotoes.end();
  }
  --itBotao;
  botao = *itBotao;
  botao->setSelecionado(true);
}
void Menu::baixo() {
  Menus::Botao* botao = *itBotao;
  botao->setSelecionado(false);
  itBotao++;
  if (itBotao == listaBotoes.end()) {
    itBotao = listaBotoes.begin();
  }
  botao = *itBotao;
  botao->setSelecionado(true);
}

}  // namespace Menus
