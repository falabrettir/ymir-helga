#include "Entidades/Personagens/Esqueleto.h"

#include <time.h>

#include <limits>

namespace Entidades::Personagens::Inimigos {
Esqueleto::Esqueleto(ID id, float visada, int dano)
    : Inimigo(id, visada, dano), forca(0.0), flecha(nullptr) {
  srand((unsigned int)time(NULL));
}
Esqueleto::~Esqueleto() {
  flecha = nullptr;
  delete flecha;
}

void Esqueleto::atacar() {
  forca = static_cast<float>(rand()) / std::numeric_limits<float>::max();
  flecha = new Projetil(this, forca);
}
void Esqueleto::executar() {
  // draw
  perseguir();
  mover();
  if (getVisando() && flecha == nullptr) atacar();
}
}  // namespace Entidades::Personagens::Inimigos
