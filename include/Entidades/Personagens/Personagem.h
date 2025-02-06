#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"

namespace Fases {
class Fase;
}

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
 private:
  int dano;
  int hp;

 protected:
  static Fases::Fase* pFase;

 public:
  Personagem(ID id);
  virtual ~Personagem();

  void tomarDano(int dano);
  const int getDano() const;
  void setDano(const int dano);
  static void setFase(Fases::Fase* fase);
  void executar();
  void colidir(Entidade* pEnt = nullptr);
};

}  // namespace Personagens

}  // namespace Entidades
