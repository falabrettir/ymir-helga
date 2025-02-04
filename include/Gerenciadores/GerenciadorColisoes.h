#pragma once

#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"

namespace Gerenciadores {

class GerenciadorColisoes {
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

  sf::Vector2f verificaColisao(Entidades::Entidade *e1,
                               Entidades::Entidade *e2);

  void incluirPers(Entidades::Personagens::Personagem *pPers);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  void incluirProj(Entidades::Projetil *pProj);
  void notificaColisao(Entidades::Entidade *sender);
};

}  // namespace Gerenciadores
