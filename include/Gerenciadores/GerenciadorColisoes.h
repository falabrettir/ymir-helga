#pragma once

#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"

namespace Gerenciadores {

class Gerenciador_Colisoes {
 private:
  static Gerenciador_Colisoes *instancia;
  std::vector<Entidades::Personagens::Personagem *> vecPers;
  std::list<Entidades::Obstaculos::Obstaculo *> listObst;
  std::set<Entidades::Projetil *> setProj;

 private:
  // Singleton
  Gerenciador_Colisoes();
  Gerenciador_Colisoes(const Gerenciador_Colisoes &) = delete;
  Gerenciador_Colisoes &operator=(const Gerenciador_Colisoes &) = delete;
  ~Gerenciador_Colisoes();

 public:
  static Gerenciador_Colisoes *getInstancia();

  sf::Vector2f verificaColisao(Entidades::Entidade *e1, Entidades::Entidade *e2);
  void incluirPers(Entidades::Personagens::Personagem *pPers);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  void incluirProj(Entidades::Projetil *pProj);

  void executar();
};

}  // namespace Gerenciadores
