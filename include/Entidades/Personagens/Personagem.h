#pragma once

#include "Entidades/Entidade.h"

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;

public:
  Personagem();
  Personagem(const std::string &path);
  ~Personagem();

  virtual void mover();
  virtual void executar() = 0;
  void salvarDataBuffer();
};

} // namespace Personagens

} // namespace Entidades
