#include "Controladores/ControladorMenu.h"

#include <SFML/Window/Keyboard.hpp>

#include "Gerenciadores/GerenciadorEstados.h"
#include "Observer.h"

namespace Controladores {
ControladorMenu::ControladorMenu(Menus::Menu* menu)
    : Observer(),
      menuAtual(menu),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()),
      teclasPressionadas() {
  teclasPressionadas.clear();
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
    }
  }
}
}  // namespace Controladores
