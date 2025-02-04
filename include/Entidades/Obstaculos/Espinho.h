#include "Entidades/Entidade.h"
#include "Obstaculo.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Obstaculos {
class Espinho : public Obstaculo {
private:
  int dano;

public:
  Espinho(const sf::Vector2f &pos);
  ~Espinho();

  const int getDano() const;

  void executar();
  void obstacular(Entidade *pEnt);
  void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0});
};
} // namespace Entidades::Obstaculos
