#include "Entidades/Personagens/Inimigo.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

std::set<Jogador *> Inimigo::setJogadores{};

Inimigo::Inimigo(ID id) : Personagem(id), visada(100.f), visando(false) {}

Inimigo::~Inimigo() {}

float Inimigo::calculaDistancia(Jogador *pJog) {
  return fabs(pJog->getPos().x - this->getPos().x);
}

void Inimigo::adicionarJogador(Jogador *pJog) { setJogadores.insert(pJog); }

void Inimigo::perseguir() {
  std::set<Jogador *>::iterator it = setJogadores.begin();
  Jogador *aux = nullptr;
  float atual, min = visada;

  while (it != setJogadores.end()) {
    atual = calculaDistancia(*it);
    if (atual <= min) {
      min = atual;
      aux = *it;
      visando = true;
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

const bool Inimigo::getVisando() const { return visando; }

void Inimigo::colidir(Entidade *pEnt,
                      sf::Vector2f ds) {  // nesse caso, entidade há de ser
                                          // outro inimigo ou então um jogador
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Jogador *>(pEnt)->tomarDano(getDano());
    }
  }
}

}  // namespace Entidades::Personagens::Inimigos
