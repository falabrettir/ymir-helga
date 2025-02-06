#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"

namespace Fases {
class Fase;
}

namespace Entidades {

namespace Personagens {

class Personagem : public Entidades::Entidade {
private:
  int dano;
  int hp;
  bool danificando;
  bool emAnimacaoKnockback;
  float tempoKnockback;
  float duracaoKnockback;
  sf::Vector2f direcaoKnockback;
  bool invencivel;
  float tempoInvencibilidade;
  const float DURACAO_INVENCIBILIDADE = 0.4f; // 1 segundo de invencibilidade

protected:
  static Fases::Fase *pFase;

public:
  Personagem(ID id);
  virtual ~Personagem();

  void tomarDano(int dano, bool esq = true);
  const int getDano() const;
  void setDano(const int dano);
  static void setFase(Fases::Fase *fase);
  virtual void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0}) = 0;
  void setDanificando(bool danificando);
  const bool getDanificando() const;
  void atualizarKnockback();
  bool getEmAnimacaoKnockback() const { return emAnimacaoKnockback; }
  void setEmAnimacaoKnockback(bool valor) { emAnimacaoKnockback = valor; }
};

} // namespace Personagens

} // namespace Entidades
