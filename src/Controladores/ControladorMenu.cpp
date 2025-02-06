#include "Controladores/ControladorMenu.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Fases/Caverna.h"
#include "Fases/Planicie.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "IDs.h"
#include "Menu/MenuPrincipal.h"
#include "Observer.h"

namespace Controladores {
ControladorMenu::ControladorMenu(Menus::Menu *menu)
    : Observer(),
      menuAtual(menu),
      pGS(Gerenciadores::GerenciadorEstados::getInstancia()),
      teclasPressionadas() {
  teclasPressionadas.clear();
  setTeclas();
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
      teclasPressionadas[cima] = false;
    } else if (teclasPressionadas[baixo]) {
      menuAtual->baixo();
      teclasPressionadas[baixo] = false;

    } else if (teclasPressionadas[selecionar]) {
      ID id = menuAtual->getIdSelecionado();
      teclasPressionadas[selecionar] = false;
      switch (id) {
        case (ID::IDbotaofase): {
          dynamic_cast<Menus::MenuPrincipal *>(menuAtual)->setFase(menuAtual->getBotao());
        } break;

        case (ID::IDbotaonovojogo): {
          std::cerr << "Marcha no menuAtual\n";
          bool fase = dynamic_cast<Menus::MenuPrincipal *>(menuAtual)->getFase();
          if (fase) {
            pGS->pushEstado(new Fases::Planicie());
          } else {
            pGS->pushEstado(new Fases::Caverna());
          }
        } break;

        case (ID::IDbotaosair): {
          pGS->popEstado();
          pGS->popEstado();
        }
        case (ID::IDbotaocontinuar): {
          pGS->popEstado();
        }
        // TODO: Botao salvar jogada
        default:
          break;
      }
    }
  }
}
void ControladorMenu::setTeclas() {
  cima = sf::Keyboard::W;
  baixo = sf::Keyboard::S;
  selecionar = sf::Keyboard::Enter;
  teclasPressionadas.insert(std::pair<Key, bool>(selecionar, false));
  teclasPressionadas.insert(std::pair<Key, bool>(cima, false));
  teclasPressionadas.insert(std::pair<Key, bool>(baixo, false));
}
}  // namespace Controladores
