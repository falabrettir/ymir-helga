#include "Entidades/Projetil.h"

#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades {

Projetil::Projetil() : Entidade(ID::IDprojetil), pPersDono(nullptr), impulso(0) {}

Projetil::Projetil(Personagens::Personagem *pPersDono, int impulso)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), impulso(impulso) {
  sf::Vector2f vel;
  vel.x = MAXVEL;
  vel.x += vel.x * impulso;
  setVel(vel);
}

Projetil::~Projetil() {}

int Projetil::getDano() { return getVel().x; }

Personagens::Personagem *Projetil::getDono() { return pPersDono; }

void Projetil::colidir(Entidade *pE, sf::Vector2f ds) {
  sf::Vector2f posEntidade = pE->getPos();
  sf::Vector2f velEntidade = pE->getVel();

  if (ds.x < 0.f && ds.y < 0.f) {  // Colidiu
    // Colidiu com plataforma -> deletar
    // Colidiu com um personagem -> danificar e deletar
  }
}

void Projetil::executar() {}

}  // namespace Entidades
