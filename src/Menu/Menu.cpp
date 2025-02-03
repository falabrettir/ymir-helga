#include "Menu/Menu.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Controladores/ControladorMenu.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "IDs.h"
#include "Menu/Botao.h"
#include "State.h"

namespace Menus {
Menu::Menu(ID id)
    : Ente(id), States::State(), listaBotoes(), itBotao(), pContr(),
      pGI(Gerenciadores::GerenciadorInput::getInstancia()) {
  pContr = new Controladores::ControladorMenu(this);
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  pGI->inscrever(pContr);
  listaBotoes.clear();
  addBotao("Novo jogo", ID::IDbotaonovojogo, {960, 216});
  addBotao("Sair", ID::IDbotaonovojogo, {960, 432});
  inicializarIt();
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
void Menu::executar() {
  std::cerr << "Executar de menu\n";
  desenhar();
  std::list<Botao *>::iterator it = listaBotoes.begin();
  while (it != listaBotoes.end()) {
    (*it)->executar();
    ++it;
  }
  pContr->controlarMenu();
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
  Menus::Botao *botao = *itBotao;
  botao->setSelecionado(false);
  if (itBotao == listaBotoes.begin()) {
    itBotao = listaBotoes.end();
  }
  --itBotao;
  botao = *itBotao;
  botao->setSelecionado(true);
}
void Menu::baixo() {
  Menus::Botao *botao = *itBotao;
  botao->setSelecionado(false);
  itBotao++;
  if (itBotao == listaBotoes.end()) {
    itBotao = listaBotoes.begin();
  }
  botao = *itBotao;
  botao->setSelecionado(true);
}
const ID Menu::getIdSelecionado() const { return (*itBotao)->getId(); }
void Menu::addBotao(const std::string &texto, const ID id, sf::Vector2f pos) {
  listaBotoes.push_back(new Botao(texto, id, pos));
}

} // namespace Menus
