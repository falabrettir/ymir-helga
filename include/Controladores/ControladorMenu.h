#pragma once
#include <SFML/Window/Keyboard.hpp>

#include "Gerenciadores/GerenciadorEstados.h"
#include "Menu/Menu.h"
#include "Observer.h"

typedef sf::Keyboard::Key Key;
namespace Controladores {
class ControladorMenu : public Observer {
 private:
  Gerenciadores::GerenciadorEstados* pGS;
  Menus::Menu* menuAtual;
  std::map<Key, bool> teclasPressionadas;
  Key cima;
  Key baixo;
  Key selecionar;

 public:
  ControladorMenu(Menus::Menu* menu);
  ~ControladorMenu();
  bool acharTecla(Key tecla);

  void atualizarTeclasPressionadas(Key tecla);
  void atualizarTeclasSoltas(Key tecla);
  void controlarMenu();
};
}  // namespace Controladores
