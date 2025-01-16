#pragma once
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>
namespace Gerenciadores {
class Gerenciador_Colisoes {
private:
  static Gerenciador_Colisoes *instancia;
  std::vector<Entidades::Personagens::Personagem *> vecChar;
  std::list<Entidades::Obstaculos::Obstaculo *> listObst;
  // std::set<Entidades::Proj> setProj;
private:
  // Singleton
  Gerenciador_Colisoes();
  Gerenciador_Colisoes(const Gerenciador_Colisoes &) = delete;
  Gerenciador_Colisoes &operator=(const Gerenciador_Colisoes &) = delete;
  ~Gerenciador_Colisoes();

public:
  static Gerenciador_Colisoes *getInstancia();
  sf::Vector2<float> verificaColisao(Entidades::Entidade *e1,
                                     Entidades::Entidade *e2);
  void incluirChar(Entidades::Personagens::Personagem *pPers);
  void incluirObst(Entidades::Obstaculos::Obstaculo *pObst);
  // void incluirProj(Entidades::Projetil* pProj);
  void executar();
};
} // namespace Gerenciadores
