#include "Controladores/ControladorMenu.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Fases/Caverna.h"
#include "Fases/Planicie.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "IDs.h"
#include "Menu/MenuPrincipal.h"
#include "Observer.h"

namespace Controladores {
ControladorMenu::ControladorMenu(Menus::Menu *menu)
    : Observer(), menuAtual(menu),
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
        dynamic_cast<Menus::MenuPrincipal *>(menuAtual)->setFase(
            menuAtual->getBotao());
      } break;
      case (ID::IDbotaomultijogador): {
        dynamic_cast<Menus::MenuPrincipal *>(menuAtual)->setMultijogador(
            menuAtual->getBotao());
      } break;

      case (ID::IDbotaonovojogo): {
        bool fase = dynamic_cast<Menus::MenuPrincipal *>(menuAtual)->getFase();
        if (fase) {
          pGS->inserirEstado(new Fases::Planicie());
          pGS->mudarEstado(ID::IDplanicie);
        } else {
          pGS->inserirEstado(new Fases::Caverna());
          pGS->mudarEstado(ID::IDcaverna);
        }
      } break;
      case (ID::IDbotaosair): {
        Gerenciadores::GerenciadorGrafico::getInstancia()->getJanela()->close();
      } break;
      case (ID::IDbotaocontinuar): {
        pGS->mudarEstado(pGS->getEstadoAnterior());
      } break;
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
} // namespace Controladores
