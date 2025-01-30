#pragma once

#include "Entidades/Entidade.h"
#include "Fabrica/FabricaEntidades.h"

namespace Fabricas {

class FabEntCaverna : public FabricaEntidades {
 private:
  static FabEntCaverna *instancia;

 private:
  FabEntCaverna();
  ~FabEntCaverna();
  FabEntCaverna(const FabEntCaverna &) = delete;
  FabEntCaverna &operator=(const FabEntCaverna &) = delete;

 public:
  static FabEntCaverna *getInstancia();

  Obstaculos::Plataforma *criarMadeira(const sf::Vector2f &pos);
  Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos);
  Entidades::Entidade *criarEntidade(char tipoEntidade,
                                     const sf::Vector2f &pos);
};

}  // namespace Fabricas
