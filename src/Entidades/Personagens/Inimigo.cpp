#include "Entidades/Personagens/Inimigo.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

Inimigo::Inimigo(ID id, float visada, int dano, bool visando)
    : Personagem(id), visada(visada), dano(dano), pJogs() {
  pJogs.clear();
}

Inimigo::~Inimigo() { pJogs.clear(); }

float Inimigo::calculaDistancia(Jogador *pJog) { return fabs(pJog->getPos().x - this->getPos().x); }

void Inimigo::perseguir() {
  std::set<Jogador *>::iterator it = pJogs.begin();
  Jogador *aux = nullptr;
  float atual, min = visada;
  while (it != pJogs.end()) {
    atual = calculaDistancia(*it);
    if (atual <= min) {
      min = atual;
      aux = *it;
    }
    ++it;
  }
  sf::Vector2f pos = this->getPos();
  sf::Vector2f jogpos = aux->getPos();

  sf::Vector2f direcao = pos - jogpos;
  float abs = std::sqrt(direcao.x * direcao.x);

  if (abs != 0) direcao /= abs;
  sf::Vector2f novaVel = sf::Vector2f({0, 0});
  novaVel.x = direcao.x * getVel().x;
  setVel(novaVel);
}

const int Inimigo::getDano() const { return dano; }

void Inimigo::colidir(Entidade *pEnt,
                      sf::Vector2f ds) {  // nesse caso, entidade há de ser outro
                                          // inimigo ou então um jogador
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Jogador *>(pEnt)->tomarDano(dano);
      // TODO:
      // dar um jumpsons p tras??
    } else if (pEnt->getId() == ID::IDprojetil) {
      if (dynamic_cast<Projetil *>(pEnt)->getDono()->getId == ID::IDjogador) {
        tomarDano(dynamic_cast<Projetil *>(pEnt)->getDano());
      }
    }
  }
}
}  // namespace Entidades::Personagens::Inimigos
