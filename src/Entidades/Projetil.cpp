#include "Entidades/Projetil.h"

#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades {

Projetil::Projetil() : Entidade(ID::IDprojetil), pPersDono(nullptr), dano(0) {}

Projetil::Projetil(Personagens::Personagem *pPersDono)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), dano(pPersDono->getDano()) {}

Projetil::~Projetil() {}

int Projetil::getDano() { return dano; }

Personagens::Personagem *Projetil::getDono() { return pPersDono; }

void Projetil::colidir(Entidade *pE, sf::Vector2f ds) {
  // TODO: Implementar
}

void Projetil::executar() {}

}  // namespace Entidades
