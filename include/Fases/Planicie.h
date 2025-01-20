#pragma once

/*
  Segunda Fase:
  Criar um numero aleatorio de instancias de cada tipo de inimigo e obstaculo,
  respeitando os valores minimo e maximo
*/

#include "Fase.h"

namespace Fases {

class Planicie : public Fase {
private:
  const int minOrc = 3;
  const int maxOrc = 5;
  const int minSlimes = 3;
  const int maxSlimes = 5;

public:
  Planicie();
  ~Planicie();

  void executar();
  void criarObstaculos();
  void criarInimigos();
  void criarSlimes();
  void criarOrcs();
  void criarEntidades();
};

} // namespace Fases
