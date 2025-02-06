#include "Entidades/Obstaculos/Gosma.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades::Obstaculos {
Gosma::Gosma(const sf::Vector2f &pos)
    : Obstaculo(ID::IDgosma, pos), pegajosidade(0.2) {
  std::clog << "Criando nova gosma\n";

  setTextura("/assets/Obstaculos/Gosma.png");
}
Gosma::~Gosma() {}

const float Gosma::getPegajosidade() const { return pegajosidade; }

void Gosma::executar() {}

void Gosma::obstacular(Entidade *pEnt) {}

void Gosma::colidir(Entidade *pEnt) {}

}  // namespace Entidades::Obstaculos
