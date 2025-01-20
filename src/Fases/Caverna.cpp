#include "Fases/Caverna.h"

namespace Fases {

Caverna::Caverna() {
  criarEntidades();
  criarInimigos();
}

Caverna::~Caverna() {}

void Caverna::executar() {
  // TODO: Chamar as funcoes 'executar' de todas as entidades
}

void Caverna::criarObstaculos() {
  // TODO: passar como parametro o tipo de obstaculo e posicao
}

void Caverna::criarInimigos() {
  criarSlimes();
  criarEsqueletos();
}

void Caverna::criarSlimes() {}

void Caverna::criarEsqueletos() {}

void Caverna::criarEntidades() {
  criarObstaculos();
  criarInimigos();
}

}; // namespace Fases
