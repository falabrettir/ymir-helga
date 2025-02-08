#include "Entidades/Obstaculos/Espinho.h"
#include "IDs.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f &pos)
    : Obstaculo(ID::IDespinho, pos, true), dano(10) {
  std::clog << "Criando novo espinho\n";

  setTextura("/assets/Obstaculos/Espinho.png");
  pSprite->setTextureRect({16, 16, 16, 16});
  setTamanho({16, 16});
}

Espinho::~Espinho() {}

const int Espinho::getDano() const { return dano; }

void Espinho::executar() {}

void Espinho::obstacular(Entidade *pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Personagens::Personagem *>(pEnt)->tomarDano(getDano());
  }
}

void Espinho::colidir(Entidade *pEnt) {
  if (pEnt) {
    obstacular(pEnt);
  }
}

} // namespace Entidades::Obstaculos
