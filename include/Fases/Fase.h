#pragma once

#include "Listas/ListaEntidades.h"

namespace Entidades::Personagens {
class Jogador;
} // namespace Entidades::Personagens

namespace Gerenciadores {
class Gerenciador_Colisoes;
} // namespace Gerenciadores

namespace Fases {

class Fase : public Ente {
protected:
  Gerenciadores::Gerenciador_Colisoes *pGC;
  Listas::ListaEntidades listaObstaculos;
  Listas::ListaEntidades listaPersonagens;

public:
  Fase();
  ~Fase();

  virtual void executar();
  virtual void criarObstaculos() = 0;
  virtual void criarInimigos() = 0;
  virtual void criarEntidades();
};

} // namespace Fases
