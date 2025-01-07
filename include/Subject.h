#pragma once

#include "Observer.h"
#include <list>

class Subject {
public:
  std::list<Observer *> *observadores;

public:
  virtual ~Subject();
  virtual void Inscrever(Observer *o);
  virtual void Desinscrever(Observer *o);
  virtual void Notificar();

protected:
  Subject();
};
