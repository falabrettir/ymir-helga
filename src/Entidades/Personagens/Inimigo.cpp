#include "../include/Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades;

Personagens::Inimigos::Inimigo::Inimigo(int id)
    : Personagem(id), visada(0.f), nivelMadade(0), pJ(nullptr) {}
Personagens::Inimigos::Inimigo::~Inimigo() {}
void Personagens::Inimigos::Inimigo::salvarDataBuffer() {}
void Personagens::Inimigos::Inimigo::persegue() {
  sf::Vector2<float> pos = getPos();
  sf::Vector2<float> posJ = pJ->getPos();
  sf::Vector2<float> vel = getVel();
  sf::Vector2<float> mov;
  mov.x = 0.0;
  mov.y = 0.0;
  if (pos.x <= posJ.x) {
    mov.x = vel.x;
  }
  if (pos.x >= posJ.x) {
    mov.x = -vel.x;
  }
  if (pos.y >= posJ.y) {
    mov.y = -vel.y;
  }
  if (pos.y <= posJ.y) {
    mov.y = vel.y;
  }
  mov.x -= 0.05;
  mov.y -= 0.05;
  // mover(mov);
}
