#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

const float gravidade = 5;

class Entidade : public Ente {
protected:
  sf::Vector2<float> pos;
  sf::Vector2<float> tamanho;
  sf::Vector2<float> velocidade;
  sf::Vector2<float> gravidade;
  std::ostream *buffer;

public:
  Entidade();
  virtual ~Entidade();

  virtual void executar() = 0;
  sf::Vector2<float> getPos() const;
  void setPos(sf::Vector2<float> &novaPos);
  sf::Vector2<float> getVel() const;
  void setVel(sf::Vector2<float> &novaVel);
  sf::Vector2<float> getSize() const;
};

} // namespace Entidades
