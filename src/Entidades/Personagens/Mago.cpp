#include "Entidades/Personagens/Mago.h"
namespace Entidades::Personagens::Inimigos {
Mago::Mago() : Inimigo(ID::IDmago), poder(1.05), bolaDeFogo(nullptr) {}
Mago::~Mago() {
  bolaDeFogo = nullptr;
  delete bolaDeFogo;
}
void Mago::atacar() {
  bolaDeFogo = new Projetil(this, poder);
  aumentarPoder();
}
void Mago::aumentarPoder() { poder *= poder; }
void Mago::executar() {
  perseguir();
  mover();
  if (getVisando() && bolaDeFogo != nullptr)
    atacar();
}
} // namespace Entidades::Personagens::Inimigos
