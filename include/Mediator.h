#pragma once

#include "Entidades/Entidade.h"

class Mediator {
 private:
  bool ativo;

 public:
  Mediator();
  virtual ~Mediator();
  virtual void notificarColisao(Entidades::Entidade *sender) = 0;
};
