#pragma once
namespace Entidades {
namespace Personagens {
class Jogador;
}
} // namespace Entidades
#include "Listas/ListaEntidades.h"
namespace Fases {

class Fase {
private:
  // Gerenciadores::Gerenciador_Colisoes* GC;
  std::vector<Entidades::Personagens::Jogador> vecJog;
  Listas::ListaEntidades entityList;

public:
  Fase();
  ~Fase();

  virtual void executar();
  void criarPlataformas();
  void criarCenario();
};

} // namespace Fases
