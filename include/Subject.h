#pragma once

#include "Observer.h"
#include <list>

class Subject {
public:
  std::list<Observer *> *observadores;

public:
  virtual ~Subject();
  virtual void inscrever(Observer *o);
  virtual void desinscrever(Observer *o);
  virtual void notificar();

protected:
  Subject();
};
