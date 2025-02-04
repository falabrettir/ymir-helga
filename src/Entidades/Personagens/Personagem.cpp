#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Personagens/Jogador.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

namespace Entidades::Personagens {

Fases::Fase *Personagem::pFase = nullptr;

Personagem::Personagem(ID id)
    : Entidade(id), hp(100), dano(0), danificando(false) {}

Personagem::~Personagem() {}

void Personagem::setFase(Fases::Fase *fase) {
  if (!fase) {
    std::cerr << "erro: Personagem::setFase(...) => fase == nullptr\n";
    exit(EXIT_FAILURE);
  }
  pFase = fase;
}
void Personagem::tomarDano(int dano) {
  hp -= dano;
  setDanificando(true);
  sf::Vector2f novaVel = getVel();
  novaVel.y += -0.1;
  setVel(novaVel);
  setNoChao(false);
}

void Personagem::setDano(const int dano) { this->dano = dano; }

const int Personagem::getDano() const { return dano; }
void Personagem::setDanificando(bool danificando) {
  this->danificando = danificando;
}
const bool Personagem::getDanificando() const { return danificando; }

} // namespace Entidades::Personagens
