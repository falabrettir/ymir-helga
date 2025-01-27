#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "IDs.h"

class Ente {
 protected:
  const ID id;
  static Gerenciadores::Gerenciador_Grafico *pGG;
  sf::RenderTarget *pAlvo;
  sf::Texture *pTexture;
  sf::Sprite *pSprite;

 public:
  Ente(ID id);
  virtual ~Ente();

  static void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *ppGG);
  const ID getId() const;
  bool setTextura(const std::string &path);
  void atualizaSprite(sf::Texture *pTexture);
  sf::Sprite getSprite();
  void setTarget();
  void desenhar();
  virtual void executar() = 0;
};
