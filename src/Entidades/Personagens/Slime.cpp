#include "Entidades/Personagens/Slime.h"

#include "Gerenciadores/GerenciadorColisoes.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

Slime::Slime(const sf::Vector2f &pos) : Inimigo(ID::IDslime) {
  std::clog << "Criando novo slime\n";

  setTextura("/assets/Personagens/Slime.png");
  setTamanho({48, 48});
}

Slime::~Slime() {}

void Slime::colidir(Entidade *pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Jogador *>(pEnt)->aplicaLentidao(viscosidade);
    dynamic_cast<Jogador *>(pEnt)->tomarDano(getDano(), getOlhandoEsquerda());
  } else if (ehPlataforma(pEnt->getId())) {
    sf::Vector2f novaPos = this->getPos();
    sf::Vector2f ds = pGC->calcOverlap(this, pEnt);
    if (ds.x < ds.y) {                         // Eixo da colisão
      if (this->getPos().x < pEnt->getPos().x) // Direção da colisao
        novaPos.x -= ds.x;                     // Colisão Esquerda => Direita
      else
        novaPos.x += ds.x; // Colisao Direita => Esquerda
      this->setVelX(0.f);
    }
    if (ds.y < ds.x) {                           // Eixo da colisão
      if (this->getPos().y < pEnt->getPos().y) { // Direção da colisão
        novaPos.y -= ds.y;                       // Caindo
        this->setNoChao(true);
      } else
        novaPos.y += ds.y;
      this->setVelY(0.f);
    }
    this->setPos(novaPos);
  }
}

void Slime::executar() {
  atualizarKnockback();
  perseguir();
  mover();
  if (!getNoChao())
    cair();
}

void Slime::atacar() {}

} // namespace Entidades::Personagens::Inimigos
