#pragma once
#include <SFML/System/Vector2.hpp>

#include "Entidades/Personagens/Personagem.h"
#include "Jogador.h"

namespace Entidades::Personagens::Inimigos {

class Inimigo : public Personagem {
 protected:
  float visada;
  bool visando;
  static std::set<Jogador*> setJogadores;

 public:
  Inimigo(ID id);
  virtual ~Inimigo();

  float calculaDistancia(Jogador* pJogs);
  void perseguir();
  void colidir(Entidade* pEnt = nullptr);
  const bool getVisando() const;
  static void resetJogs();

  static void adicionarJogador(Jogador* pJog);

  virtual void atacar() = 0;
  virtual void executar() = 0;
};

}  // namespace Entidades::Personagens::Inimigos
