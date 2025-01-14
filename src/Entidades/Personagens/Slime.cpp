#include "../include/Entidades/Personagens/Slime.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Inimigos::Slime::Slime()
    : Entidades::Personagens::Inimigos::Inimigo(), lentidao(0) {
  setTexture("/assets/Characters(100x100)/Slime/Slime/Slime-Idle.png");
}
Inimigos::Slime::~Slime() {}
void Inimigos::Slime::danificar(Entidades::Personagens::Jogador *pJog) {
  std::cout << "Danificando!" << std::endl;
}
void Inimigos::Slime::executar() {
  if (pJ->getPos().x > this->getPos().x) {
    std::cout << "Perseguindo!" << std::endl;
  }
}
