#include "Subject.h"
#include "Observer.h"
#include <list>

Subject::Subject() : observadores(nullptr) {}
Subject::~Subject() {}

void Subject::inscrever(Observer *o) {
  if (!observadores) {
    observadores = new std::list<Observer *>();
  }

  observadores->push_back(o);
}

void Subject::desinscrever(Observer *o) {
  if (observadores) {
    observadores->remove(o);
  }
}

void Subject::notificarTeclaPressionada(sf::Keyboard::Key tecla) {
  if (observadores) {
    std::list<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->atualizarTeclasPressionadas(tecla);
    }
  }
}

void Subject::notificarTeclaSolta(sf::Keyboard::Key tecla) {
  if (observadores) {
    std::list<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->atualizarTeclasSoltas(tecla);
    }
  }
}
