#include "Entidades/Personagens/Mago.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Entidades/Personagens/Personagem.h"
#include "Fabrica/FabricaProjeteis.h"
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"
namespace Entidades::Personagens::Inimigos {

Fabricas::FabricaProjeteis* Mago::fabProj =
    Fabricas::FabricaProjeteis::getInstancia();

Mago::Mago(const sf::Vector2f& pos)
    : Inimigo(ID::IDmago), poder(1.000005), bolaDeFogo(nullptr) {

  setTextura("/assets/Personagens/Mago.png");

  setPos(pos);
}

Mago::~Mago() {
  bolaDeFogo = nullptr;
}

void Mago::atacar() {
  if (!fabProj) {
    std::cerr << "erro: Mago::atacar() => fabProj == nullptr\n";
    exit(EXIT_FAILURE);
  }
  if (!pFase) {
    std::cerr << "erro: Mago::atacar() => pFase == nullptr\n";
    exit(EXIT_FAILURE);
  }

  // Ataca apenas se a ultima bola de fogo ja colidiu
  if (podeAtacar) {
    podeAtacar = false;
    pFase->adicionarProjetil(fabProj->criarProjetil(this, poder));

    aumentarPoder();
  }
}

void Mago::aumentarPoder() {
  poder *= poder;
}

void Mago::executar() {

  atualizarKnockback();
  setDanificando(false);
  setNoChao(false);

  perseguir();

  if (getVisando()) {
    atacar();
  }

  mover();

  pGC->notificar(this);
  Personagem::executar();
}

}  // namespace Entidades::Personagens::Inimigos
