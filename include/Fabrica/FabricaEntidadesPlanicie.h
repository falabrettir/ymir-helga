#pragma once

#include "Fabrica/FabricaEntidades.h"

namespace Fabricas {

class FabEntPlanicie : public FabricaEntidades {
 private:
  static FabEntPlanicie *instancia;

 private:
  FabEntPlanicie();
  ~FabEntPlanicie();
  FabEntPlanicie(const FabEntPlanicie &) = delete;
  FabEntPlanicie &operator=(const FabEntPlanicie &) = delete;

 public:
  static FabEntPlanicie *getInstancia();

  Obstaculos::Plataforma *criarMadeira(const sf::Vector2f &pos);
  Obstaculos::Plataforma *criarChao(const sf::Vector2f &pos);
  void criarEntidade(char tipoEntidade, const sf::Vector2f &pos);
};

}  // namespace Fabricas
