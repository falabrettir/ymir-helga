#pragma once
#include "Entidades/Personagens/Personagem.h"
#include "Jogador.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

namespace Personagens {
namespace Inimigos {

class Inimigo : public Entidades::Personagens::Personagem {
protected:
  int nivelMadade;
  float visada;
  Entidades::Personagens::Jogador *pJ;

public:
  Inimigo();
  virtual ~Inimigo();
  void persegue();

  void salvarDataBuffer();
  // virtual void executar() = 0;
  // virtual void danificar(Entidades::Personagens::Jogador *pJog) = 0;
};

} // namespace Inimigos
} // namespace Personagens
} // namespace Entidades
