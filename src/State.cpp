#include "State.h"

namespace States {
State::State(ID id) : ativo(true), id(id) {}

State::~State() { ativo = false; }

const bool State::getAtivo() const { return ativo; }

void State::setAtivo(const bool ativo) { this->ativo = ativo; }

const ID State::getId() const { return id; }

}  // namespace States
