#pragma once

#include "Entidades/Projetil.h"
#include "Inimigo.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens::Inimigos {
class Esqueleto : public Inimigo {
private:
  float forca;
  Projetil *flecha;

public:
  Esqueleto(const sf::Vector2f &pos);
  ~Esqueleto();
  void atacar();
  void executar();
};
} // namespace Entidades::Personagens::Inimigos
