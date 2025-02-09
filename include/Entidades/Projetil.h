#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"
#include "Entidades/Personagens/Personagem.h"

namespace Entidades {

class Projetil : public Entidade {
 private:
  Personagens::Personagem* pPersDono;
  Fases::Fase* pFase;
  int impulso;

 public:
  Projetil(Personagens::Personagem* pPersDono, int impulso = 0);
  ~Projetil();

  int getDano();
  Personagens::Personagem* getDono();
  void colidir(Entidade* pEnt = nullptr);
  void executar();
  void setFase(Fases::Fase* fase);
};

}  // namespace Entidades
