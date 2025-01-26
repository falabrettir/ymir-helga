#pragma once

#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {
class Esqueleto : public Inimigo {
 private:
  float força;
  unsigned short int numFlechas;

 public:
  Esqueleto(ID id, float visada, int dano, int numflechas = 10);
  ~Esqueleto();
  void atacar();
  void executar();
};
}  // namespace Entidades::Personagens::Inimigos
