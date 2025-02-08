#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"
#include "Obstaculo.h"

namespace Entidades::Obstaculos {
class Espinho : public Obstaculo {
private:
  int dano;

public:
  Espinho(const sf::Vector2f &pos);
  ~Espinho();

  const int getDano() const;
  void colidir(Entidade *pEnt = nullptr);

  void executar();
  void obstacular(Entidade *pEnt);
};
} // namespace Entidades::Obstaculos
