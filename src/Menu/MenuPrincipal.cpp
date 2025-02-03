#include "Menu/MenuPrincipal.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "Controladores/ControladorMenu.h"
#include "Gerenciadores/GerenciadorGrafico.h"

namespace Menus {
MenuPrincipal::MenuPrincipal(ID id) : Menu(id), titulo() {
  inicializaTitulo();
  pContr = new Controladores::ControladorMenu(this);
  pGI->inscrever(pContr);
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  criarBotoes();
}
MenuPrincipal::~MenuPrincipal() {}
void MenuPrincipal::criarBotoes() {
  Menu::addBotao("Novo jogo", ID::IDbotaonovojogo, {960, 320});
  Menu::addBotao("Multijogador", ID::IDbotaomultijogador, {960, 480});
  Menu::addBotao("Caverna", ID::IDbotaofase, {960, 640});
  Menu::addBotao("Carregar jogo", ID::IDbotaocarregarjogo, {960, 800});
  Menu::addBotao("Colocacao", ID::IDbotaomultijogador, {960, 960});
  inicializarIt();
}
void MenuPrincipal::executar() {
  std::cerr << "Executar de menu principal\n";
  desenhar();
  pGG->getJanela()->draw(titulo);
  std::list<Botao *>::iterator it = listaBotoes.begin();
  while (it != listaBotoes.end()) {
    (*it)->executar();
    ++it;
  }
  pContr->controlarMenu();
}
void MenuPrincipal::inicializaTitulo() {
  titulo.setFont(*Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  titulo.setString("Ymir e Helga");
  titulo.setScale(2.f, 2.f);
  titulo.setFillColor(sf::Color::White);
  titulo.setOutlineColor(sf::Color::Black);
  titulo.setOutlineThickness(3.f);
  titulo.setPosition(960 - titulo.getGlobalBounds().width / 2.f, 160);
}
}  // namespace Menus
