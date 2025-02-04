#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Projetil.h"
#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {

class Mago : public Inimigo {
 private:
  float poder;
  Projetil *bolaDeFogo;
  static Fabricas::FabricaProjeteis *fabProj;

 public:
  Mago(const sf::Vector2f &pos);
  ~Mago();
  void atacar();
  void executar();
  void aumentarPoder();
};
}  // namespace Entidades::Personagens::Inimigos
