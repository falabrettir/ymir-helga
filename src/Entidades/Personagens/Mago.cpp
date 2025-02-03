#include "Entidades/Personagens/Mago.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Fabrica/FabricaProjeteis.h"
#include "Fases/Fase.h"

namespace Entidades::Personagens::Inimigos {

Fabricas::FabricaProjeteis *Mago::fabProj =
    Fabricas::FabricaProjeteis::getInstancia();

Mago::Mago(const sf::Vector2f &pos)
    : Inimigo(ID::IDmago), poder(1.05), bolaDeFogo(nullptr) {
  std::clog << "Criando novo mago\n";

  setTextura("/assets/Personagens/Mago.png");
}

Mago::~Mago() { delete bolaDeFogo; }

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
  if (!bolaDeFogo) {
    bolaDeFogo = fabProj->criarProjetil(this, poder);
    pFase->adicionarProjetil(bolaDeFogo);

    aumentarPoder();
  }
}

void Mago::aumentarPoder() { poder *= poder; }

void Mago::executar() {
  perseguir();
  mover();
  if (getVisando()) atacar();
}

}  // namespace Entidades::Personagens::Inimigos
