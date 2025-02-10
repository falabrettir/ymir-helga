#pragma once
#include "IDs.h"

namespace States {
class State {
 private:
  ID id;

 public:
  State(ID id);
  const ID getId() const;
  virtual ~State();
  virtual void executar() = 0;
};
}  // namespace States
