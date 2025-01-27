#include "Fases/Planicie.h"

#include "Entidades/Obstaculos/Plataforma.h"
#include "Fases/Fase.h"
#include "IDs.h"

using namespace Entidades;

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) { criarMapa("assets/Mapas/planicie.txt"); }

Planicie::~Planicie() {}

void Planicie::executar() { Fase::executar(); }

void Planicie::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
    case 'E':
      criarEsqueleto(pos);
      break;
    case 'W':
      criarMago(pos);
      break;
    case 'G':
      criarGrama(pos);
      break;
    case 'M':
      criarMadeira(pos);
      break;
    case 'S':
      criarEspinho(pos);
      break;
    case 'J':
      criarJogador(pos);
      break;
    default:
      break;
  }
}

void Planicie::criarMago(const sf::Vector2f &pos) {
  // TODO: Implementar depois de criar Mago
}

void Planicie::criarGrama(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlataforma = new Obstaculos::Plataforma(ID::IDgrama, pos);
  listaObstaculos.incluir(novaPlataforma);
}

void Planicie::criarMadeira(const sf::Vector2f &pos) {
  Obstaculos::Plataforma *novaPlataforma = new Obstaculos::Plataforma(ID::IDmadeira2, pos);
  listaObstaculos.incluir(novaPlataforma);
}

void Planicie::criarEspinho(const sf::Vector2f &pos) {
  // TODO: Implementar depois de criar Espinho
}

}  // namespace Fases
