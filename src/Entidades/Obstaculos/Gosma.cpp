#include "Entidades/Obstaculos/Gosma.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Jogador.h"

namespace Entidades::Obstaculos {
Gosma::Gosma(const sf::Vector2f &pos)
    : Obstaculo(ID::IDgosma, pos), pegajosidade(0.2) {
  std::clog << "Criando nova gosma\n";

  setTextura("/assets/Obstaculos/Gosma.png");
}
Gosma::~Gosma() {}

const float Gosma::getPegajosidade() const { return pegajosidade; }

void Gosma::executar() {}

void Gosma::obstacular(Entidade *pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Personagens::Jogador *>(pEnt)->aplicaLentidao(pegajosidade);
  }
}

void Gosma::colidir(Entidade *pEnt) { obstacular(pEnt); }

} // namespace Entidades::Obstaculos
