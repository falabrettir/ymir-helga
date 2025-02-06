#pragma once

/*
  Primeira Fase:
  Criar um numero aleatorio de instancias de cada tipo de inimigo e obstaculo,
  respeitando os valores minimo e maximo
*/

#include "Fase.h"

namespace Fases {

class Caverna : public Fase {
private:
  const int minEsqueletos;
  static int contEsqueletos;

  const int minSlimes;
  static int contSlimes;

  const int minGosmas;
  static int contGosmas;

  const int minPlat;
  static int contPlat;

public:
  Caverna();
  ~Caverna();

  const int getMinEsq() const;
  const int getMinSli() const;
  const int getMinGosmas() const;
  const int getMinPlat() const;

  const static int getCont(char tipoEnt);

  void executar();
  void criarSlime(const sf::Vector2f &pos);
  void criarPedra(const sf::Vector2f &pos);
  void criarMadeira(const sf::Vector2f &pos);
  void criarGosma(const sf::Vector2f &pos);
};

} // namespace Fases
