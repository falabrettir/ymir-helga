#pragma once

#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"
#include "Mediator.h"

namespace Gerenciadores {

class GerenciadorColisoes : public Mediator {
 private:
  static GerenciadorColisoes *instancia;
  std::vector<Entidades::Personagens::Personagem *> vecPers;
  std::list<Entidades::Obstaculos::Obstaculo *> listObst;
  std::set<Entidades::Projetil *> setProj;

 private:
  // Singleton
  GerenciadorColisoes();
  GerenciadorColisoes(const GerenciadorColisoes &) = delete;
  GerenciadorColisoes &operator=(const GerenciadorColisoes &) = delete;
  ~GerenciadorColisoes();

 public:
  static GerenciadorColisoes *getInstancia();

  // Interface colisao
  bool verificaColisao(const Entidades::Entidade *e1,
                       const Entidades::Entidade *e2) const;
  sf::Vector2f resolverColisao(Entidades::Entidade *e1,
                               Entidades::Entidade *e2);

  void incluirPers(Entidades::Personagens::Personagem *pPers);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  void incluirProj(Entidades::Projetil *pProj);
  void notificarColisao(Entidades::Entidade *sender);
};

}  // namespace Gerenciadores
