#pragma once

namespace States {
class State {
 private:
  bool ativo;

 public:
  State();
  virtual ~State();
  const bool getAtivo() const;
  void setAtivo(const bool ativo);
  virtual void executar() = 0;
};
}  // namespace States
