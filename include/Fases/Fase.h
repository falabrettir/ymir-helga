#pragma once

#include <SFML/System/Vector2.hpp>

#include "Fabrica/FabricaEntidades.h"
#include "Listas/ListaEntidades.h"
#include "State.h"

namespace Gerenciadores {
class GerenciadorColisoes;
}  // namespace Gerenciadores

namespace Fases {

class Fase : public Ente, public States::State {
 protected:
  Gerenciadores::GerenciadorColisoes *pGC;
  Fabricas::FabricaEntidades *pFE;

  Listas::ListaEntidades *listaObstaculos;
  Listas::ListaEntidades *listaPersonagens;

 public:
  Fase();
  ~Fase();

  virtual void executar();
  void incluirNoColisor();
  void criarMapa(const std::string path);
};

}  // namespace Fases
