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

 protected:
  sf::Vector2f tamanho;
  sf::Vector2f velocidade;
  static Gerenciadores::GerenciadorColisoes* pGC;

 public:
  Entidade(ID id);
  virtual ~Entidade();

  void atualizaOrientacao();
  void mover();
  void cair();
  void desenhar();

  virtual void colidir(Entidade* pEnt = nullptr) = 0;
  virtual void executar() = 0;

  // ============================================================================
  // Getters e setters
  // ============================================================================

  void setVel(const sf::Vector2f& novaVel);
  void setVelX(const float& velX);
  void setVelY(const float& velY);

  void setPos(const sf::Vector2f& novaPos);
  void setPosX(const float& x);
  void setPosY(const float& y);

  void setTamanho(const sf::Vector2f& tam);

  void setOlhandoEsquerda(const bool& olhandoEsquerda);
  void setNoChao(const bool& noChao);

  sf::Vector2f getVel() const;
  sf::Vector2f getPos() const;
  bool getNoChao() const;
  sf::Vector2f getTamanho() const;
  bool getOlhandoEsquerda() const;
};

}  // namespace Entidades
