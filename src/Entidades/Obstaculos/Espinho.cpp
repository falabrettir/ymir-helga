#include "Entidades/Obstaculos/Espinho.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f& pos)
    : Obstaculo(ID::IDespinho, pos, true), dano(50) {

  setTextura("/assets/Obstaculos/Espinho.png");
  pSprite->setTextureRect({16, 16, 16, 16});
  setTamanho({16, 16});
}

Espinho::~Espinho() {}

const int Espinho::getDano() const {
  return dano;
}

void Espinho::executar() {
  if (pGC == nullptr) {
    std::cerr << "erro: Espinho::executar() => pGC == nullptr" << std::endl;
  }
  pGC->notificar(this);
  mover();
}

void Espinho::obstacular(Entidade* pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Entidades::Personagens::Jogador*>(pEnt)->tomarDano(getDano());
  }
}

void Espinho::colidir(Entidade* pEnt) {
  if (pEnt == nullptr) {
    std::cerr << "erro: Espinho::colidir() => pEnt == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  obstacular(pEnt);
}

}  // namespace Entidades::Obstaculos
