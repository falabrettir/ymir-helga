#include "Subject.h"
#include "Observer.h"
#include <list>

Subject::Subject() : observadores(new std::list<Observer *>) {}

void Subject::Inscrever(Observer *o) {
  if (observadores) {
    observadores->push_back(o);
  }
}

void Subject::Desinscrever(Observer *o) {
  if (observadores) {
    observadores->remove(o);
  }
}

void Subject::Notificar() {
  if (observadores) {
    std::list<Observer *>::iterator it;
    for (it = observadores->begin(); it != observadores->end(); it++) {
      (*it)->Atualizar();
    }
  }
}
