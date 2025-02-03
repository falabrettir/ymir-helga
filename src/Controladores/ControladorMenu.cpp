#include "Controladores/ControladorMenu.h"

#include <SFML/Window/Keyboard.hpp>

#include "Fases/Caverna.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "IDs.h"
#include "Observer.h"
#include <iostream>

namespace Controladores {
ControladorMenu::ControladorMenu(Menus::Menu *menu)
    : Observer(), menuAtual(menu),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()),
      teclasPressionadas() {
  teclasPressionadas.clear();
  cima = sf::Keyboard::W;
  baixo = sf::Keyboard::S;
  selecionar = sf::Keyboard::Enter;
  teclasPressionadas.insert(std::pair<Key, bool>(selecionar, false));
  teclasPressionadas.insert(std::pair<Key, bool>(cima, false));
  teclasPressionadas.insert(std::pair<Key, bool>(baixo, false));
}
ControladorMenu::~ControladorMenu() {
  delete menuAtual;
  menuAtual = nullptr;
  pGS = nullptr;
  teclasPressionadas.clear();
}
bool ControladorMenu::acharTecla(Key tecla) {
  return (teclasPressionadas.find(tecla) != teclasPressionadas.end());
}
void ControladorMenu::atualizarTeclasPressionadas(Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = true;
  }
}

void ControladorMenu::atualizarTeclasSoltas(Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = false;
  }
}
void ControladorMenu::controlarMenu() {
  if (menuAtual) {
    if (teclasPressionadas[cima]) {
      menuAtual->cima();
    } else if (teclasPressionadas[baixo]) {
      menuAtual->baixo();
    } else if (teclasPressionadas[selecionar]) {
      // TODO: lógica de selecao
      ID id = menuAtual->getIdSelecionado();
      switch (id) {
      case (ID::IDbotaonovojogo): {
        std::cerr << "Marcha no menuAtual\n";
        pGS->pushEstado(new Fases::Caverna());
      } break;
      default:
        break;
      }
    }
  }
}
} // namespace Controladores
