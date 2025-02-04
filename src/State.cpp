#include "State.h"

namespace States {
State::State() : ativo(true) {}

State::~State() { ativo = false; }

const bool State::getAtivo() const { return ativo; }

void State::setAtivo(const bool ativo) { this->ativo = ativo; }

}  // namespace States
