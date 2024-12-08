#pragma once

namespace Entidades {

namespace Personagens {

class Personagem {
protected:
  int hp;

public:
  Personagem();
  ~Personagem();

  virtual void mover();
  virtual void executar() = 0;
  void salvarDataBuffer();
};

} // namespace Personagens

} // namespace Entidades
