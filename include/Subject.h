#pragma once

#include "Observer.h"
#include <SFML/Window/Keyboard.hpp>
#include <list>

class Subject {
public:
  std::list<Observer *> *observadores;

public:
  virtual ~Subject();

  virtual void inscrever(Observer *o);
  virtual void desinscrever(Observer *o);

  virtual void notificarTeclaPressionada(sf::Keyboard::Key tecla);
  virtual void notificarTeclaSolta(sf::Keyboard::Key tecla);

protected:
  Subject();
};
