#pragma once

#include "Entidades/Projetil.h"
#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {
class Esqueleto : public Inimigo {
 private:
  float forca;
  Projetil* flecha;

 public:
  Esqueleto(ID id, float visada, int dano);
  ~Esqueleto();
  void atacar();
  void executar();
};
}  // namespace Entidades::Personagens::Inimigos
