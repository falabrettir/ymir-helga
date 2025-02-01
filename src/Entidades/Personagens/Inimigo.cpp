#include "Entidades/Personagens/Inimigo.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

std::set<Jogador *> Inimigo::setJogadores{};

Inimigo::Inimigo(ID id) : Personagem(id), visada(500.f), visando(false) {}

Inimigo::~Inimigo() {}

float Inimigo::calculaDistancia(Jogador *pJog) { return fabs(pJog->getPos().x - this->getPos().x); }

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
  setVelX(MAXVEL * 0.5);
  if (aux != nullptr) {
    sf::Vector2f pos = this->getPos();
    sf::Vector2f jogpos = aux->getPos();

    sf::Vector2f direcao = jogpos - pos;  // Fix direction
    float magnitude = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

    if (magnitude != 0) direcao /= magnitude;  // Normalize correctly

    sf::Vector2f novaVel;
    novaVel.x = direcao.x * getVel().x;
    setVelX(novaVel.x);
  }
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
