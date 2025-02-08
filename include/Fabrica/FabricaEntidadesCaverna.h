#pragma once

#include "Entidades/Entidade.h"
#include "Fabrica/FabricaEntidades.h"
#include "Fases/Caverna.h"

namespace Fabricas {

class FabEntCaverna : public FabricaEntidades {
private:
  static FabEntCaverna *instancia;
  Fases::Caverna *pC;

private:
  FabEntCaverna(const bool mp);
  ~FabEntCaverna();
  FabEntCaverna(const FabEntCaverna &) = delete;
  FabEntCaverna &operator=(const FabEntCaverna &) = delete;

public:
  static FabEntCaverna *getInstancia(const bool mp = false);

  void setFase(Fases::Caverna *pC);

  Entidades::Obstaculos::Plataforma *criarMadeira(const sf::Vector2f &pos);
  Entidades::Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos);
  Entidades::Entidade *criarEntidade(char tipoEntidade,
                                     const sf::Vector2f &pos);
};

} // namespace Fabricas
