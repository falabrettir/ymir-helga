#pragma once
#include <map>

#include "IDs.h"
#include "State.h"

namespace Gerenciadores {
class GerenciadorEstados {
 private:
  std::map<ID, States::State *> mapStates;
  static GerenciadorEstados *instancia;
  ID idAtual;
  ID idAnterior;

 private:
  GerenciadorEstados();
  ~GerenciadorEstados();
  GerenciadorEstados(const GerenciadorEstados &) = delete;
  GerenciadorEstados &operator=(const GerenciadorEstados &) = delete;

 public:
  static GerenciadorEstados *getInstancia();
  const ID getEstadoAnterior();
  const ID getEstadoAtual();
  void mudarEstado(ID id);
  void executar();
  void inserirEstado(States::State *s);
  void removerEstado(ID id);
};
}  // namespace Gerenciadores
