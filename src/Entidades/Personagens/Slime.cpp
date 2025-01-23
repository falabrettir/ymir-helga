#include "../include/Entidades/Personagens/Slime.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "IDs.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Entidades::Personagens::Inimigos {

// FIX: Construtora de Inimigo
Slime::Slime() : Inimigo(ID::IDslime), lentidao(0) {
  setTexture("/assets/Characters(100x100)/Slime/Slime/Slime-Idle.png");
}

Slime::~Slime() {}
void Inimigos::Slime::danificar(Entidades::Personagens::Jogador *pJog) {
  std::cout << "Danificando!" << std::endl;
}

void Slime::executar() {
  // FIX: undeclared identifier pJ
  if (pJ->getPos().x > this->getPos().x) {
    std::cout << "Perseguindo!" << std::endl;
  }
}

} // namespace Entidades::Personagens::Inimigos
