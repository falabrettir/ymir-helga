#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>

#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Personagens/Slime.h"

using namespace Entidades;

namespace Fases {

Caverna::Caverna() : Fase(), contEsqueletos(0), contSlimes(0) {
  criarMapa("assets/Mapas/caverna.txt");
}

Caverna::~Caverna() {}

void Caverna::executar() { Fase::executar(); }

void Caverna::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
    case 'E':
      criarEsqueleto(pos);
      break;
    case 'S':
      criarSlime(pos);
      break;
    case 'P':
      criarPedra(pos);
      break;
    case 'M':
      criarMadeira(pos);
      break;
    case 'G':
      criarGosma(pos);
      break;
    case 'J':
      criarJogador(pos);
      break;
    default:
      break;
  }
}

void Caverna::criarSlime(const sf::Vector2f &pos) {
  Personagens::Inimigos::Slime *novoSlime = new Personagens::Inimigos::Slime(pos);
  listaPersonagens.incluir(novoSlime);
}

void Caverna::criarPedra(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlataforma = new Obstaculos::Plataforma(ID::IDpedra, pos);
  listaObstaculos.incluir(novaPlataforma);
}

void Caverna::criarMadeira(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlataforma = new Obstaculos::Plataforma(ID::IDmadeira1, pos);
  listaObstaculos.incluir(novaPlataforma);
}

void Caverna::criarGosma(const sf::Vector2f &pos) {
  // TODO: Implementar depois de criar Gosma
}

};  // namespace Fases
