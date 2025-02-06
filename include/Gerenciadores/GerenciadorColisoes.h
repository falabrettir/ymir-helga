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
  // Singleton
  static GerenciadorColisoes *instancia;

  std::vector<Entidades::Personagens::Jogador *> jogadores;
  std::vector<Entidades::Personagens::Inimigos::Inimigo *> inimigos;
  std::list<Entidades::Obstaculos::Obstaculo *> obstaculos;
  std::set<Entidades::Projetil *> projeteis;

 private:
  // Singleton
  GerenciadorColisoes();
  GerenciadorColisoes(const GerenciadorColisoes &) = delete;
  GerenciadorColisoes &operator=(const GerenciadorColisoes &) = delete;
  ~GerenciadorColisoes();

 public:
  // Singleton
  static GerenciadorColisoes *getInstancia();

  void executar();

  // Interface colisao

  void verificarColisoes();
  void verificarColisoesProjeteis();
  void verificarColisoesPersonagens();

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

  void resolverColisao(Entidades::Entidade *e1, Entidades::Entidade *e2);

  void notificar(Entidades::Entidade *sender);

  // TODO: Alterar a Fase para adicionar inimigos e jogadores
  void limparEntidades();
  void incluirJog(Entidades::Personagens::Jogador *pJog);
  void incluirInim(Entidades::Personagens::Inimigos::Inimigo *pInim);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  void incluirProj(Entidades::Projetil *pProj);
};

}  // namespace Gerenciadores
