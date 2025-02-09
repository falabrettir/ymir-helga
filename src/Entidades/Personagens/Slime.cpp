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
  pSprite->setTextureRect({16, 16, 16, 16});
  setTamanho({48, 48});
  setPos(pos);
}

Slime::~Slime() {}

void Slime::colidir(Entidade *pEnt) {
  if (ehJogador(pEnt->getId())) {
    dynamic_cast<Jogador *>(pEnt)->aplicaLentidao(viscosidade);
    dynamic_cast<Jogador *>(pEnt)->tomarDano(getDano(), getOlhandoEsquerda());
  } else if (ehProjetil(pEnt->getId())) {
    Personagem *pDono = dynamic_cast<Projetil *>(pEnt)->getDono();

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

  if (!getNoChao())
    cair();

  perseguir();

  if (getVisando()) {
    atacar();
  }

  mover();

  pGC->notificar(this);
}

void Slime::atacar() {}

} // namespace Entidades::Personagens::Inimigos
