#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Projetil.h"
#include "Fabrica/FabricaProjeteis.h"
#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {
class Esqueleto : public Inimigo {
 private:
  float forca;
  Projetil *flecha;
  static Fabricas::FabricaProjeteis *fabProj;

 public:
  Esqueleto(const sf::Vector2f &pos);
  ~Esqueleto();
  void atacar();
  void executar();
};
}  // namespace Entidades::Personagens::Inimigos
