#include "Entidades/Obstaculos/Espinho.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Jogador.h"

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f &pos)
    : Obstaculo(ID::IDespinho, pos, true), dano(10) {
  std::clog << "Criando novo espinho\n";

  setTextura("/assets/Obstaculos/Espinho.png");
}

Espinho::~Espinho() {}

const int Espinho::getDano() const { return dano; }

void Espinho::executar() {}

void Espinho::obstacular(Entidade *pEnt) {}

void Espinho::colidir(Entidade *pEnt) {}

}  // namespace Entidades::Obstaculos
