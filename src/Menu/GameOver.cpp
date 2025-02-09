#include "Menu/GameOver.h"

#include "Controladores/ControladorMenu.h"
namespace Menus {
GameOver::GameOver(ID id) : Menu(id), _gameOver() {
  inicializaTitulo();
  pContr = new Controladores::ControladorMenu(this);
  pGI->inscrever(pContr);
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  criarBotoes();
}
GameOver::~GameOver() {}

void GameOver::inicializaTitulo() {
  _gameOver.setFont(*Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  _gameOver.setString("Game Over!");
  _gameOver.setScale(1.5f, 1.5f);
  _gameOver.setFillColor(sf::Color::White);
  _gameOver.setOutlineColor(sf::Color::Black);
  _gameOver.setOutlineThickness(3.f);
  _gameOver.setPosition(960 - _gameOver.getGlobalBounds().width / 2.f, 540);
}
void GameOver::criarBotoes() {
  Menu::addBotao("Sair", ID::IDbotaosair, {960, 720});
  inicializarIt();
}
void GameOver::executar() {
  desenhar();
  pGG->getJanela()->draw(_gameOver);
  std::list<Botao *>::iterator it = listaBotoes.begin();
  while (it != listaBotoes.end()) {
    (*it)->executar();
    ++it;
  }
  pContr->controlarMenu();
}

}  // namespace Menus
