#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"

namespace Fases {
class Fase;
}

namespace Entidades {

class Projetil;

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
  const float DURACAO_INVENCIBILIDADE = 0.4f;  // 1 segundo de invencibilidade
  bool vivo;

 protected:
  static Fases::Fase* pFase;
  bool podeAtacar;
  float ultimoAtaque;

 public:
  Personagem(ID id);
  virtual ~Personagem();

  void tomarDano(int dano, bool esq = true);
  void executar();
  void atualizarKnockback();
  virtual void colidir(Entidade* pEnt = nullptr) = 0;

  // ============================================================================
  // Getters e setters
  // ============================================================================
  const int getDano() const;
  bool getEmAnimacaoKnockback() const;
  const bool getDanificando() const;

  void setDano(const int dano);
  void setEmAnimacaoKnockback(bool valor);
  void setDanificando(bool danificando);
  static void setFase(Fases::Fase* fase);
};

}  // namespace Personagens

}  // namespace Entidades
