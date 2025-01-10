#include "Entidades/Personagens/Skjolder.h"
#include "Controladores/ControladorJogador.h"

Skjolder::Skjolder() : Jogador(), stamina(100.0f), furia(0), pCont(nullptr) {
  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
  pCont = new Controladores::Controlador_Jogador();
  pCont->setJog(this);
}
Controladores::Controlador_Jogador *Skjolder::getControlador() const {
  return pCont;
}
// TODO:
// Destrutora e metodos atacar e executar
Skjolder::~Skjolder() {}
void Skjolder::atacar() {}
void Skjolder::executar() {}
