#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

const float gravidade = 5;

class Entidade : public Ente {
protected:
  sf::Vector2f pos;
  sf::Vector2f tamanho;
  sf::Vector2f velocidade;
  const sf::Vector2f gravidade;
  std::ostream *buffer;

public:
  Entidade();
  virtual ~Entidade();

  virtual void executar() = 0;

  void setVel(sf::Vector2f &novaVel);
  void setPos(sf::Vector2f &novaPos);
  sf::Vector2f getPos() const;
  sf::Vector2f getVel() const;
  sf::Vector2<float> getSize() const;
};

} // namespace Entidades
