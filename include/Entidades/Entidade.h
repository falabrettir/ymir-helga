#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include "Ente.h"

namespace Gerenciadores {
class GerenciadorColisoes;
}
namespace Entidades {

class Entidade : public Ente {
 private:
  sf::Vector2f pos;
  sf::Vector2f gravidade;
  bool noChao;
  bool olhandoEsquerda;
  std::ostream *buffer;

 protected:
  sf::Vector2f tamanho;
  sf::Vector2f velocidade;
  sf::FloatRect hitbox;
  static Gerenciadores::GerenciadorColisoes *pGC;

 public:
  Entidade(ID id);
  virtual ~Entidade();

  void atualizaOrientacao();
  void setOlhandoEsquerda(bool olhandoEsquerda);
  bool getOlhandoEsquerda();

  void mover();
  void setPos(sf::Vector2f novaPos);
  void setVel(sf::Vector2f novaVel);
  void setVelX(float velX);
  void setVelY(float velY);

  void setNoChao(bool noChao);
  void setHitbox(sf::FloatRect &hitbox);
  virtual void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0}) = 0;

  sf::Vector2f getVel() const;
  sf::Vector2f getPos() const;
  bool getNoChao() const;
  sf::Vector2f getTamanho() const;
  sf::FloatRect getHitbox() const;

  void desenhar();

  void cair();

  virtual void executar() = 0;
};

}  // namespace Entidades
