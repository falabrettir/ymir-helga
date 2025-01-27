#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
private:
  int dano;
  int hp;
  bool olhandoEsquerda;

public:
  Personagem(ID id);
  virtual ~Personagem();

  void atualizaOrientacao();
  void mover();
  void tomarDano(int dano);
  const int getDano() const;
  void setDano(const int dano);

  void setOlhandoEsquerda(bool olhandoEsquerda);
};

} // namespace Personagens

} // namespace Entidades
