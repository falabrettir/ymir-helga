#include "Menu/Menu.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "IDs.h"
#include "Menu/Botao.h"
#include "State.h"

namespace Menus {
Menu::Menu(ID id) : Ente(id), States::State(), listaBotoes(), itBotao() {
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  pSprite->setPosition(0.f, 0.f);
  listaBotoes.clear();
  addBotao("Ymir e Helga", ID::IDbotaonovojogo, {960, 216});
  addBotao("Testoso", ID::IDbotaonovojogo, {960, 432});
  addBotao("Marcha", ID::IDbotaonovojogo, {960, 648});
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
void Menu::addBotao(const std::string& texto, const ID id, sf::Vector2f pos) {
  listaBotoes.push_back(new Botao(texto, id, pos));
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

}  // namespace Menus
