#include "Observer.h"

Observer::Observer() : ativo(true) {}

const bool Observer::getAtivo() const { return ativo; }
