#include "Entidades/Personagens/Skjolder.h"
#include "Controladores/ControladorJogador.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens {

Skjolder::Skjolder() : Jogador(), stamina(100.0f), furia(0) {

  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");

  pContr->setJog(this);

  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
  debug.setSize(getSize());
  debug.setPosition(pSprite->getPosition());
  debug.setOutlineColor(sf::Color::Red);
  debug.setOutlineThickness(1);
  debug.setFillColor(sf::Color::Transparent);
}

Skjolder::~Skjolder() {}

void Skjolder::atacar() {}

void Skjolder::executar() { Jogador::executar(); }

} // namespace Entidades::Personagens
