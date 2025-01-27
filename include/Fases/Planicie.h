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
  const int minOrc = 3;
  const int maxOrc = 5;
  int contOrc;

  const int minSlimes = 3;
  const int maxSlimes = 5;
  int contSlime;

 public:
  Planicie();
  ~Planicie();

  void executar();
  void criarEntidade(char tipoEntidade, const sf::Vector2f &pos);
  void criarMago(const sf::Vector2f &pos);
  void criarGrama(const sf::Vector2f &pos);
  void criarMadeira(const sf::Vector2f &pos);
  void criarEspinho(const sf::Vector2f &pos);
};

}  // namespace Fases
