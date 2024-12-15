#pragma once

#include "Entidades/Entidade.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;
  int numVidas;

public:
  Personagem();
  Personagem(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
             const std::string &path);
  virtual ~Personagem();

  virtual void mover(sf::Vector2<float> mov);
  // virtual void executar() = 0;
  void salvarDataBuffer();
};

} // namespace Personagens

} // namespace Entidades
