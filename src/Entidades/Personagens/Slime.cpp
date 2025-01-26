#include "Entidades/Personagens/Slime.h"

#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

Slime::Slime(ID id, float visada, int dano)
    : Inimigo(ID::IDslime, visada, dano), viscosidade(0.60) {
  setTexture("/assets/Characters(100x100)/Slime/Slime/Slime-Idle.png");
}

Slime::~Slime() {}

void Slime::colidir(Entidade* pEnt, sf::Vector2f ds) {
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Jogador*>(pEnt)->aplicaLentidao(viscosidade);
      dynamic_cast<Jogador*>(pEnt)->tomarDano(getDano());
    } else if (pEnt->getId() == ID::IDprojetil) {
      if (dynamic_cast<Projetil*>(pEnt)->getDono()->getId() == ID::IDjogador) {
        tomarDano(dynamic_cast<Projetil*>(pEnt)->getDano());
      }
    }
  }
}
void Slime::executar() {
  perseguir();
  mover();
}
}  // namespace Entidades::Personagens::Inimigos
