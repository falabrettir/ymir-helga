#include "Entidades/Personagens/Skjolder.h"
#include "Controladores/ControladorJogador.h"

namespace Entidades::Personagens {

Skjolder::Skjolder()
    : Entidades::Personagens::Jogador(), stamina(100.0f), furia(0),
      pContr(nullptr) {
  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");
  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);
}
Controladores::Controlador_Jogador *Skjolder::getControlador() const {
  return pContr;
}
// TODO:
// Destrutora e metodos atacar e executar
Skjolder::~Skjolder() {}
void Skjolder::atacar() {}
void Skjolder::executar() {}

} // namespace Entidades::Personagens
