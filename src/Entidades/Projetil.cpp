#include "Entidades/Projetil.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades {

Projetil::Projetil()
    : Entidade(ID::IDprojetil), pPersDono(nullptr), impulso(0) {
  pGC->incluirProj(this);
}

Projetil::Projetil(Personagens::Personagem *pPersDono, int impulso)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), impulso(impulso) {
  std::clog << "Criando projetil\n";

  if (pPersDono->getId() == ID::IDesqueleto ||
      pPersDono->getId() == ID::IDjogador) {
    setTextura("/assets/Projeteis/Flecha.png");
  } else if (pPersDono->getId() == ID::IDmago) {
    setTextura("/assets/Projeteis/BolaDeFogo.png");
  }

  pSprite->setTextureRect({16, 16, 16, 16});
  tamanho = {16, 16};

  sf::Vector2f pos = pPersDono->getPos();
  if (pPersDono->getOlhandoEsquerda()) {
    pos.x -= 32;
  } else {
    pos.x += 32;
  }
  setPos(pos);

  sf::Vector2f vel;
  vel.x = 2 * MAXVEL;
  vel.x += vel.x * impulso;
  // vel.y = -0.35;
  if (pPersDono->getOlhandoEsquerda()) vel.x *= -1;

  setVel(vel);
}

Projetil::~Projetil() { pFase = nullptr; }

int Projetil::getDano() { return getVel().x; }

Personagens::Personagem *Projetil::getDono() { return pPersDono; }

void Projetil::colidir(Entidade *pE) {
  // Fazer com que a fase tire o projetil da sua lista
  // mesma coisa pro pgc
  pPersDono->apagarProj();
  pGC->removerEnt(this);
  pFase->removerProjetil(this);
}

void Projetil::executar() {
  mover();
  // cair();
  pGC->notificar(this);
}

void Projetil::setFase(Fases::Fase *fase) { pFase = fase; }

}  // namespace Entidades
