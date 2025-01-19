#include "Entidades/Personagens/Skjolder.h"
#include "Controladores/ControladorJogador.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens {

Skjolder::Skjolder() : Jogador(), stamina(100.0f), furia(0) {

  setTexture("/assets/Characters(100x100)/Knight/Knight/Knight-Idle.png");

  pContr->setJog(this);

  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);
  sf::FloatRect hitbox({0.f, 0.f, 16.f, 16.f});
  setHitbox(hitbox);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
  debug.setSize(getSize());
  debug.setPosition(pSprite->getPosition());
  debug.setTexture(pTexture);
  debug.setTextureRect(sf::IntRect(0, 0, 100, 100));
  debug.setScale(1.f / 8.f, 1.f);
}

Skjolder::~Skjolder() {}

void Skjolder::atacar() {}

void Skjolder::executar() { Jogador::executar(); }

} // namespace Entidades::Personagens
