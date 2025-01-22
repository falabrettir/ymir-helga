#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
private:
  int hp;
  bool olhandoEsquerda;

public:
  Personagem(ID id);
  void atualizaOrientacao();
  virtual ~Personagem();

  virtual void mover();
  void tomarDano(int dano);

  void setOlhandoEsquerda(bool olhandoEsquerda);
};

} // namespace Personagens

} // namespace Entidades
