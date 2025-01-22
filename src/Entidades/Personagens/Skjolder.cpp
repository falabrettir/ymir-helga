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
  sf::FloatRect hitbox({0, 0, 27.f, 18.f});
  pSprite->setTextureRect({41, 39, 27, 20});
  setHitbox(hitbox);
  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
}

Skjolder::~Skjolder() {}

void Skjolder::atacar() {}

void Skjolder::executar() { Jogador::executar(); }

} // namespace Entidades::Personagens
