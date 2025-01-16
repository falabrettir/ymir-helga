#pragma once
#include "Listas/ListaEntidades.h"
#include <vector>

namespace Entidades::Personagens {
class Jogador;
} // namespace Entidades::Personagens

namespace Fases {

class Fase {
private:
  // Gerenciadores::Gerenciador_Colisoes* GC;
  std::vector<Entidades::Personagens::Jogador> vecJog;
  Listas::ListaEntidades listaEntidades;

public:
  Fase();
  ~Fase();

  void criarPlataformas();
  void criarCenario();
  virtual void executar();
};

} // namespace Fases
