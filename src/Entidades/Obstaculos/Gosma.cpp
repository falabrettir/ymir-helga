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
void Gosma::executar() { pGC->notificaColisao(this); }
void Gosma::obstacular(Entidade *pEnt) {}
void Gosma::colidir(Entidade *pEnt, sf::Vector2f ds) {
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Personagens::Jogador *>(pEnt)->aplicaLentidao(pegajosidade);
    }
  }
}
} // namespace Entidades::Obstaculos
