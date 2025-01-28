#pragma once

#include <SFML/System/Vector2.hpp>

#include "Fabrica/FabricaEntidades.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "Listas/ListaEntidades.h"

namespace Gerenciadores {
class Gerenciador_Colisoes;
}  // namespace Gerenciadores

namespace Fases {

class Fase : public Ente {
 protected:
  Gerenciadores::Gerenciador_Colisoes *pGC;
  Gerenciadores::Gerenciador_Input *pGI;
  Fabricas::FabricaEntidades *pFE;

  Listas::ListaEntidades listaObstaculos;
  Listas::ListaEntidades listaPersonagens;

  bool ehPrimeiroJogador;

 public:
  Fase();
  ~Fase();

  virtual void executar();
  void incluirNoColisor();
  void criarMapa(const std::string path);
};

}  // namespace Fases
