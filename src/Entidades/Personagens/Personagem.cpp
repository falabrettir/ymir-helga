#include "Entidades/Personagens/Personagem.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

namespace Entidades::Personagens {

Fases::Fase* Personagem::pFase = nullptr;

Personagem::Personagem(ID id) : Entidade(id), hp(100), dano(0) {}

Personagem::~Personagem() {}

void Personagem::setFase(Fases::Fase* fase) {
  if (!fase) {
    std::cerr << "erro: Personagem::setFase(...) => fase == nullptr\n";
    exit(EXIT_FAILURE);
  }
  pFase = fase;
}
void Personagem::tomarDano(int dano) { hp -= dano; }

void Personagem::setDano(const int dano) { this->dano = dano; }

const int Personagem::getDano() const { return dano; }

}  // namespace Entidades::Personagens
