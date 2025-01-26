#include "Entidades/Personagens/Esqueleto.h"

#include <time.h>

#include <limits>

#include "Entidades/Projetil.h"

namespace Entidades::Personagens::Inimigos {
Esqueleto::Esqueleto(ID id, float visada, int dano, int numFlechas)
    : Inimigo(id, visada, dano), força(0.0) {
  srand((unsigned int)time(NULL));
}
Esqueleto::~Esqueleto() {}

void Esqueleto::atacar() {
  força = static_cast<float>(rand()) / std::numeric_limits<float>::max();
  // TODO:
  // criar projetil e implementar um timeout pros ataques;
  numFlechas--;
}
}  // namespace Entidades::Personagens::Inimigos
