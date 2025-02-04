#include "Entidades/Projetil.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades {

Projetil::Projetil()
    : Entidade(ID::IDprojetil), pPersDono(nullptr), impulso(0) {}

Projetil::Projetil(Personagens::Personagem *pPersDono, int impulso)
    : Entidade(ID::IDprojetil), pPersDono(pPersDono), impulso(impulso) {
  std::clog << "Criando projetil\n";

  if (pPersDono->getId() == ID::IDesqueleto ||
      pPersDono->getId() == ID::IDjogador) {
    setTextura("/assets/Projeteis/Flecha.png");
  } else if (pPersDono->getId() == ID::IDmago) {
    setTextura("/assets/Projeteis/BolaDeFogo.png");
  }

  sf::Vector2f pos = pPersDono->getPos();
  if (pPersDono->getOlhandoEsquerda()) {
    pos.x -= 32;
  } else {
    pos.x += 32;
  }
  setPos(pos);

  sf::Vector2f vel;
  vel.x = 8 * MAXVEL;
  vel.x += vel.x * impulso;
  vel.y = -0.35;
  if (pPersDono->getOlhandoEsquerda())
    vel.x *= -1;

  setVel(vel);
}

Projetil::~Projetil() {}

int Projetil::getDano() { return getVel().x; }

Personagens::Personagem *Projetil::getDono() { return pPersDono; }

void Projetil::colidir(Entidade *pE, sf::Vector2f ds) {
  if (pE == pPersDono) {
    return;
  }

  sf::Vector2f posEntidade = pE->getPos();
  sf::Vector2f velEntidade = pE->getVel();

  if (ds.x < 0.f && ds.y < 0.f) { // Colidiu
    // Colidiu com plataforma -> deletar
    // Colidiu com um personagem -> danificar e deletar
    this->setPos({-6000, -6000});
    this->setVel({0, 0});

    if (ehPersonagem(pE->getId())) {
      dynamic_cast<Entidades::Personagens::Personagem *>(pE)->tomarDano(
          getDano(), this->getOlhandoEsquerda());
    }
  }
}

void Projetil::executar() {
  mover();
  cair();
  pGC->notificaColisao(this);
}

} // namespace Entidades
