#include "Entidades/Personagens/Skjolder.h"

Skjolder::Skjolder() : Jogador(), stamina(100.0f), furia(0) {
  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
}
// TODO:
// Destrutora e metodos atacar e executar
Skjolder::~Skjolder() {}
void Skjolder::atacar() {}
void Skjolder::executar() {}
