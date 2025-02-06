#include "Entidades/Personagens/Slime.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

Slime::Slime(const sf::Vector2f &pos) : Inimigo(ID::IDslime) {
  std::clog << "Criando novo slime\n";

  setTextura("/assets/Personagens/Slime.png");
}

Slime::~Slime() {}

void Slime::colidir(Entidade *pEnt) {}

void Slime::executar() {
  perseguir();
  mover();
  if (!getNoChao()) cair();
}

void Slime::atacar() {}

}  // namespace Entidades::Personagens::Inimigos
