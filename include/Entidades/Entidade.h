#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include "Ente.h"

namespace Gerenciadores {
class Gerenciador_Colisoes;
}
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
  sf::FloatRect hitbox;
  static Gerenciadores::Gerenciador_Colisoes *pGC;

 public:
  Entidade(ID id);
  virtual ~Entidade();

  void setVel(sf::Vector2f novaVel);
  void setVelX(float velX);
  void setVelY(float velY);
  void setPos(sf::Vector2f novaPos);
  void setNoChao(bool noChao);
  void setHitbox(sf::FloatRect &hitbox);
  virtual void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0}) = 0;

  sf::Vector2f getVel() const;
  sf::Vector2f getPos() const;
  bool getNoChao() const;
  sf::Vector2f getSize() const;
  sf::FloatRect getHitbox() const;
  const bool ehPlataforma() const;

  void cair();

  virtual void executar() = 0;
};

}  // namespace Entidades
