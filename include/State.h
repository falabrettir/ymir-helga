#pragma once
#include "IDs.h"

namespace States {
class State {
 private:
  bool ativo;
  ID id;

 public:
  State(ID id);
  const ID getId() const;
  virtual ~State();
  const bool getAtivo() const;
  void setAtivo(const bool ativo);
  virtual void executar() = 0;
};
}  // namespace States
