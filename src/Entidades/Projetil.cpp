#include "Entidades/Projetil.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades {

Projetil::Projetil(Personagens::Personagem* pPersDono, int impulso)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), impulso(impulso), pFase(nullptr) {
  if (pPersDono == nullptr) {
    std::cerr << "erro: Projetil::Projetil(...) => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (pPersDono->getId() == ID::IDesqueleto || pPersDono->getId() == ID::IDjogador) {
    setTextura("/assets/Projeteis/Flecha.png");
  } else if (pPersDono->getId() == ID::IDmago) {
    setTextura("/assets/Projeteis/BolaDeFogo.png");
  }

  pSprite->setTextureRect({16, 16, 16, 16});
  setTamanho({16, 16});

  // Inicializacao da posicao
  sf::Vector2f pos = pPersDono->getPos();
  if (pPersDono->getOlhandoEsquerda()) {
    pos.x -= 48;
  } else {
    pos.x += 48;
  }
  setPos(pos);

  // Inicializacao da velocidade
  sf::Vector2f vel;
  vel.x = 2 * MAXVEL;
  vel.x += vel.x * impulso;
  if (pPersDono->getOlhandoEsquerda()) vel.x *= -1;
  setVel(vel);
}

Projetil::~Projetil() {
  pFase = nullptr;
  pPersDono = nullptr;
  std::clog << "~Projetil" << std::endl;
}

int Projetil::getDano() { return std::fabs(getVel().x); }

Personagens::Personagem* Projetil::getDono() { return pPersDono; }

void Projetil::colidir(Entidade* pE) {
  if (pGC == nullptr) {
    std::cerr << "erro: Projetil::colidir() => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (pFase == nullptr) {
    std::cerr << "erro: Projetil::colidir() => pFase == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  pFase->removerProjetil(this);
}

void Projetil::executar() {
  mover();

  if (pGC == nullptr) {
    std::cerr << "erro: Projetil::executar() => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }
  pGC->notificar(this);
}

void Projetil::setFase(Fases::Fase* fase) { pFase = fase; }

}  // namespace Entidades
