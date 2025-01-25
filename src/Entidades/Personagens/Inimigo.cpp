#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Entidades::Personagens::Inimigos {

Inimigo::Inimigo(ID id, float visada, int dano)
    : Personagem(id), visada(visada), dano(dano) {}

Inimigo::~Inimigo() {}

bool Inimigo::visando(Jogador *pJog) {
  return fabs(pJog->getPos().x - this->getPos().x) <= visada;
}

void Inimigo::perseguir(Jogador *pJog) {
  if (visando(pJog)) {
    sf::Vector2f pos = this->getPos();
    sf::Vector2f jogpos = pJog->getPos();

    sf::Vector2f direcao = pos - jogpos;
    float abs = std::sqrt(direcao.x * direcao.x);

    if (abs != 0)
      direcao /= abs;
    sf::Vector2f novaVel = sf::Vector2f({0, 0});
    novaVel.x = direcao.x * getVel().x;
    setVel(novaVel);
  }
}

const int Inimigo::getDano() const { return dano; }

void Inimigo::colidir(Entidade *pEnt,
                      sf::Vector2f ds) { // nesse caso, entidade há de ser outro
                                         // inimigo ou então um jogador
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Jogador *>(pEnt)->tomarDano(dano);
      // TODO:
      // dar um jumpsons p tras??
    } else if (pEnt->getId() == ID::projetil) {
      if (pEnt->getDono() == ID::IDjogador) {
        tomarDano(pEnt->getDano());
      }
    }
  }
}

} // namespace Entidades::Personagens::Inimigos
