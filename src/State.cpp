#include "State.h"

namespace States {
State::State(ID id) : id(id) {}

State::~State() {}

const ID State::getId() const { return id; }

}  // namespace States
