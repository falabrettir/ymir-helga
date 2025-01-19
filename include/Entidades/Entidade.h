#include "Ente.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Entidades {

const float gravidade = 5;

class Entidade : public Ente {
private:
  sf::Vector2f pos;
  const sf::Vector2f gravidade;
  sf::Vector2f tamanho;
  bool noChao;
  std::ostream *buffer;

protected:
  sf::Vector2f velocidade;
  sf::FloatRect hitbox;

public:
  Entidade();
  virtual ~Entidade();

  void setVel(sf::Vector2f novaVel);
  void setVelX(float velX);
  void setVelY(float velY);
  void setPos(sf::Vector2f novaPos);
  void setNoChao(bool noChao);
  void setHitbox(sf::FloatRect &hitbox);

  sf::Vector2f getVel() const;
  sf::Vector2f getPos() const;
  bool getNoChao() const;
  sf::Vector2f getSize() const;
  sf::FloatRect getHitbox() const;

  void cair();
};

} // namespace Entidades
