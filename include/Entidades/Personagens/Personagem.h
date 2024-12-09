#pragma once

#include "Entidades/Entidade.h"

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
protected:
  int hp;
  int numVidas;
  sf::Vector2<float> velocidade;

public:
  Personagem();
  Personagem(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
             const std::string &path);
  ~Personagem();

  virtual void mover();
  virtual void executar() = 0;
  void salvarDataBuffer();
};

} // namespace Personagens

} // namespace Entidades
