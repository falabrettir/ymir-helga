#include "Entidades/Projetil.h"

#include "IDs.h"

namespace Entidades {

Projetil::Projetil() : Entidade(ID::IDprojetil), pPersDono(nullptr), dano(0) {}

Projetil::Projetil(Personagens::Personagem *pPersDono)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), dano(0) {}

Projetil::~Projetil() {}

void Projetil::executar() {}
}  // namespace Entidades
