#pragma once
#include "Jogador.h"
#include <SFML/Graphics/RectangleShape.hpp>

namespace Entidades::Personagens {

class Skjolder : public Entidades::Personagens::Jogador {
private:
  float stamina;
  short int furia;

public:
  sf::RectangleShape debug;
  Skjolder();
  ~Skjolder();
  void atacar();
  void executar();
};

} // namespace Entidades::Personagens
