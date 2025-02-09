#include "Entidades/Obstaculos/Gosma.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Gerenciadores/GerenciadorColisoes.h"

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Jogador.h"

namespace Entidades::Obstaculos {

Gosma::Gosma(const sf::Vector2f& pos)
    : Obstaculo(ID::IDgosma, pos), pegajosidade(0.2) {
  setTextura("/assets/Obstaculos/Gosma.png");
  pSprite->setTextureRect({16, 16, 16, 16});
  setTamanho({16, 16});
}

Gosma::~Gosma() {}

const float Gosma::getPegajosidade() const {
  return pegajosidade;
}

void Gosma::executar() {
  if (pGC == nullptr) {
    std::cerr << "erro: Gosma::executar() => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  pGC->notificar(this);
}

void Gosma::obstacular(Entidade* pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Personagens::Jogador*>(pEnt)->aplicaLentidao(pegajosidade);
  }
}

void Gosma::colidir(Entidade* pEnt) {
  if (pEnt == nullptr) {
    std::cerr << "erro: Gosma::colidir() => pEnt == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  obstacular(pEnt);
}

}  // namespace Entidades::Obstaculos
