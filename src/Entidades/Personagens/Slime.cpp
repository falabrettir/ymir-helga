#include "Entidades/Personagens/Slime.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

namespace Entidades::Personagens::Inimigos {

Slime::Slime(const sf::Vector2f& pos) : Inimigo(ID::IDslime), viscosidade(0.5) {
  setTextura("/assets/Personagens/Slime.png");
  setPos(pos);
}

Slime::~Slime() {}

void Slime::colidir(Entidade* pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Jogador*>(pEnt)->aplicaLentidao(viscosidade);
    dynamic_cast<Jogador*>(pEnt)->tomarDano(getDano(), getOlhandoEsquerda());
  } else if (ehProjetil(pEnt->getId())) {
    Personagem* pDono = dynamic_cast<Projetil*>(pEnt)->getDono();

    if (pDono == nullptr) {
      std::cerr << "erro: Inimigo::colidir(...) => pDono == nullptr\n";
      exit(EXIT_FAILURE);
    }

    ID idDono = pDono->getId();
    if (ehJogador(idDono)) {
      tomarDano(pDono->getDano() + 200, pDono->getOlhandoEsquerda());
    }
  }
}

void Slime::executar() {
  atualizarKnockback();
  setDanificando(false);
  setNoChao(false);
  atacar();
  pGC->notificar(this);
  Personagem::executar();
}

void Slime::atacar() {
  atualizarKnockback();
  setDanificando(false);
  setNoChao(false);

  if (!getNoChao())
    cair();

  perseguir();

  mover();
}

}  // namespace Entidades::Personagens::Inimigos
