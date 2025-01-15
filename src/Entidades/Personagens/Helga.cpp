#include "Entidades/Personagens/Helga.h"

namespace Entidades::Personagens {

Helga::Helga() : Jogador(), numFlechas(10) {

  setPrimeiroJog(false);

  setTexture("/assets/Characters(100x100)/Archer/Archer/Archer-Idle.png");

  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);

  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
};

Helga::~Helga() {}

void Helga::atacar() {}

void Helga::executar() { Jogador::executar(); }

} // namespace Entidades::Personagens
