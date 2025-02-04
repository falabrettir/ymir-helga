#include "Controladores/ControladorJogador.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <iostream>
#include <utility>

#include "Entidades/Personagens/Jogador.h"
#include "Observer.h"

namespace Controladores {

// Constroi com controles padrao (WASD+Space)
Controlador_Jogador::Controlador_Jogador() : pJog(nullptr), Observer() {
  teclasPressionadas.clear();
}

Controlador_Jogador::~Controlador_Jogador() {
  pJog = nullptr;
  teclasPressionadas.clear();
}

void Controlador_Jogador::setJog(Entidades::Personagens::Jogador *pJog) {
  if (pJog) {
    this->pJog = pJog;
    setControles();
  } else {
    std::cerr << "error: parametro invalido em Controlador_Jogador::setJog(), "
                 "pJog == nullptr\n";
    exit(EXIT_FAILURE);
  }
}

void Controlador_Jogador::setControles() {
  if (pJog->getPrimeiroJog()) {
    direita = sf::Keyboard::D;
    esquerda = sf::Keyboard::A;
    pulo = sf::Keyboard::W;
    ataque = sf::Keyboard::Space;

  } else {
    direita = sf::Keyboard::Right;
    esquerda = sf::Keyboard::Left;
    pulo = sf::Keyboard::Up;
    ataque = sf::Keyboard::RShift;
  }

  teclasPressionadas.insert(std::pair<Key, bool>(direita, false));
  teclasPressionadas.insert(std::pair<Key, bool>(esquerda, false));
  teclasPressionadas.insert(std::pair<Key, bool>(pulo, false));
  teclasPressionadas.insert(std::pair<Key, bool>(ataque, false));
}

bool Controlador_Jogador::acharTecla(Key tecla) {
  return (teclasPressionadas.find(tecla) != teclasPressionadas.end());
}

void Controlador_Jogador::atualizarTeclasPressionadas(Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = true;

    // Considerar que a ultima tecla apertada tem prioridade
    if (tecla == direita)
      teclasPressionadas[esquerda] = false;
    else if (tecla == esquerda)
      teclasPressionadas[direita] = false;
  }
}

void Controlador_Jogador::atualizarTeclasSoltas(Key tecla) {
  if (acharTecla(tecla)) {
    teclasPressionadas[tecla] = false;
  }
}

void Controlador_Jogador::controlarJogador() {
  if (pJog) {
    // Controla movimento na horizontal
    if (teclasPressionadas[direita] && !pJog->getDanificando()) {
      pJog->andarDireita();
    } else if (teclasPressionadas[esquerda] && !pJog->getDanificando()) {
      pJog->andarEsquerda();
    } else {
      pJog->naoAndar();
    }

    if (teclasPressionadas[pulo] && !pJog->getDanificando()) {
      pJog->pular();
    }

    if (teclasPressionadas[ataque] && !pJog->getDanificando()) {
      pJog->atacar();
    }
  }
}

} // namespace Controladores
