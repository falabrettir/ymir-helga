#include "Menu/MenuPrincipal.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Controladores/ControladorMenu.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#define ALTURA 130

namespace Menus {
MenuPrincipal *MenuPrincipal::instancia(nullptr);
MenuPrincipal::MenuPrincipal()
    : Menu(ID::IDmenuprincipal), titulo(), fase2(false) {
  inicializaTitulo();
  pContr = new Controladores::ControladorMenu(this);
  pGI->inscrever(pContr);
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  criarBotoes();
}
MenuPrincipal::~MenuPrincipal() {}
void MenuPrincipal::criarBotoes() {
  Menu::addBotao("Novo jogo", ID::IDbotaonovojogo, {960, ALTURA * 2});
  Menu::addBotao("Multijogador", ID::IDbotaomultijogador, {960, ALTURA * 3});
  Menu::addBotao("Caverna", ID::IDbotaofase, {960, ALTURA * 4});
  Menu::addBotao("Sair", ID::IDbotaosair, {960, ALTURA * 7});
  inicializarIt();
}
void MenuPrincipal::executar() {
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
  titulo.setFont(
      *Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  titulo.setString("Ymir e Helga");
  titulo.setScale(1.5f, 1.5f);
  titulo.setFillColor(sf::Color::White);
  titulo.setOutlineColor(sf::Color::Black);
  titulo.setOutlineThickness(3.f);
  titulo.setPosition(960 - titulo.getGlobalBounds().width / 2.f, ALTURA);
}
void MenuPrincipal::setFase(Botao *botao) {
  fase2 = !fase2;
  botao->mudaFase(fase2);
}
const bool MenuPrincipal::getFase() const { return fase2; }
MenuPrincipal *MenuPrincipal::getInstancia() {
  if (instancia == nullptr) {
    instancia = new MenuPrincipal();
  }
  return instancia;
}
} // namespace Menus
