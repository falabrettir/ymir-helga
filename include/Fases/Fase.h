#pragma once

#include "Listas/ListaEntidades.h"

namespace Entidades::Personagens {
class Jogador;
} // namespace Entidades::Personagens

namespace Gerenciadores {
class Gerenciador_Colisoes;
} // namespace Gerenciadores

namespace Fases {

class Fase {
private:
  Gerenciadores::Gerenciador_Colisoes *pGC;
  std::vector<Entidades::Personagens::Jogador> vecJog;
  Listas::ListaEntidades listaEnt;

public:
  Fase();
  ~Fase();

  virtual void executar();
  void criarPlataformas();
  void criarCenario();
  virtual void criarEntidades();
};

} // namespace Fases
