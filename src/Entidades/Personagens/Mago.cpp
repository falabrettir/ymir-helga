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
  bolaDeFogo = nullptr;
  delete bolaDeFogo;
}
void Mago::atacar() {
  bolaDeFogo = fabProj->criarProjetil(this, poder);
  aumentarPoder();
}
void Mago::aumentarPoder() { poder *= poder; }
void Mago::executar() {
  perseguir();
  mover();
  if (getVisando() && bolaDeFogo != nullptr) atacar();
}
}  // namespace Entidades::Personagens::Inimigos
