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
