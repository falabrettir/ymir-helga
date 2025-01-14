#include "Entidades/Personagens/Skjolder.h"
#include "Controladores/ControladorJogador.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens {

Skjolder::Skjolder()
    : Entidades::Personagens::Jogador(), stamina(100.0f), furia(0),
      pContr(nullptr) {
  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");

  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);

  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
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
