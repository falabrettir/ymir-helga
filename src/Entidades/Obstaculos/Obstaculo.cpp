#include "Entidades/Obstaculos/Obstaculo.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Gerenciadores/GerenciadorColisoes.h"

namespace Entidades::Obstaculos {

Obstaculo::Obstaculo(ID id, const sf::Vector2f& pos, const bool danoso)
    : Entidade(id), danoso(danoso) {
  if (pGC == nullptr) {
    std::cerr << "erro: Obstaculo::Obstaculo(...) => pGC == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  setNoChao(true);

  pGC->incluirObst(this);
  setPos(pos);
}

Obstaculo::~Obstaculo() {}

}  // namespace Entidades::Obstaculos
