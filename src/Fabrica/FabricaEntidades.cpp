#include "Fabrica/FabricaEntidades.h"

#include <SFML/System/Vector2.hpp>
#include "Entidades/Obstaculos/Plataforma.h"
#include "IDs.h"

using namespace Entidades;

namespace Fabricas {

FabricaEntidades::FabricaEntidades() : ativo(true) {}

FabricaEntidades::~FabricaEntidades() {
  ativo = false;
}

Personagens::Jogador* FabricaEntidades::criarJogador(const sf::Vector2f& pos) {
  return new Personagens::Jogador(pos);
}

Personagens::Inimigos::Esqueleto* FabricaEntidades::criarEsqueleto(
    const sf::Vector2f& pos) {
  return new Personagens::Inimigos::Esqueleto(pos);
}

Personagens::Inimigos::Slime* FabricaEntidades::criarSlime(
    const sf::Vector2f& pos) {
  return new Personagens::Inimigos::Slime(pos);
}

Personagens::Inimigos::Mago* FabricaEntidades::criarMago(
    const sf::Vector2f& pos) {
  return new Personagens::Inimigos::Mago(pos);
}

Obstaculos::Gosma* FabricaEntidades::criarGosma(const sf::Vector2f& pos) {
  return new Obstaculos::Gosma(pos);
}

Obstaculos::Espinho* FabricaEntidades::criarEspinho(const sf::Vector2f& pos) {
  return new Obstaculos::Espinho(pos);
}

Obstaculos::Plataforma* FabricaEntidades::criarParede(const sf::Vector2f& pos) {
  return new Obstaculos::Plataforma(ID::IDparede, pos);
}

}  // namespace Fabricas
