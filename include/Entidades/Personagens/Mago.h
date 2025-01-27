#include "Entidades/Projetil.h"
#include "Inimigo.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens::Inimigos {
class Mago : public Inimigo {
private:
  float poder;
  Projetil *bolaDeFogo;

public:
  Mago(const sf::Vector2f &pos);
  ~Mago();
  void atacar();
  void executar();
  void aumentarPoder();
};
} // namespace Entidades::Personagens::Inimigos
