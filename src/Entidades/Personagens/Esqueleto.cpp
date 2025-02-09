#include "Entidades/Personagens/Esqueleto.h"

#include <time.h>

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "Fabrica/FabricaProjeteis.h"
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades::Personagens::Inimigos {

Fabricas::FabricaProjeteis* Esqueleto::fabProj =
    Fabricas::FabricaProjeteis::getInstancia();

Esqueleto::Esqueleto(const sf::Vector2f& pos)
    : Inimigo(ID::IDesqueleto), forca(0.0), flecha(nullptr) {

  srand((unsigned int)time(NULL));
  setTextura("/assets/Personagens/Esqueleto.png");
  setPos(pos);
}

Esqueleto::~Esqueleto() {
  delete flecha;
}

void Esqueleto::atacar() {
  if (!fabProj) {
    std::cerr << "erro: Esqueleto::atacar() => fabProj == nullptr\n";
    exit(EXIT_FAILURE);
  }
  if (!pFase) {
    std::cerr << "erro: Esqueleto::atacar() => pFase == nullptr\n";
    exit(EXIT_FAILURE);
  }

  if (podeAtacar) {
    podeAtacar = false;
    forca = static_cast<float>(rand()) / std::numeric_limits<float>::max();
    flecha = fabProj->criarProjetil(this, forca);
    pFase->adicionarProjetil(flecha);
  }
}
void Esqueleto::executar() {
  Personagem::executar();

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

}  // namespace Entidades::Personagens::Inimigos
