#include "Entidades/Obstaculos/Gosma.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Obstaculos {
Gosma::Gosma(const sf::Vector2f &pos)
    : Obstaculo(ID::IDgosma, pos), pegajosidade(0.6) {
  // TODO: aplicar texturas e posicao
  setTextura("");
  setPos();
}
Gosma::~Gosma() {}

const float Gosma::getPegajosidade() const { return pegajosidade; }
void Gosma::executar() {}
void Gosma::obstacular(Entidade *pEnt) {}
void Gosma::colidir(Entidade *pEnt, sf::Vector2f ds) {
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Personagens::Jogador *>(pEnt)->aplicaLentidao(pegajosidade);
    }
  }
}
} // namespace Entidades::Obstaculos
