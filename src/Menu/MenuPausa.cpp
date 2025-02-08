#include "Menu/MenuPausa.h"

#include "Controladores/ControladorMenu.h"
#include "IDs.h"

namespace Menus {

MenuPausa *MenuPausa::instancia(nullptr);

MenuPausa::MenuPausa() : Menu(ID::IDmenupause) {
  pContr = new Controladores::ControladorMenu(this);
  pGI->inscrever(pContr);
  setTextura("/assets/Menu.png");
  pSprite->setScale(1.f, 1.f);
  criarBotoes();
}
MenuPausa::~MenuPausa() {}
void MenuPausa::criarBotoes() {
  addBotao("Continuar", ID::IDbotaocontinuar, {960, 180});
  addBotao("Sair", ID::IDbotaosair, {960, 540});
  inicializarIt();
}
void MenuPausa::executar() {
  desenhar();
  std::list<Botao *>::iterator it = listaBotoes.begin();
  while (it != listaBotoes.end()) {
    (*it)->executar();
    ++it;
  }
  pContr->controlarMenu();
}
MenuPausa *MenuPausa::getInstancia() {
  if (instancia == nullptr) {
    instancia = new MenuPausa();
  }
  return instancia;
}
} // namespace Menus
