#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Inimigo.h"
#include <SFML/System/Vector2.hpp>
namespace Inimigos {

class Slime : public Entidades::Personagens::Inimigos::Inimigo {
private:
  int lentidao;

public:
  Slime();
  ~Slime();
  void danificar(Entidades::Personagens::Jogador *pJog);
  void executar();
};
} // namespace Inimigos
