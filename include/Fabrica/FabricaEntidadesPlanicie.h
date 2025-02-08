#pragma once

#include "Entidades/Entidade.h"
#include "Fabrica/FabricaEntidades.h"
#include "Fases/Planicie.h"

namespace Fabricas {

class FabEntPlanicie : public FabricaEntidades {
private:
  static FabEntPlanicie *instancia;
  Fases::Planicie *pP;

private:
  FabEntPlanicie();
  ~FabEntPlanicie();
  FabEntPlanicie(const FabEntPlanicie &) = delete;
  FabEntPlanicie &operator=(const FabEntPlanicie &) = delete;

public:
  static FabEntPlanicie *getInstancia();

  void setFase(Fases::Planicie *pP);

  Entidades::Obstaculos::Plataforma *criarMadeira(const sf::Vector2f &pos);
  Entidades::Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos);
  Entidades::Entidade *criarEntidade(char tipoEntidade,
                                     const sf::Vector2f &pos);
};

} // namespace Fabricas
