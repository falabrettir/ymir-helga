#include "Subject.h"
#include "Observer.h"
#include <set>

Subject::Subject() : observadores(nullptr) {}
Subject::~Subject() {}

void Subject::inscrever(Observer *o) {
  if (!observadores) {
    observadores = new std::set<Observer *>();
  }
  observadores->insert(o);
}

void Subject::desinscrever(Observer *o) {
  if (observadores) {
    observadores->erase(o);
  }
}

void Subject::notificarTeclaPressionada(sf::Keyboard::Key tecla) {
  if (observadores) {
    std::set<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->atualizarTeclasPressionadas(tecla);
    }
  }
}

void Subject::notificarTeclaSolta(sf::Keyboard::Key tecla) {
  if (observadores) {
    std::set<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->atualizarTeclasSoltas(tecla);
    }
  }
}
