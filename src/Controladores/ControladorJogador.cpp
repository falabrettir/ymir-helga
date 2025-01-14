#include "Controladores/ControladorJogador.h"
#include "Entidades/Personagens/Jogador.h"
#include "Observer.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <utility>
#define VEL 0.3

namespace Controladores {

// Constroi com controles padrao (WASD+Space)
Controlador_Jogador::Controlador_Jogador() : pJog(nullptr), Observer() {
  teclasPressionadas.clear();
  setControles();
}

Controlador_Jogador::~Controlador_Jogador() {
  pJog = nullptr;
  teclasPressionadas.clear();
}

void Controlador_Jogador::setJog(Entidades::Personagens::Jogador *pJog) {
  if (pJog) {
    this->pJog = pJog;
  }
}

// TODO:
// Apos criar classes para Jogador1 e Jogador2, otimizar essa funcao
void Controlador_Jogador::setControles(Key direita, Key esquerda, Key pulo,
                                       Key ataque) {
  this->direita = direita;
  teclasPressionadas.insert(std::pair<Key, bool>(direita, false));

  this->esquerda = esquerda;
  teclasPressionadas.insert(std::pair<Key, bool>(esquerda, false));

  this->pulo = pulo;
  teclasPressionadas.insert(std::pair<Key, bool>(pulo, false));

  this->ataque = ataque;
  teclasPressionadas.insert(std::pair<Key, bool>(ataque, false));
}

void Controlador_Jogador::atualizarTeclasPressionadas(Key tecla) {
  if (teclasPressionadas.find(tecla) != teclasPressionadas.end()) {

    teclasPressionadas[tecla] = true;

    // Considerar que a ultima tecla de movimento apertada tem prioridade
    if (tecla == direita) {
      teclasPressionadas[esquerda] = false;
    } else if (tecla == esquerda) {
      teclasPressionadas[direita] = false;
    }
  }
}

void Controlador_Jogador::atualizarTeclasSoltas(Key tecla) {
  if (teclasPressionadas.find(tecla) != teclasPressionadas.end()) {
    teclasPressionadas[tecla] = false;
  }
}

// TODO:
void Controlador_Jogador::controlarJogador() {
  if (pJog) {
    sf::Vector2<float> mov(0.f, 0.f);
    std::clog << "Passei aqui" << std::endl;
    if (teclasPressionadas[direita]) {
      std::clog << "Movendo para direita" << std::endl;
      mov.x = VEL;
    } else if (teclasPressionadas[esquerda]) {
      mov.x = -VEL;
    }
    if (teclasPressionadas[pulo]) {
      mov.y = -VEL;
    }
    pJog->setVel(mov);
    pJog->mover();
    //
    // if (teclasPressionadas[ataque]) {
    //   pJog->atacar();
    // }
  }
}

} // namespace Controladores
