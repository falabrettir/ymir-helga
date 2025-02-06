#pragma once

/*
  Segunda Fase:
  Criar um numero aleatorio de instancias de cada tipo de inimigo e obstaculo,
  respeitando os valores minimo e maximo
*/

#include <SFML/System/Vector2.hpp>

#include "Fase.h"

namespace Fases {

class Planicie : public Fase {
private:
  const int minMago;
  static int contMago;

  const int minEsq;
  static int contEsq;

  const int minGosma;
  static int contGosma;

  const int minPlat;
  static int contPlat;

public:
  Planicie();
  ~Planicie();

  const int getMinEsq() const;
  const int getMinMago() const;
  const int getMinGosma() const;
  const int getMinPlat() const;

  const static int getCont(char tipoEnt);
  void incrementaContadores(char tipoEnt);

  void executar();
  void criarMago(const sf::Vector2f &pos);
  void criarGrama(const sf::Vector2f &pos);
  void criarMadeira(const sf::Vector2f &pos);
  void criarEspinho(const sf::Vector2f &pos);
};

} // namespace Fases
