#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Inimigo.h"
#include <SFML/System/Vector2.hpp>
namespace Inimigos {

class Slime : public Entidades::Personagens::Inimigos::Inimigo {
private:
  int lentidao;

public:
  Slime();
  Slime(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
        const std::string &path, Entidades::Personagens::Jogador *pJog);
  ~Slime();
  void danificar(Entidades::Personagens::Jogador *pJog);
  void executar();
};
} // namespace Inimigos
