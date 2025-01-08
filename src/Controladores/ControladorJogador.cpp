#include "Controladores/ControladorJogador.h"
#include "Observer.h"
#include <SFML/Window/Keyboard.hpp>

namespace Controladores {

Controlador_Jogador::Controlador_Jogador()
    : pJog(nullptr), pGI(nullptr), Observer() {
  teclasPressionadas.clear();
}

Controlador_Jogador::~Controlador_Jogador() {
  pJog = nullptr;
  teclasPressionadas.clear();
}

void atualizarTeclasPressionadas(sf::Keyboard::Key tecla) {
  // TODO
}

void atualizarTeclasSoltas(sf::Keyboard::Key tecla) {
  // TODO
}

} // namespace Controladores
