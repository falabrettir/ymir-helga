#include "Entidades/Personagens/Helga.h"

namespace Entidades::Personagens {

Helga::Helga() : Jogador(), numFlechas(10) {

  setTexture("/assets/Characters(100x100)/Archer/Archer/Archer-Idle.png");

  setPrimeiroJog(false);

  pContr->setJog(this);

  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);
  sf::FloatRect hitbox({0, 0, 27.f, 18.f});
  pSprite->setTextureRect({41, 39, 27, 20});
  setHitbox(hitbox);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
};

Helga::~Helga() {}

void Helga::atacar() {}

void Helga::executar() { Jogador::executar(); }

} // namespace Entidades::Personagens
