#include "Mediator.h"

Mediator::Mediator() : ativo(true) {}

Mediator::~Mediator() { ativo = false; }
