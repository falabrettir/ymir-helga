#pragma once

#include "Fase.h"

namespace Fases {

class Caverna : public Fase {
 private:
  const int minEsq;
  static int contEsq;

  const int minSlimes;
  static int contSlimes;

  const int minEsp;
  static int contEsp;

  const int minPlat;
  static int contPlat;

 public:
  Caverna(bool mp);
  ~Caverna();

  const int getMinEsq() const;
  const int getMinSli() const;
  const int getMinEsp() const;
  const int getMinPlat() const;

  const static int getCont(char tipoEnt);
  void incrementaContadores(char tipoEnt);

  void executar();
  void criarSlime(const sf::Vector2f& pos);
  void criarPedra(const sf::Vector2f& pos);
  void criarMadeira(const sf::Vector2f& pos);
  void criarEspinho(const sf::Vector2f& pos);
};

}  // namespace Fases
