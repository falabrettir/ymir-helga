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
  const int minEsqueletos = 3;
  const int maxEsqueletos = 5;
  int contEsqueletos;

  const int minSlimes = 3;
  const int maxSlimes = 5;
  int contSlimes;

public:
  Caverna();
  ~Caverna();

  void executar();
  void criarEntidade(char tipoEntidade, const sf::Vector2f &pos);
  void criarSlime(const sf::Vector2f &pos);
  void criarEsqueleto(const sf::Vector2f &pos);
  void criarPedra(const sf::Vector2f &pos);
  void criarMadeira(const sf::Vector2f &pos);
  void criarGosma(const sf::Vector2f &pos);
};

} // namespace Fases
