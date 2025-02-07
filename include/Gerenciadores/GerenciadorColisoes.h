#pragma once

#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Mediator.h"

namespace Gerenciadores {

class GerenciadorColisoes : public Mediator {
 private:
  static GerenciadorColisoes *instancia;

  std::vector<Entidades::Personagens::Jogador *> jogadores;
  std::vector<Entidades::Personagens::Inimigos::Inimigo *> inimigos;
  std::list<Entidades::Obstaculos::Obstaculo *> obstaculos;
  std::set<Entidades::Projetil *> projeteis;

 private:
  GerenciadorColisoes();
  ~GerenciadorColisoes();
  GerenciadorColisoes(const GerenciadorColisoes &) = delete;
  GerenciadorColisoes &operator=(const GerenciadorColisoes &) = delete;

  // Funcoes para verificar colisoes de cada caso de entidade
  void verificarProj(Entidades::Entidade *pEnt);
  void verificarInim(Entidades::Entidade *pEnt);
  void verificarJog(Entidades::Entidade *pEnt);

  // Funcoes auxiliares
  float calcOverlapVert(const Entidades::Entidade *e1,
                        const Entidades::Entidade *e2) const;
  float calcOverlapHor(const Entidades::Entidade *e1,
                       const Entidades::Entidade *e2) const;
  bool colidiu(const Entidades::Entidade *e1,
               const Entidades::Entidade *e2) const;
  bool colidiuVertical(const Entidades::Entidade *e1,
                       const Entidades::Entidade *e2) const;
  bool colidiuHorizontal(const Entidades::Entidade *e1,
                         const Entidades::Entidade *e2) const;

  void limparEntidades();

  // ============================================================================
  // Interface publica
  // ============================================================================

 public:
  static GerenciadorColisoes *getInstancia();

  void notificar(Entidades::Entidade *sender);

  sf::Vector2f calcOverlap(const Entidades::Entidade *e1,
                           const Entidades::Entidade *e2) const;

  void incluirJog(Entidades::Personagens::Jogador *pJog);
  void incluirInim(Entidades::Personagens::Inimigos::Inimigo *pInim);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  void incluirProj(Entidades::Projetil *pProj);
  void removerEnt(Entidades::Entidade *pEnt);
};

}  // namespace Gerenciadores
