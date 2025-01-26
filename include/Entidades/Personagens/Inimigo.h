#pragma once
#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Personagem.h"
#include "Jogador.h"

namespace Entidades::Personagens::Inimigos {

class Inimigo : public Personagem {
 protected:
  float visada;
  std::set<Jogador *> pJogs;
  bool visando;

 public:
  Inimigo(ID id, float visada, bool visando = false);
  virtual ~Inimigo();

  float calculaDistancia(Jogador *pJogs);
  void perseguir();
  virtual void colidir(Entidade *pEnt, sf::Vector2f ds = sf::Vector2f({0.f, 0.f}));
  const bool getVisando() const;

  virtual void atacar() = 0;
  virtual void executar() = 0;
};

}  // namespace Entidades::Personagens::Inimigos
