#pragma once

#include <Listas/Lista.h>

class Subject;

class Observer {
public:
  bool ativo;

public:
  virtual ~Observer();
  virtual void Atualizar(Subject *changedSubject) = 0;

protected:
  Observer();
};

class Subject {
public:
  Listas::Lista<Observer *> observadores;

public:
  virtual ~Subject();
  virtual void Inscrever(Observer *o);
  virtual void Desinscrever(Observer *o);
  virtual void Notificar();

protected:
  Subject();
};
