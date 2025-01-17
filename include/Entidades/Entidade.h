#pragma once

#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

class Entidade : public Ente {
private:
  sf::Vector2f pos;
  sf::Vector2f gravidade;
  sf::Vector2f tamanho;
  bool noChao;
  std::ostream *buffer;

protected:
  sf::Vector2f velocidade;

public:
  Entidade();
  virtual ~Entidade();

  void setVel(sf::Vector2f novaVel);
  void setVelX(float velX);
  void setVelY(float velY);
  void setPos(sf::Vector2f novaPos);
  void setNoChao(bool noChao);

  sf::Vector2f getVel() const;
  sf::Vector2f getPos() const;
  bool getNoChao() const;
  sf::Vector2f getSize() const;

  void cair();
};

} // namespace Entidades
