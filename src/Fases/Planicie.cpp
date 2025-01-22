#include "Fases/Planicie.h"
#include "Fases/Fase.h"

namespace Fases {

Planicie::Planicie() : Fase(), contOrc(0), contSlime(0) {
  criarMapa("assets/Mapas/planicie.txt");
}

Planicie::~Planicie() {}

void Planicie::executar() { Fase::executar(); }

void Planicie::criarEntidade(char tipoEntidade, const sf::Vector2f &pos) {
  switch (tipoEntidade) {
  case 'E':
    criarEsqueleto(pos);
    break;
  case 'O':
    criarOrc(pos);
    break;
  case 'G':
    criarGrama(pos);
    break;
  case 'M':
    criarMadeira(pos);
    break;
  case 'P':
    criarEspinho(pos);
    break;
  case 'J':
    criarJogador(pos);
    break;
  default:
    break;
  }
}

void Planicie::criarOrc(const sf::Vector2f &pos) {
  // TODO: Implementar
}

void Planicie::criarGrama(const sf::Vector2f &pos) {
  // TODO: Implementar
}

void Planicie::criarMadeira(const sf::Vector2f &pos) {
  // TODO: Implementar
}

void Planicie::criarEspinho(const sf::Vector2f &pos) {
  // TODO: Implementar
}

} // namespace Fases
