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
  bool olhandoEsquerda;

 protected:
  static Fases::Fase* pFase;

 public:
  Personagem(ID id);
  virtual ~Personagem();

  void atualizaOrientacao();
  void mover();
  void tomarDano(int dano);
  const int getDano() const;
  void setDano(const int dano);
  void setFase(Fases::Fase* fase);
  virtual void colidir(Entidade* pEnt, sf::Vector2f ds = {0, 0}) = 0;

  void setOlhandoEsquerda(bool olhandoEsquerda);
};

}  // namespace Personagens

}  // namespace Entidades
