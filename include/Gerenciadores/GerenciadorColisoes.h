#pragma once
#include "Listas/ListaEntidades.h"
#include <SFML/System/Vector2.hpp>
#include <vector>
namespace Entidades {
namespace Personagens {
class Personagem;
}
} // namespace Entidades
namespace Gerenciadores {
class Gerenciador_Colisoes {
private:
  static Gerenciador_Colisoes *instancia;
  std::vector<Entidades::Personagens::Personagem *> vecChar;
  // std::list<Entidades::Obstaculos> listObst;
  // std::set<Entidades::Proj> listProj;
private:
  // Singleton
  Gerenciador_Colisoes();
  Gerenciador_Colisoes(const Gerenciador_Colisoes &) = delete;
  Gerenciador_Colisoes &operator=(const Gerenciador_Colisoes &) = delete;
  ~Gerenciador_Colisoes();

public:
  static Gerenciador_Colisoes *getInstancia();
  const sf::Vector2<float> calculaColisao(Entidades::Entidade *e1,
                                          Entidades::Entidade *e2);
  void incluirChar(Entidades::Personagens::Personagem *pPers);
  // void incluirObst(Entidades::Obstaculos* pObst);
  // void incluirProj(Entidades::Projetil* pProj);
  void executar();
};
} // namespace Gerenciadores
