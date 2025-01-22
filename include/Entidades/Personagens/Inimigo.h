#pragma once
#include "Entidades/Personagens/Personagem.h"
#include "Jogador.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {
namespace Inimigos {

class Inimigo : public Personagem {
protected:
  float visada;
  int dano;

public:
  Inimigo(ID id, float visada, int dano);
  virtual ~Inimigo();

  bool visando(Jogador *pJog);
  void perseguir(Jogador *pJog);
  void colidir(Entidade *pEnt, sf::Vector2f ds = sf::Vector2f({0.f, 0.f}));
  const int getDano() const;

  virtual void atacar() = 0;
  // virtual void executar() = 0;
};

} // namespace Inimigos
} // namespace Personagens
} // namespace Entidades
