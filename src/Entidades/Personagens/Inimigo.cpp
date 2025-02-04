#include "Entidades/Personagens/Inimigo.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

std::set<Jogador *> Inimigo::setJogadores{};

Inimigo::Inimigo(ID id) : Personagem(id), visada(50.f), visando(false) {}

Inimigo::~Inimigo() {}

float Inimigo::calculaDistancia(Jogador *pJog) {
  return fabs(pJog->getPos().x - this->getPos().x);
}

void Inimigo::adicionarJogador(Jogador *pJog) { setJogadores.insert(pJog); }

void Inimigo::perseguir() {
  std::set<Jogador *>::iterator it = setJogadores.begin();
  Jogador *aux = nullptr;
  float atual, min = visada;
  visando = false; // Reset targeting flag

  // Check for players in sight
  while (it != setJogadores.end()) {
    atual = calculaDistancia(*it);
    if (atual <= min) {
      min = atual;
      aux = *it;
      visando = true;
    }
    ++it;
  }

  // If targeting player, chase them
  if (aux != nullptr) {
    setVelX(MAXVEL * 0.5);
    sf::Vector2f pos = this->getPos();
    sf::Vector2f jogpos = aux->getPos();
    sf::Vector2f direcao = jogpos - pos;
    float magnitude = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (magnitude != 0)
      direcao /= magnitude;
    sf::Vector2f novaVel;
    novaVel.x = direcao.x * getVel().x;
    setVelX(novaVel.x);
  } else { // movimento aleatório
    static float moveTimer = 0.0f;
    static int direcao = 1;
    static float mudarIntervalo = (rand() % 20 + 10) / 10.0f; // 1-3 seconds

    moveTimer += 0.016f;

    // Random chance to change direction each frame (10%)
    if ((rand() % 100) < 10 || moveTimer >= mudarIntervalo) {
      direcao = (rand() % 2) * 2 - 1; // Generates either -1 or 1
      moveTimer = 0.0f;
      mudarIntervalo = (rand() % 20 + 10) / 10.0f; // New random interval
    }

    setVelX(MAXVEL * 0.3 * direcao);
  }
}
const bool Inimigo::getVisando() const { return visando; }

void Inimigo::colidir(Entidade *pEnt,
                      sf::Vector2f ds) { // nesse caso, entidade há de ser
                                         // outro inimigo ou então um jogador
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDjogador) {
      dynamic_cast<Jogador *>(pEnt)->tomarDano(getDano(),
                                               this->getOlhandoEsquerda());
    }
  }
}

} // namespace Entidades::Personagens::Inimigos
