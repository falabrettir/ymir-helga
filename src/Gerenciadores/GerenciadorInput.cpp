#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

using namespace Gerenciadores;

Gerenciador_Input *Gerenciador_Input::instancia = nullptr;

Gerenciador_Input::Gerenciador_Input() {
  keyMap.clear();
  keyMap[sf::Keyboard::A] = "A";
  keyMap[sf::Keyboard::D] = "D";
  keyMap[sf::Keyboard::W] = "W";
  keyMap[sf::Keyboard::Space] = "Space";
  keyMap[sf::Keyboard::Left] = "Left";
  keyMap[sf::Keyboard::Right] = "Right";
  keyMap[sf::Keyboard::Up] = "Up";
  keyMap[sf::Keyboard::RShift] = "RShift";
}

Gerenciador_Input::~Gerenciador_Input() { keyMap.clear(); }

Gerenciador_Input *Gerenciador_Input::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Input();
  }
  return instancia;
}

void Gerenciador_Input::setGG(Gerenciador_Grafico *ppGG) { pGG = ppGG; }

void Gerenciador_Input::processaInput() {}
