#pragma once

class Subject;

class Observer {
private:
  bool ativo;

public:
  virtual ~Observer();
  virtual void Atualizar() = 0;
  const bool getAtivo() const;

protected:
  Observer();
};
