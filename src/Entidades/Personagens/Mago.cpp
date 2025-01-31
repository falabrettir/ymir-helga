#include "Entidades/Personagens/Mago.h"

#include <SFML/System/Vector2.hpp>

#include "Fabrica/FabricaFireball.h"

namespace Entidades::Personagens::Inimigos {

Fabricas::FabricaProjeteis *Mago::fabProj =
    Fabricas::FabricaFireball::getInstancia();

Mago::Mago(const sf::Vector2f &pos)
    : Inimigo(ID::IDmago), poder(1.05), bolaDeFogo(nullptr) {
  setTextura("/assets/Personagens/Mago.png");
}

Mago::~Mago() {
  delete bolaDeFogo;
  bolaDeFogo = nullptr;
}

void Mago::atacar() {
  if (fabProj) {
    bolaDeFogo = fabProj->criarProjetil(this, poder);
    aumentarPoder();
  } else {
    exit(EXIT_FAILURE);
  }
}

void Mago::aumentarPoder() { poder *= poder; }

void Mago::executar() {
  perseguir();
  mover();
  if (getVisando() && bolaDeFogo) atacar();
}

}  // namespace Entidades::Personagens::Inimigos
