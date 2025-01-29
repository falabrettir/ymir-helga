#pragma once
#include <stack>

#include "State.h"

namespace Gerenciadores {
class Gerenciador_Estados {
 private:
  std::stack<States::State *> pilhaEstados;
  static Gerenciador_Estados *instancia;

 private:
  Gerenciador_Estados();
  ~Gerenciador_Estados();
  Gerenciador_Estados(const Gerenciador_Estados &) = delete;
  Gerenciador_Estados &operator=(const Gerenciador_Estados &) = delete;

 public:
  static Gerenciador_Estados *getInstancia();
  void executar();
  void pushEstado(States::State *s);
  States::State *topEstado();
  void popEstado();
};
}  // namespace Gerenciadores
