#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "IDs.h"

class Ente {
 protected:
  const ID id;
  static Gerenciadores::GerenciadorGrafico *pGG;
  sf::RenderTarget *pAlvo;
  sf::Texture *pTexture;
  sf::Sprite *pSprite;

 public:
  Ente(ID id);
  virtual ~Ente();

  const ID getId() const;
  bool setTextura(const std::string &path);
  void atualizaSprite(sf::Texture *pTexture);
  sf::Sprite getSprite();
  void setTarget();
  void desenhar();
  virtual void executar() = 0;
};
