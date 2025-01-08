#include "Subject.h"
#include "Observer.h"
#include <list>

Subject::Subject() : observadores(new std::list<Observer *>) {}

void Subject::inscrever(Observer *o) {
  if (observadores) {
    observadores->push_back(o);
  }
}

void Subject::desinscrever(Observer *o) {
  if (observadores) {
    observadores->remove(o);
  }
}

void Subject::notificar() {
  if (observadores) {
    std::list<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->atualizar();
    }
  }
}
