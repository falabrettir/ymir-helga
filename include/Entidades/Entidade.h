#include "../Ente.h"
#include <SFML/System/Vector2.hpp>
#include <ostream>

namespace Entidades {
class Entidade : public Ente {
protected:
  sf::Vector2<float> pos;
  sf::Vector2<float> tamanho;

public:
  Entidade();
  Entidade(sf::Vector2<float> pos, sf::Vector2<float> tamanho);
  // std::ostream buffer;
};
} // namespace Entidades
