#pragma once

#include <SFML/Window/Keyboard.hpp>

class Subject;

class Observer {
private:
  Subject *pSub;

public:
  virtual ~Observer();

  void setSub(Subject *pSub);

  virtual void atualizarTeclasPressionadas(sf::Keyboard::Key tecla) = 0;
  virtual void atualizarTeclasSoltas(sf::Keyboard::Key tecla) = 0;

protected:
  Observer();
};
